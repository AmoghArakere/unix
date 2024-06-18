// Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  int fd = open(argv[1], O_RDWR);
  if (fd == -1)
  {
    perror("open");
    return 1;
  }
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_END;
  lock.l_start = 0;
  lock.l_len = 100;
  if (fcntl(fd, F_GETLK, &lock) == -1)
  {
    perror("fcntl");
    close(fd);
    return 1;
  }
  if (lock.l_type == F_UNLCK)
  {
    printf("Region is not locked, locking the region...\n");
    lock.l_type = F_WRLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
      perror("fcntl");
      close(fd);
      return 1;
    }
    printf("Region locked.\n");
    lseek(fd, -50, SEEK_END);
    char buffer[51];
    if (read(fd, buffer, 50) != 50)
    {
      perror("read");
      close(fd);
      return 1;
    }
    buffer[50] = '\0';
    printf("Read last 50 bytes: %s\n", buffer);
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
      perror("fcntl");
    }
  }
  else
  {
    printf("Region is locked by PID: %d\n", lock.l_pid);
  }
  close(fd);
  return 0;
}
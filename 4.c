// C program that takes the file descriptor as an argument and prints the description of selected file flags for that descriptor.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void print_flags(int flags)
{
  if (flags & O_APPEND)
  {
    printf("O_APPEND\n");
  }
  if (flags & O_NONBLOCK)
  {
    printf("O_NONBLOCK\n");
  }
  if (flags & O_SYNC)
  {
    printf("O_SYNC\n");
  }
  if (flags & O_DSYNC)
  {
    printf("O_DSYNC\n");
  }
  if (flags & O_RSYNC)
  {
    printf("O_RSYNC\n");
  }
  if ((flags & O_ACCMODE) == O_RDONLY)
  {
    printf("O_RDONLY\n");
  }
  if ((flags & O_ACCMODE) == O_WRONLY)
  {
    printf("O_WRONLY\n");
  }
  if ((flags & O_ACCMODE) == O_RDWR)
  {
    printf("O_RDWR\n");
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *filename = argv[1];
  int fd = open(filename, O_CREAT | O_RDWR | O_APPEND | O_NONBLOCK | O_SYNC, S_IRWXU | S_IRWXG | S_IRWXO);
  if (fd == -1)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }

  int flags = fcntl(fd, F_GETFL);
  if (flags == -1)
  {
    perror("fcntl");
    close(fd);
    exit(EXIT_FAILURE);
  }

  printf("File descriptor %d has the following flags set:\n", fd);
  print_flags(flags);

  close(fd);
  return 0;
}

// C program to create a child process and show how parent and child  processes will share the text file and justify that both parent and child shares the same file offset.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
  int fd = open("test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  if (fd == -1)
  {
    perror("open");
    return 1;
  }

  pid_t pid = fork();
  if (pid == -1)
  {
    perror("fork");
    close(fd);
    return 1;
  }
  else if (pid == 0)
  {
    // Child process
    char buffer[10];
    lseek(fd, 5, SEEK_SET);
    read(fd, buffer, 5);
    buffer[5] = '\0';
    printf("Child read: %s\n", buffer);
  }
  else
  {
    // Parent process
    wait(NULL);
    char buffer[10];
    read(fd, buffer, 5);
    buffer[5] = '\0';
    printf("Parent read: %s\n", buffer);
  }

  close(fd);
  return 0;
}

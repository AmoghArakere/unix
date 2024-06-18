// Write a C program to simulate system function.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int my_system(const char *command)
{
  if (command == NULL)
  {
    return -1;
  }

  pid_t pid = fork();
  if (pid < 0)
  {
    // Fork failed
    return -1;
  }
  else if (pid == 0)
  {
    // Child process
    execl("/bin/sh", "sh", "-c", command, (char *)NULL);
    // If exec returns, there was an error
    perror("execl");
    exit(EXIT_FAILURE);
    else
    {
      // Parent process
      int status;
      if (waitpid(pid, &status, 0) == -1)
      {

        return -1;
      }
      if (WIFEXITED(status))
      {
        return WEXITSTATUS(status);
      }
      else
      {
        return -1;
      }
    }
  }
}

int main()
{
  // Example usage of my system function
  printf("Running 'ls -l':\n");
  int result = my_system("ls -l") if (result = -1)
  {
    perror("my_system") :
  }
  else
  {
        printf('"ls -l' exited with status %d\n", result):
  }

  return 0;
}

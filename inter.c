// C program to
// i.To create a child process.
// ii.Child should execute an interpreter file by passing few arguments and some environment variables.
// iii.Parent should execute an interpreter file by passing few arguments
// iv.Create an interpreter file that has the path of echoall.c file
// Create echoall.c file which prints the arguments and environment variables received through parent and child process

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();
  if (pid < 0)
    printf("Error\n");
  else if (pid == 0)
  { // Child process
    if (execl("./textinterpreter", "textinterpreter", "myarg1", "myarg2", (char *)0) < 0)
      printf("error\n");
  }
  else
  { // Parent process
    if (waitpid(pid, NULL, 0) < 0)
      printf("wait error\n");
  }
  return 0;
}

/*
Gcc -o echoall echoall.c
Chmod 777 text interpreter
Gcc -o inter inter.c
./inter
*/

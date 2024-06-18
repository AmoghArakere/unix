// C program to remove empty files from the given directory.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
int main()
{
  struct dirent *dir;
  int fd, n;
  DIR *dp; //=(argc>1) ? argv[1] : "." ;
  dp = opendir(".");
  if (dp)
  {
    while ((dir = readdir(dp)) != NULL)
    {
      fd = open(dir->d_name, O_RDWR, 0777);
      n = lseek(fd, 0, SEEK_END);
      if (!n)
      {
        unlink(dir->d_name);
      }
    }
  }
}

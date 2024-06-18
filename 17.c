// C program such that it initializes itself as a Daemon Process.

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>

void create_daemon()
{
  pid_t pid = fork();
  if (pid < 0)
  {
    exit(EXIT_FAILURE);
  }
  if (pid > 0)
  {
    exit(EXIT_SUCCESS);
  }
  if (setsid() < 0)
  {
    exit(EXIT_FAILURE);
  }
  umask(0);
  if (chdir("/") < 0)
  {
    exit(EXIT_FAILURE);
  }
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  open("/dev/null", O_RDWR);
  dup(0);
  dup(0);
}

int main()
{
  create_daemon();
  openlog("daemon_example", LOG_PID, LOG_DAEMON);
  while (1)
  {
    syslog(LOG_NOTICE, "Daemon is running...");
    sleep(30);
  }
  closelog();
  return EXIT_SUCCESS;
}
/**
 * A mini Daemon sample code from APUE 2ed.
 * 
 * What a Daemon should do and avoid:
 * 1. 
 */

#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void daemonize( const char* cmd ) {
  
  // Clear file creation mask
  umask(0);

  // Get maximum number of file description
  if( getrlimit(RLIMIT_NOFILE, &r1) < 0 )
    err_quit("%s: can't get file limit", cmd);

  // Become a session leader to lose controlling TTY.
  if( (pid = fork()) < 0 )
    err_quit("%s: can't fork", cmd);
  else if (pid != 0 ) // parent
    exit(0);


  // TODO: what is setsid() used for?
  setsid(); 

  // Ensure future opens won't allocate controlling TTYs.
  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  if(sigaction(SIGHUP, &sa, NULL) < 0 )
    err_quit("%s: can't ignore SIGHUP");

  if( (pid = fork()) < 0 )
    err_quit("%s: can't fork", cmd);
  else if( pid != 0 ) //parent
    exit(0);

  // Change the current working directory to the root so we 
  // won't prevent file systems from being unmounted.

  if( chdir("/") < 0 )
    err_quit("%s: can't change directory to /");

  // Close all open file descriptors.
  if( rl.rlim_max == RLIM_INFINITY )
    rl.rlim_max = 1024;

  for( i=0; i < rl.rlim_max; i++) 
    close(i);

  // Attach file descriptors 0,1 and 2 to /dev/null
  fd0 = open("/dev/null", O_RDWR);
  fd1 = dup(0);
  fd2 = dup(0);

  // Initialize the log file
  openlog(cmd, LOG_CONS, LOG_DAEMON);
  if( fd0 != 0 || fd1 != 1 || fd2 != 2 ) {
    syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, 
           fd1, fd2);
    exit(1);
  }
}

int main( int argc, char* argv[]) {
  char* cmd;
  if(( cmd = strrchr(arg[0], '/')) == NULL )
    cmd = argv[0];
  else 
    cmd++;

  daemonize(cmd);

  return 0;

}

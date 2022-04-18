#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int t,n,x;

  if(argc < 2)
	n = 1;
  else
	n = atoi(argv[1]);
  if (n < 0 ||n > 20)
	n = 2;
  x = 0;
  for ( int i = 0; i < n; i++ ) {
    t = fork ();
    if ( t < 0 ) {
      printf(1, "Fork Failed!\n");
    } else if ( t > 0) {
        printf(1, "Parent with PID %d creating child whose PID is %d\n",getpid(),t);
        wait();
      }
      else{
	printf(1,"Child with PID %d is created.\n",getpid());
	for(int i = 0; i < 4000000000; i++)
	    x = x + 3.14*89.64; // this loop will be used to comsume cpu time so that ps command can be used in that time and record the processes details.
	break;
      }
  }
  exit();
}

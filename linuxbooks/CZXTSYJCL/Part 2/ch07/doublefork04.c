#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int status;
	// `pid_t` defined in `include\sys\types.h`
	pid_t currentparentpid, currentpid, pid1, pid2;
	// get parent pid
	currentparentpid = getpid();
	// create child process 1.
	pid1 = fork();
	// create child process 2.
	pid2 = fork();
	// get process pid.
	currentpid = getpid();

	printf("currentparentpid = %9d  pid1 = %9d  pid2 = %9d  currentpid = %9d \n", currentparentpid, pid1, pid2, currentpid);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int status;
	// `pid_t` defined in `include\sys\types.h`
	pid_t currentpid;
	// get parent process pid.
	currentpid = getpid();

	printf("%d\n", currentpid);
}

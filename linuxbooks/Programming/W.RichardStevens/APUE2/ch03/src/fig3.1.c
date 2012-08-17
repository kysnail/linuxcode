#include "../../appendix/b/apue.h"

int
main(void)
{
	/*
 	  Because negative offset are possible, we should be careful
	  to compare the return value from lseek as being equal or
	  or not equal to -1 and not test if it's less than 0.
 	*/
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	exit(0);
}

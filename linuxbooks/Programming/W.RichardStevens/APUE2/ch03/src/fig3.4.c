#include "../../appendix/b/apue.h"

#define BUFFSIZE 4096

int
main(void)
{
	int n;
	char buf[BUFFSIZE];

	// this is a template of read/write file in Linux.
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	// for read function, if the end of file is encountered, 0 is returned.
	if (n < 0)
		err_sys("read error");

	exit(0);
}

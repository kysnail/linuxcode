#include "../../appendix/b/apue.h"
#include <fcntl.h>

void
set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
	int val;
	
	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error.");

	/* turn on flags */
	val |= flags;

	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error.");
}

void
clr_fl(int fd, int flags) /* flags are file status flags to turn off */
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error.");

	/* turn off flags */
	var &= ~flags;

	if (fcntl(fd, FSETFL, val) < 0)
		err_sys("fcntl F_SETFL error.");
}

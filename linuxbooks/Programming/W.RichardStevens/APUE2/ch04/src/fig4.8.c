/*
 * =====================================================================================
 *
 *       Filename:  fig4.8.c
 *
 *    Description:  Example of access Function
 *
 *        Version:  1.0
 *        Created:  08/22/2012 09:25:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../../appendix/b/apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	if (access(argv[1], R_OK))
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");

	exit(0);
}


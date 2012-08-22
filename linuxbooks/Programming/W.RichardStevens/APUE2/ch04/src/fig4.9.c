/*
 * =====================================================================================
 *
 *       Filename:  fig4.9.c
 *
 *    Description:  Example of umask function
 *
 *        Version:  1.0
 *        Created:  08/22/2012 07:20:24 PM
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

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int
main(void)
{
	//umask(0);
	if (creat("foo", RWRWRW) < 0)
		err_sys("create error for foo");
}


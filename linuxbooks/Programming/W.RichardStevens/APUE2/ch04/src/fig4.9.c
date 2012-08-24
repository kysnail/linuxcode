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
	umask(0);
	/* 
 	formula
	-------
	mode & ~cmask
	
	mode   = 110 110 110
	cmask  = 000 000 000
	~cmask = 111 111 111

	mode & ~cmask = 110 110 110 => rw-rw-rw-
	*/
	if (creat("foo", RWRWRW) < 0)
		err_sys("create error for foo");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	/* 
	mode   = 110 110 110
	cmask  = 000 110 110
	~cmask = 111 001 001

	mode & ~cmask = 110 000 000 => rw-------
	*/
	if (creat("bar", RWRWRW) < 0)
		err_sys("create error for bar");
	
	exit(0);
}


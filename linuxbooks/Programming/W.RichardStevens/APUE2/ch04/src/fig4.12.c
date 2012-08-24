/*
 * =====================================================================================
 *
 *       Filename:  4.12.c
 *
 *    Description:  Example of chmod function.
 *
 *        Version:  1.0
 *        Created:  08/24/2012 07:46:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../../appendix/b/apue.h"

int
main(void)
{
	struct stat statbuf;

	/* turn on set-group-ID and turn off group-execute */
	if (stat("foo", &statbuf) < 0)
		err_sys("stat error for foo");

	/*
	formula
	-------
 	mode & ~cmask

	foo
	---
	mode     = 110 110 110
	S_IXGRP  = 000 001 000 	
	~S_IXGRP = 111 110 111

	mode & ~S_IXGRP = 110 110 110 
	mode & ~S_IXGRP | S_ISGID = 110 11S 110 
 	*/
	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		err_sys("chmod error for foo");


	/*
	formula
	-------
 	mode & ~cmask

	foo
	---
	mode     = 110 000 000
	S_IRUSR  = 100 000 000
	S_IWUSR  = 010 000 000
	S_IRGRP  = 000 100 000
	S_IROTH  = 000 000 100

	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH = 110 100 100
	
 	This method can set absolute mode to a file.
 	*/
	/* set absolute mode to "rw-r--r--" */
	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		err_sys("chmod error for bar");

	exit(0);
}


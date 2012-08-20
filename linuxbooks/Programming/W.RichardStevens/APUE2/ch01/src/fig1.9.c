/*
 * =====================================================================================
 *
 *       Filename:  fig1.9.c
 *
 *    Description:  Print user ID and group ID
 *
 *        Version:  1.0
 *        Created:  08/20/2012 08:09:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../../appendix/b/apue.h"

int
main(void)
{
	printf("uid = %d, gid = %d", getuid(), getgid());
	exit(0);
}


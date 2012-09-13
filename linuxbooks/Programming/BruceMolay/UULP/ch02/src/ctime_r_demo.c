/*
 * =====================================================================================
 *
 *       Filename:  ctime_r_demo.c
 *
 *    Description:  ctime_r() - Convert Time to Character String (Restartable)
 *    		    This function is the restartable version of the ctime() function.
 *
 *        Version:  1.0
 *        Created:  09/13/2012 07:06:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t ltime;
	char buf[50];

	time(&ltime);
	printf("the time is %s", ctime_r(&ltime, buf));
}

/* 
execute result:
---------------
$ ./ctime_r_demo
the time is Thu Sep 13 19:10:04 2012
*/

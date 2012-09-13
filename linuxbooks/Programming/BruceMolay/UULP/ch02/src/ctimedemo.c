/*
 * =====================================================================================
 *
 *       Filename:  ctimedemo.c
 *
 *    Description:  Example that uses ctime() function.
 *		    The example polls the system clock using ctime().
 *		    It then print a message giving the current date and time.
 *        Version:  1.0
 *        Created:  09/13/2012 05:33:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t ltime;
	time(&ltime);
	printf("the time is %s", ctime(&ltime));
}

/*
Output:
-------
$./ctimedemo
the time is Thu Sep 13 17:36:54 2012
*/

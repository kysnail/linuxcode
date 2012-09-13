/*
 * =====================================================================================
 *
 *       Filename:  color.c
 *
 *    Description:  Using printf function to print out colorful characters.
 *
 *        Version:  1.0
 *        Created:  09/13/2012 04:28:58 PM
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

//#define GREEN \033[32m
//#define NORMAL \033[0m

int main()
{
	printf("Green -> \\033[32m & Normal -> \\033[0m \n");
	printf("--------------- confusion way ------------------------\n");
	printf("%s%20s\n%s%20s\n", "\033[32m", "Green", "\033[0m", "Green");

	char *GREEN = "\033[32m";
	char *NORMAL = "\033[0m";

	printf("--------------- better way ------------------------\n");
	printf("%s%20s\n%s%20s\n", GREEN, "Green", NORMAL, "Normal");
}

/*
execute result:
---------------
Green -> \033[32m & Normal -> \033[0m 
--------------- confusion way ------------------------
[32m               Green		<-- display green
[0m               Green		<-- display normal
--------------- better way ------------------------
[32m               Green		<-- display green
[0m              Normal		<-- display normal

"[32m" and "[0m" are automatically generate by program which can not be seen under shell environment.
*/

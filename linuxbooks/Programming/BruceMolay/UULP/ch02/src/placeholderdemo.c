/*
 * =====================================================================================
 *
 *       Filename:  placeholderdemo.c
 *
 *    Description:  printf function's format placeholders demo.
 *
 *        Version:  1.0
 *        Created:  09/13/2012 07:46:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("demo format string -> %%12.12s\n");
	printf("01234567890123456789\n");
	printf("%12.12s\n", "abcdefghijklmnopqrstuvwxyz");
	printf("The string is abcdefghijklmnopqrstuvwxyz");
}

/*
execute result:
---------------
demo format string -> %12.12s
01234567890123456789
abcdefghijkl        <-- print out 12 characters.
The string is abcdefghijklmnopqrstuvwxyz
*/

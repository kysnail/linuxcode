/*
 * =====================================================================================
 *
 *       Filename:  demo.c
 *
 *    Description:  gprof demo.
 *                  Notice that the gmon.out file was not referenced in the command line,
 *                  just the name of the executable program.
 *                  # gcc -o demo demo.c -pg to generate the gmon.out
 *        Version:  1.0
 *        Created:  11/27/2012 10:21:17 AM
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

void function1()
{
        int i, j;
        for(i = 0; i < 100000; i++)
                j += i;
}

void function2()
{
        int i, j;
        function1();
        for(i = 0; i < 200000; i++)
                j = i;
}

int main()
{
        int i, j;
        for (i = 0; i < 100; i++)
                function1();

        for (i = 0; i < 50000; i++)
                function2();

        return 0;
}


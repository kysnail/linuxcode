/*
 * =====================================================================================
 *
 *       Filename:  more02.c - version 0.2 of more
 *
 *    Description:  read and print 24 lines then pause for a few special commands
 *		    feature of version 0.2: reads from /dev/tty from commands
 *        Version:  1.0
 *        Created:  08/29/2012 09:15:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more(FILE *);

int main(int ac, char *av[])
{
	FILE *fp;

	if (ac == 1)
		do_more(stdin);
	else
		printf ("%d", ac);
		while (--ac)
			if ((fp = fopen(*++av, "r")) != NULL)
			{
				do_more(fp);
				fclose(fp);
			}
			else
				exit(1);

		printf ("%d", ac);
	return 0;
}

/* 
 * read PAGELEN lines, then call see_more() for further instructions
 */
void do_more(FILE *fp)
{
	char line[LINELEN];
	int  num_of_lines = 0;
	int  see_more(FILE *), reply;
	// The file /dev/tty is a character file with major number 5 and minor number 0,
	// usually of mode 0666 and owner.group root.tty. It is a synonym for the controlling 
	// terminal of a process, if any.
	// ==$ file /dev/tty
	// crw-rw-rw- 1 root tty 5, 0 Aug 29 12:56 /dev/tty
	// Terminal Special Files such as /dev/tty
	FILE *fp_tty;		

	fp_tty = fopen("/dev/tty", "r");		/* NEW: cmd stream */
	// 测试的时候，将 /dev/tty 写成了 /de/tty 结果造成了 fp_tty = 0 的情况。
	if (fp_tty == NULL)				/* if open fails */
		exit(1);				/* no use in running */

	while (fgets(line, LINELEN, fp)) {		/* more input */
		if (num_of_lines == PAGELEN) {		/* full screen? */
			reply = see_more(fp_tty);	/* NEW: pass FILE * */
			if (reply == 0)			/* done */
				break;
			num_of_lines -= reply;	/* reset count */
		}
		
		if (fputs(line, stdout) == EOF)		/* show line */
			exit(1);			/* or die */
		num_of_lines++;				/* count it */
	}
}

/* 
 * print message, wait for response, return # of lines to advance
 * q means no, space means yes, CR means one line.
 */
int see_more(FILE *cmd)					/* NEW: accepts arg */
{
	int c;
	printf("\033[7m more? \033[m");			/* reverse on a vt100 */
	// printf("\033[7m more? \033[m");		/* \033 equivalent to \e */
	
	// 这里使用了 getc ，与 more01.c（使用了 getchar） 不同。
	// The function getchar is defined to be equivalent to getc(stdin).
	while ((c = getc(cmd)) != EOF)			/* NEW: read from tty */
	{
		if (c == 'q')				/* q -> N */
			return 0;
		if (c == ' ')				/* ' ' => next page */
			return PAGELEN;			/* how many to show */
		// 这里的 \n 也表示了，在 Linux 下换行符是 \n 。
		if (c == '\n')				/* Enter key => 1 line */
			return 1;

		// 这里的目的是为了测试 \n 代表的即使换行符/回车键。如果不使用 \n 那么
		// more01.c 版本的程序在重定向后就不会执行了。
		if (c == '\t')
			return 1;
	}

	return 0;
}

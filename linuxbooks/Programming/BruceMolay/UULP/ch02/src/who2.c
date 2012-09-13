/*
 * =====================================================================================
 *
 *       Filename:  who2.c
 *
 *    Description:  read /var/run/utmp and list info thereinh
 *    		      - supresses empty records
 *    		      - formats time nicely
 *
 *        Version:  2.0
 *        Created:  09/01/2012 08:09:00 PM
 *       Revision:  09/13/2012 by kysnail
 *       Compiler:  gcc
 *
 *         Author:  kysnail
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>

/* #define SHOWHOST */
void showtime(long);
void show_info(struct utmp *);

int main()
{
	struct utmp utbuf;					/* read info into here */
	int         utmpfd;					/* read from this descriptor */
	int         reclen = sizeof(utbuf);

	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);
		exit(1);
	}

	while (read(utmpfd, &utbuf, sizeof(utbuf)) == reclen)
		show_info(&utbuf);
	close(utmpfd);
	return 0;
}

/*
 * show_info()
 *		displays the contents of the utmp struct
 *		in human readable form
 *		displays nothing if recored has no user name
 */
void show_info(struct utmp *utbufp)
{
	if(utbufp->ut_type != USER_PROCESS)	
		return;
	
	printf("%-8.8s", utbufp->ut_name);		/* the logname  */	
	printf(" ");					/* a space */
	printf("%-8.8s", utbufp->ut_line);		/* the tty */
	printf(" ");					/* a space */
	showtime(utbufp->ut_time);			/* display time */
#ifdef SHOWHOST
	if(utbufp->ut_host[0] != '\0')
		printf("(%s)", utbufp->ut_host);	/* the host */
#endif
	printf("\n");
}

/*
 * displays time in a format fit for human consumption
 * uses ctime to build a string then picks parts out of it
 * Nots: %12.12s prints a string 12 chars wide and LIMITS
 * it to 12chars.
 */
void showtime(long timeval)
{
	char *cp;					/* to hold address of time */
	cp = ctime(&timeval);				/* convert time into string */
							/* string looks like */
							/* Mon Feb 4 00:46:40 EST 1991 */
							/* 0123456789012345. */
	printf("%12.12s", cp + 4);			/* pick 12 chars from pos 4 */
}

/*
execute result
--------------
$ ./who2
sunxuebi tty1     Sep  5 16:18
sunxuebi pts/0    Sep  5 16:18
lipeng   pts/2    Sep 11 19:04
kangyush pts/3    Sep  5 16:19
kangyush pts/4    Sep  5 16:20
liurui   pts/5    Sep  6 09:35
sunxuebi pts/1    Sep  6 14:50
kangyush pts/7    Sep 13 16:56
kangyush pts/8    Sep  7 09:44
kangyush pts/10   Sep 13 15:41
kangyush pts/6    Sep 11 14:25
sunxuebi pts/9    Sep 13 14:55
*/

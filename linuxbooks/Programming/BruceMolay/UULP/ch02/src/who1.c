/*
 * =====================================================================================
 *
 *       Filename:  who1.c
 *
 *    Description:  a first version of who program
 *		    open, read UTMP file, and show results.
 *        Version:  1.0
 *        Created:  09/01/2012 06:40:36 PM
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
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST					/* include remote machine on output */

int main()
{
	struct utmp current_record;			/* read info into here */
	int         utmpfd;				/* read from this descriptor */
	int         reclen = sizeof(current_record);

	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
		perror(UTMP_FILE);			/* UTMP_FILE is in utmp.h */
		exit(1);
	}

	while (read(utmpfd, &current_record, reclen) == reclen)
		show_info(&current_record);

	close(utmpfd);
	return 0;					/* went ok */
}

/* 
 * show_info()
 * displays contents of the utmp struct in human readable form
 * * note * these sizes should not be hardwired
 */

show_info(struct utmp *utbufp)
{
	printf("%-8.8s", utbufp->ut_name);		/* the logname  */	
	printf(" ");					/* a space */
	printf("%-8.8s", utbufp->ut_line);		/* the tty */
	printf(" ");					/* a space */
	printf("%10ld", utbufp->ut_time);		/* logtime */	
	printf(" ");					/* a space */

#ifdef SHOWHOST
	printf("(%s)", utbufp->ut_host);		/* the host */
#endif
	printf("\n");					/* new line */
}

/*
execute result:
---------------
$ ./who1
reboot   ~        1346041151 (3.4.7-1.fc16.x86_64)
runlevel ~        1346041169 (3.4.7-1.fc16.x86_64)
sunxuebi tty1     1346041185 (:0)
sunxuebi pts/0    1346320491 ()
sunxuebi pts/1    1346379541 (:0.0)
kangyush pts/2    1346497537 (kangyushi-pc.xause.com)
         pts/3    1346304391 ()
         pts/4    1346069090 ()
         pts/5    1346068862 ()
         pts/6    1346069174 ()
         pts/7    1346080626 ()
kangyush pts/4    1346116324 (:12.0)
         pts/1    1346305086 ()
kangyush pts/7    1346119624 (:12.0)
         pts/8    1346217940 ()
kangyush pts/8    1346223667 (:12.0)
kangyush pts/9    1346143668 ()
lipeng   pts/3    1346304395 (:11.0)
         pts/9    1346306427 ()
         pts/10   1346322577 ()
         pts/11   1346246264 ()
         pts/12   1346390743 ()
lipeng   pts/11   1346304354 (:11.0)
liurui   pts/13   1346379896 (:14.0)
liurui   pts/14   1346305938 ()
         pts/14   1346394415 ()
kangyush pts/0    1346488648 (kangyushi-pc.xause.com)
liurui   pts/10   1346375337 (:14.0)
sunxuebi pts/12   1346400318 (:0.0)
*/

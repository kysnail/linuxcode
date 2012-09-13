# ctime_r() - Convert Time to Character String (Restartable)

## Format

	#include <time.h>
	char *ctime_r(const time_t *time, char *buf);

## Language Level

	XPG4

## Threadsafe

	Yes

## Description
This function is the **restartable** version of the `ctime()` function.

The `ctime_r()` function converts the time value pointed to by *time* to local time in the form of a character string. A time value is usually obtained by a call to the `time()` function. 

The string result that is produced by the `ctime_r()` function contains exactly `26` characters and has the format:

	"%.3s %.3s%3d %.2d:%.2d:%.2d %d\n"

For example:

	Mon Jul 16 02:03:55 1987\n\0

The `ctime_r()` function uses a 24-hour clock format. The day are abbreviated to:

	Sun, Mon, Tue, Wed, Thu, Fri, and Sat.

The months are abbreviated to:

	Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, and Dec.

All fields hava a constant width. Dates with only one digit are preceded with a zero. The new-line character (`\n`) and the null character (`\0`) occupy the last two positions of the string.

## Return Value
The `ctime_r()` function returns a pointer to the character string result. If the function is unsuccessful, it returns NULL. A call to `ctime_r()` is equivalent to:

	asctime_r(localtime_r(&anytime, buf2), buf)

where buf is a pointer to char.

## Explore that uses ctime_r()
This example polls the system clock using `ctime_r()`. It then print a message giving the current date and time.

	#include <time.h>
	#include <stdio.h>
	
	int main(void)
	{
		time_t ltime;
		char buf[50];

		time(&ltime);
		printf("the time is %s", ctime_r(&ltime, buf));
	}

**Ref**
 * [ctime_r](http://publib.boulder.ibm.com/infocenter/iadthelp/v6r0/index.jsp?topic=/com.ibm.etools.iseries.langref.doc/rzan5mst93.htm)

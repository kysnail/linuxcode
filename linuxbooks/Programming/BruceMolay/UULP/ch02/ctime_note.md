# ctime - Convert Time to Character String

	Format:
	-------
	#include <time.h>
	char *ctime(const time_t *time);

	Language Level: ANSI

	Threadsafe: No. Use ctime_r() instead.

## Description
The `ctime()` function converts the time value pointed to by *time* to local time in the form of a character string. A time value is usually obtained by a call to the `time()` function.

The strint result that is produced by `ctime()` contains exactly `26` characters and has the format:

	"%.3s %.3s%3d %.2d:%.2d:%.2d %d\n"

For example:

	Mon Jul 16 02:03:55 1987\n\0

The `ctime()` function uses a 24-hour clock format. The days are abbreviated to: Sun, Mon, Tue, Thu, Fri, and Sat. The months are abbreviated to:

	Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, and Dec.

All fields have a constant width. Dates with only one digit are preceded with a zero. The new-line character `(\n)` and the null character `(\0)` occupy the last two position of the string.

## Return Value
The `ctime()` function returns a pointer to the character string result. If the function is successful, it returns NULL. A call to the `ctime()` function is equivalent to:

	asctime(localtime(&anytime))

## Note:
The `asctime()` and `ctime()` functions, and other time functions may use a common, statically allocated buffer to hold the return string. Each call to one of these functions may destroy the result of previous call. The `asctime_r()`, `ctime_r()`, `gmtime_r()`, and `localtime_r()` functions do not use a common, statically-allocated buffer to hold the return string. These functions can be used in the replace of `asctime()`, `ctime()`, `gmtime()`, and `localtime()` if reentrancy is desired.

	Notes in Note:
	--------------
	1. 这里以 xxx_r() 结尾的函数，都是线程安全的。
	2. degree of reentrancy - 重入次数
	--------------
	但这里对于 reentrancy 的解释不够权威，看一段更具权威的：
	--------------------------------------------------------
	Reentrancy (computing) - 中文译为 - 可重入
	In computing, a computer program or subroutine is called reentrant if it can be interrupted in the middle of its 
	execution and then safely called again ("re-entered") before its previous invocations complete execution.
	----------------------------------------------------------------------------------------------------------------
	关于 可重入 的具体内容，参看;

		-> reentrancynote.md

## Example that uses ctime()
The example polls the system clock using `ctime()`. It then prints a message giving the current date and time.

	#include <time.h>
	#include <stdio.h>

	int main(void)
	{
		time_t ltime;
		time(&ltime);	
		printf("the time is %s", ctime(&ltime));
	}

	output:
	-------
	the time is Thu Sep 13 17:37:33 2012

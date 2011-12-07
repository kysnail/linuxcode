/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-03
 * Description:
 * 	这里程序保证如下的执行流程：
 *
 * 	
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int p1, p2, p3, p4, p5, p6, p7;
	int end_p1 = 0, end_p2 = 0, end_p3 = 0, end_p4 = 0, end_p5 = 0, end_p6 = 0, end_p7 = 0; 	
	int pid, status;

	// Create Process 1
	if ((p1 = fork()) == 0) 
	{
		execl("/bin/echo", "My Echo", "I am P1", 0);
	}

	wait(&status);
	if ((p2 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P2", 0);
	}

	if ((p3 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P3", 0);
	}

	// 这里只能保证 p2/p3 必定限于 p4/p5 完成，但并不能保证 p2/p3 之间的先后顺序。
	do {
		pid = wait(&status);
		if (pid == p2) end_p2 = 1;	// 置子进程 p2 终止
		if (pid == p3) end_p3 = 1;	// 置子进程 p3 终止
	} while (end_p2 == 0 || end_p3 == 0);	// 只要有一个子进程没有终止，则继续循环执行。
	// 但实际上，根据流程图，p2/p3 之间并没有这么严格的先后要求。

	if ((p4 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P4", 0);
	}

	if ((p5 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P5", 0);
	}

	// 这里保证 p4/p5 的完成，但并不能保证 p4/p5 之间的先后顺序。
	do {
		pid = wait(&status);
		if (pid == p4) end_p4 = 1;
		if (pid == p5) end_p5 = 1;
	} while (end_p4 == 0 || end_p5 == 0);

	printf("---------\n");
}

/**
 * Result:
 *  $ ./a.out 
 *  I am P1
 *  I am P2
 *  I am P3
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P4
 *  I am P5
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P2
 *  I am P3
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P2
 *  I am P3
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P5
 *  I am P4
 *  ---------
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P5
 *  I am P4
 *  ---------
 *  通过大量的运行可以验证 p2/p3 一定会在 p4/p5 之前执行完毕。
 */

/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-03
 * Description:
 * 	这里与 controlprocess03.c 的区别在于使用一个循环，在一个固定的点上，等待所有的子进程完成运行，并返回。
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

	// 这就是与 controlprocess03.c 的本质区别，这里使用了循环，等待 p2/p3 的完成，当然需要
	// 注意的是，这里只要 p2/p3 中的任意一个返回即可，与下面的那个稍有不同。
	do 
	{
		pid = wait(&status);
		if (pid == p2) end_p2 = 1;
		if (pid == p3) end_p3 = 1;
	} while(end_p3 == 0);		// 与下面的 do...while 循环所不同之处。

	if ((p4 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P4", 0);
	}

	if ((p5 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P5", 0);
	}

	// 作用与上面的 do...while 类似，不同的地方在于，次循环可以保证 p4&p5 都完成后，再运行下一条指令。
	do
	{
		pid = wait(&status);
		if (pid == p4) end_p4 = 1;
		if (pid == p5) end_p5 = 1;
	} while(end_p4 == 0 || end_p5 == 0);

	printf("---------\n");
}

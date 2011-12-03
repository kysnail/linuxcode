/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-03
 * Description:
 * 	这里创建五个子进程，但选择在不同的地方使用 wait 函数，等待子进程的返回。以此理解 wait 的作用。
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

	// 这里的 wait 只是用来等待 p1 的结束。
	wait(&status);
	if ((p2 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P2", 0);
	}

	if ((p3 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P3", 0);
	}

	// 而这里的 wait 则只要 p2/p3 中有一个返回，即结束。
	pid = wait(&status);
	if (pid == p2) end_p2 = 1;
	if (pid == p3) end_p3 = 1;

	if ((p4 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P4", 0);
	}

	if ((p5 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P5", 0);
	}

	// 同第二个 wait 函数，而这里的 wait 则只要 p2/p3/p4/p5 中有一个返回，即结束。这是因为上面的 wait 可能会截留 p2/p3 中的任意一个。
	pid = wait(&status);
	if (pid == p4) end_p4 = 1;
	if (pid == p5) end_p5 = 1;

	printf("---------\n");
}

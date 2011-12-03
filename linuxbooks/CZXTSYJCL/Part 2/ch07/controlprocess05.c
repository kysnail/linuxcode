/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-03
 * Description:
 * 	这里与 controlprocess04.c 的区别在于不再使用循环等待子进程的返回，而是使用两个 wait 函数
 * 	完成等价的工作。
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
	// 也正是由于这个细微的差别，所以子进程执行顺序仍是混乱的，只能保证 p2/p3 中的一个领先
	// 于 p4/p5 但另一个是否一定弄呢狗狗领先于 p4/p5 则不能确定。
	pid = wait(&status);
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

	// 作用与上面的 do...while 类似，不同的地方在于，次循环可以保证 p4&p5 都完成后，再运行下一条指令。
	pid = wait(&status);
	pid = wait(&status);
	if (pid == p4) end_p4 = 1;
	if (pid == p5) end_p5 = 1;

	printf("---------\n");
}

/**
 * Result:
 *  $ ./a.out 
 *  I am P1
 *  I am P3
 *  I am P2
 *  I am P4
 *  I am P5
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
 *  I am P4
 *  I am P5
 *  ---------
 *

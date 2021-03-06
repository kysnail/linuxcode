/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-03
 * Description:
 * 	这里程序保证如下的执行流程：
 * 		与 controlprocess06.c 的区别在于，不再强制 p2 与 p3 同时执行完成。
 * 		因为本身从流程执行上来说，p2 只是作为 p7 的先导条件，它的要求仅是在 p7 执行之前
 * 		必须运行完成，而 p3 本身是作为 p4/p5 的先导条件。详细的流程参看下图：
 * 		
 *		     |-> p2 ----------------------> |
 *		p1 ->|                              | -> p7
 *		     |         |-> p4 -> |          |
 *		     |-> p3 -> |         | -> p6 -> |
 *		               |-> p5 -> |  
 *
 *		从图中可以看到，实际上 controlprocess06.c 并不满足上面的执行流程。为了正确的表示
 *		执行的先后顺序，需要修改第一个 wait 循环处。
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
	} while (end_p3 == 0);	// 实际的流程只需要保证在 p4/p5 执行前，完成 p3 的操作即可。
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

	if ((p6 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P6", 0);
	}

	do
	{
		pid = wait(&status);
		if (pid == p2) end_p2 = 1;
		if (pid == p6) end_p6 = 1;
	} while(end_p2 == 0 || end_p6 == 0);

	if ((p7 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P7", 0);
	}
	wait(&status);
	exit(1);
	printf("---------\n");
}

/**
 * Result:
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P4
 * I am P5
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P5
 * I am P4
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P5
 * I am P4
 * I am P6
 * ^P
 * ^P
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P4
 * I am P5
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P4
 * I am P5
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P5
 * I am P4
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P5
 * I am P4
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P2
 * I am P3
 * I am P5
 * I am P4
 * I am P6
 * I am P7
 * $ ./a.out 
 * I am P1
 * I am P2
 * I am P3
 * I am P5
 * I am P4
 * I am P6
 * I am P7
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P5
 * I am P4
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P3
 * I am P2
 * I am P4
 * I am P5
 * I am P6
 * ^C
 * $ ./a.out 
 * I am P1
 * I am P2
 * I am P3
 * I am P4
 * I am P5
 * I am P6
 * I am P7
 *
 * 从执行结果中可以发现，只要沿着 p1->p2->p3->p4->p5->p6->p7 流程执行下去，则程序可以正常完成，否则程序编程处于无响应的状态。
 *
 * 之所以产生上面的现象，可以作如下解释：
 * 	在第一个 do...while() 循环时，p3 先于 p2 执行完成，所以 p2 在这里未来得及为 end_p2 作置 1 操作。
 * 	这样在第二个 do...while() 循环时，由于 p6 执行完成后会将 end_p6 置 1 ，但并没有将 end_p2 置为 1 机会，所以会在这里产生一个
 * 	死循环。
 *
 * 	之所以能想到这里，也是从结果上看出来的。从执行结果上看，如果程序无响应，则停止在 p6 进程执行完成，p7 进程尚未开始的阶段。
 * 	能产生这个效果的代码段也只有第二个 do...while() 循环可以做到。
 *
 * 	p2 进程只有在第一个循环有一次获得 end_p2 置 1 的操作，如果这次没有成功，则后面成功的概率非常小。因为第二次置 1 的操作
 * 	是在 p4/p5 进程都执行完成后才有可能发生，而 p2 进程基本不可能延续这么长时间。
 *
 * 	从这里也可以看出 C 语言的陷阱实在是太多了！！！！
 */

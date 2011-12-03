/**
 * Author:
 * 	kysnail
 * Date:
 * 	2011-12-02
 * Description:
 * 	创建两个子进程，但只会打印出一条 "----------" ，因为这里在子进程的分支中使用 execl 替换成了另一个进程
 * 	作用等同于 controlprocess01 中添加 return 的效果，从子进程返回。	
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
		execl("/bin/echo", "echo", "I am P1", 0);
	 	//printf("Process 1 \n");
		//return 0;
	}

//	wait(&status);
	if ((p2 = fork()) == 0)
	{
		execl("/bin/echo", "echo", "I am P2", 0);
	 	//printf("Process 2 \n");
		//return 0;
	}

	printf("---------\n");
}

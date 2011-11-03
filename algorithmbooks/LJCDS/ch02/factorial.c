/**
 * Objective:
 * 		打印出 n 的阶乘 n! 。
 * Notes:
 * 		递归算法两个主要知识点：
 * 			1. 创建正确的递归式；
 * 			2. 正确的递归终止条件。
 * 		该问题递归终止时，必然求出的是第一个元素的值，那么这是只需要返回 a[0] 即可。
 *		至于递归式，必然是 n*(n-1)!。有了前面的数学式，就可以将其转换为程序代码了。
 *			[n * (n - 1)!] => [n * factorial(n - 1)]
 * Author:
 * 		kysnail
 * Date:
 *		2011-08-30
 */
#include <stdio.h>

long factorial(int n);

void main()
{
	int i, num;
	printf("打印出 20 以内的阶乘。\n");
	printf("请输入阶乘数: ");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
		printf("%d! = %ld\n", i, factorial(i));
}

long factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n-1);		// 递归的数学式 [n*(n-1)!] => [n*factorial(n-1)] 
}

/*
	Output:	
		$ ./a.out 
			打印出 20 以内的阶乘。
			请输入阶乘数: 10
			0! = 1
			1! = 1
			2! = 2
			3! = 6
			4! = 24
			5! = 120
			6! = 720
			7! = 5040
			8! = 40320
			9! = 362880
*/

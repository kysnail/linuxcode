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
 * 		在用递归解决问题时，递归函数只知道怎样解决最简单的问题，我们称此类为题为基本问题。
 * 		递归函数在解决基本问题时只是返回一个值。
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
/* 递归函数实现。当 n = 0 时，递归返回；否则递归调用。 */
/* 这种对于函数作用的语义描述，对于书写递归函数很有作用。 */
{
	if (n == 0)
		return 1;				// 0! = 1 是最基本问题的解。
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

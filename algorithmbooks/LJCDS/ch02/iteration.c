/**
 * Objective:
 * 		求 n 个自然数的和的递归函数
 * Notes:
 * 		递归算法两个主要知识点：
 * 			1. 创建正确的递归式；
 * 			2. 正确的递归终止条件。
 * 		该问题递归终止时，必然求出的是第一个元素的值，那么这是只需要返回 a[0] 即可。
 *		至于递归式，必然是 a[n] + sum(a, n-1)
 * 			[a(n) + sum(0, n-1)] => [a[n] + sum(a, n-1)]
 * Author:
 * 		kysnail
 * Date:
 *		2011-08-30
 */
#include <stdio.h>
#define N 50

int sum(int a[], int n);

void main()
{
	int i, n, a[N];
	printf("请输入一个 50 内的和: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		a[i] = i + 1;		
	
	printf("前 %d 个自然数的和为: %d\n", n, sum(a, n));
}

// 递归求数组 a 前 n 个数的和 
int sum(int a[], int n)
{
	if (n <= 0)
		return 0;		// 前 a[0] 个元素的 sum 值为 0
	else
		return a[n-1] + sum(a, n-1); 	// 递归求前 n 个数的和
}

/*
	Output:	
		$ ./a.out 
		请输入一个 50 内的和: 19^H0
		前 19 个自然数的和为: 190
	输出结果很有意思，这里虽说在数字之间夹了一个 ^H 字符，但是并未影响计算结果，这表明
	^H 并没有被系统所获取。	
*/

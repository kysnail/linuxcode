## execute result of more03 
more03 的执行结果相对比较蹊跷一些，具体原因还是没想清楚：

	1
	2
	3
	4
	5
	6
	7
	8
	9
	10
	11
	12
	13
	14
	15
	16
	17
	18
	19
	20
	21
	22
	23
	24
	[7m more? [m25
	incrementing numbers 是由下面的指令产生的：

		:.!printf '\%s\n' {1..100}

输出 25 比较好理解，但为什么会输出后面两行？

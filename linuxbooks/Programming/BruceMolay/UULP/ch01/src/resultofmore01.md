## the execute result of more01

	cat 1 | ./more01

执行上面的命令后，得到如下的输出：

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
	[7m more? [m25	<-- [7m [m -- 这个标签的作用是反白 more? 
	[7m more? [m27
	[7m more? [m29
	[7m more? [m31
	[7m more? [m33
	[7m more? [m35
	[7m more? [m37
	[7m more? [m39
	[7m more? [m41
	[7m more? [m43
	[7m more? [m45
	[7m more? [m47
	[7m more? [m49
	[7m more? [m51
	[7m more? [m53
	[7m more? [m55
	[7m more? [m57
	[7m more? [m59
	[7m more? [m61
	[7m more? [m63
	[7m more? [m65
	[7m more? [m67
	[7m more? [m69
	[7m more? [m71
	[7m more? [m73
	[7m more? [m75
	[7m more? [m77
	[7m more? [m79
	[7m more? [m81
	[7m more? [m83
	[7m more? [m85
	[7m more? [m87
	[7m more? [m89
	[7m more? [m91
	[7m more? [m93
	[7m more? [m95
	[7m more? [m97
	[7m more? [m99

之所以产生上面这种输出的原因分析如下：

	首先，由于未提供文件，所以默认从标准输入获取数据，也就是走

		if (ac == 1)
			do_more(stdin);

	这个分支。而这里由于管道操作符 | 的作用，使得标准输入重定向到 cat 的标准输出。

	进入 do_more() 函数内部后，开始进行数据的显示输出。前面的 24 行输出没有任何问题，但当到 25 行时，本
	身应该获得标准输入的指令（也就是我们平时使用的键盘），却由于重定向的问题，使得他从同一个标准输出开始
	进行数据的读入操作。

	上面的 24 行完成后，就该进入 see_more() 函数了，这个函数从从定向后的标准输入采集数据，也就是在 see_more()
	中循环的解析数据，这个操作由 fgets() 方法完成：
		2
		5
		\n
	
	最终由 fputs 完成输出。

感觉稍微有些复杂了，但只要理解了其原理，实际也好懂。

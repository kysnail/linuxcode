# 第 1 章 - Unix 系统编程概述

## fortune
一个很有意思的程序，貌似以前在那里听到过。

	==$ fortune
	When in doubt, do it.  It's much easier to apologize than to get permission.
			-- Grace Murray Hopper
 
这个程序会随机的打印一些格言。

	fortune - print a random, hopefully interesting, adage.

## 文件操作

### 文件命名规则
书中说道，文件名甚至可以出现 **回车符** ，还是第一次听说。

### 文件删除操作
文中提到 Unix 并不提供文件恢复功能：

	其中的一个原因是 Unix 是一个多用户系统，当一个文件被删掉以后，它所占用的存储空间被立即分配给其他用户的文件。

此书英文版大概在 2003 年出版，可能那时的 Unix 不提供恢复功能，但现在的可能会提供了。

### 打印文件
用 lpr 来打印文件，还可以用 lp 命令完成同样的操作。

### 文件权限
文件所有者甚至可以取消自己读自己文件的权限。

## 1.5 从系统的角度来看 Unix


### 1.5.3 bc：Unix 的计算器
Unix 系统中的 bc 命令是执行一个基于字符的计算器程序：

	bc - An arbitrary precision calculator language

bc 还可以进行编程，可以定义变量，有逻辑判断和循环结构，语法与 C 语言类似：

	x = 3
	if (x == 3) {
		
	}

bc 的另一个重要特点是，从严格意义上讲，bc 并不做任何计算。实际的计算交由 `dc` 来完成。bc 是 dc 的预处理器，它将用户输入的表达式转换成逆波兰表达式，然后通过一个称为管道（pipe）的通信程序交给 dc。

	从上面的这个 bc 计算器例子，我们可以看到在
	Unix 系统编程在很多场合下，就是要解决好建立这些独立程序之间的连接和协作方式的问题。

### 逆波兰式 - 后缀表达式

	TODO

## 1.6 动手实践

### more 的三种用法

	$ more filename
	$ command | more
	$ more < filename

我还未分析过 more 程序的工作流程，这里作者的分析比较好，而且通过很简洁的方式将此流程表达出来了。

	+----> show 24 lines from input
	| +--> print [more?] message
	| |    Input Enter, SPACE, or q
	| +--> if Enter, advance one line
	|----> if SPACE
	       if q --> exit

### version 0.1 of more
此版本先写出一个 more 工具的初始版本，这个版本还有很多问题，但正是这遗留下的问题，对于我们深入的理解很有好处。

对于此版本的程序有几点比较有趣：

 1. 使用了 `FILE` 结构体
 2. `main` 函数本身的写法与自己以往所看到的都不相同，相对比较简化
 3. 它的循环处理比较有趣，也是第一次看到这种处理方式

	while (--ac)                                    <-- ac 代表所有参数的个数
		if ((fp = fopen(*++av, "r")) != NULL)   <-- av 代表具体哪个参数

 4. 还有就是处理问题的思路，比如在开始写代码之前，先画出了上面的流程图。

更详细的内容，可以参看代码：

	src/more01.c

#### warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
编译过程中报了下面的错误

	==$ gcc more01.c -o more01
	more01.c: In function ‘main’:
	more01.c:38:4: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
	more01.c: In function ‘do_more’:
	more01.c:58:4: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]

	source code:
	------------
	
	int main(int ac, char *av[])
	{
		FILE *fp;
		if (ac == 1)
			do_more(stdin);
		else
			while(--ac)
			if((fp = fopen(*++av, "r")) != NULL)
			{
				do_more(fp);
				fclose(fp);
			}
			else
				exit(1);	<--- line 38
		return 0;
	}


	void do_more(FILE *fp)
	/* 
	 * read PAGELEN lines, then call see_more() for further instructions
	 */
	{
		char line[LINELEN];
		int  num_of_lines = 0;
		int  see_more(), reply;
		while (fgets(line, LINELEN, fp)) {				/* more input */
			if (num_of_lines == PAGELEN) {				/* full screen? */
				reply = see_more();				/* y: ask user */
				if (reply == 0)					/* n: done */
					break;
				num_of_lines -= reply;				/* reset count */
			}
			if (fputs(line, stdout) == EOF)				/* show line */
				exit(1);					/* or die */		<--- line 58
			num_of_lines++;						/* count it */
		}
	}

解决这个问题可以加入 `stdlib.h` 头文件。因为 `exit()` 函数是一个库函数，需要引入对应的头文件。

#### the execute result of more01
在分析执行结果的过程中，我们发现，发生这种问题的原因在于：

	从同一个数据流中读取用户的输入。
	-----
	查看：
	-----
	/src/resultofmore01.md

实际上，翻页等发命令的操作，最好能够直接从键盘读取。下面的第二个版本就准备解决这个问题。

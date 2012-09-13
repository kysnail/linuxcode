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
	| +--- if Enter, advance one line
	+----- if SPACE
	       if q --> exit

### version 0.1 of more
此版本先写出一个 more 工具的初始版本，这个版本还有很多问题，但正是这遗留下的问题，对于我们深入的理解很有好处。

对于此版本的程序有几点比较有趣：

 * 使用了 `FILE` 结构体
 * `main` 函数本身的写法与自己以往所看到的都不相同，相对比较简化
 * 它的循环处理比较有趣，也是第一次看到这种处理方式

-

	while (--ac)                                    <-- ac 代表所有参数的个数
		if ((fp = fopen(*++av, "r")) != NULL)   <-- av 代表具体哪个参数

-

 * 还有就是处理问题的思路，比如在开始写代码之前，先画出了上面的流程图。

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

### version 0.2 of more
为了解决上面的遗留问题，可以采用下面的方式：

	1. 从标准输入读入要分页的数据；
	2. 从键盘读入用户输入的命令。

在此过程中，必须借用 `/dev/tty` 来实现：

	/de/tty
	-------
	这是键盘和显示器的设备描述文件，向这个文件写相当于显示在用户的屏幕上，读相当于从键盘获取用户的输入。
	即使程序的输入/输出被 "<" 或 ">" 重定向，程序还是可以通过这个文件与终端交互数据。

具体内容，查看源代码；

	src/more02.c

这个版本可以从标准输入得到数据，也可以从键盘得到用户的输入，同时通过编写 more02.c ，增加了对文件 `/dev/tty` 的了解。

当然 `more02.c` 仍然还有需要完善的地方，比如输入命令后，还需要按回车键才会显示。

### 对输入的进一步处理
上面的程序还远未达到使用的程度，用户操作的终端有很多参数，可以调整参数使得用户输入的字符被立即送到程序，而不用等待回车，还可以使输入的字符不回显。结构如下图所示：

	*------*                  *------*                     ***********
	|      |                  |      |                     *         *
	| who  |----------------->| more |-------------------->* Display *
	|      |                  |      |                     *         *
	*------*                  *------*                     ***********
	                             ^                              |
	                             |                              |
	                             |                              |
	                   *------------------*                     |
	                   *                  *                     |
	                   *   字符处理单元   *                     |
	                   *                  *                     |
	                   *------------------*                     | 
	                             ^                              |
	                             |                              |
	                             |                              |
	                   *------------------*                     |
	                   *                  *                     |
	 /dev/tty -------> *       kernel     * <-------------------*
	                   *                  *
	                   *------------------*

新加入的部分是用于调整终端参数的，程序运行的时候可以动态地调整终端的参数。读到这里，伴随 more 的两个版本的完成，我们也可以看到结构的变化过程。

	*------*                  *------*                     ***********
	|      |                  |      |                     *         *
	| who  |----------------->| more |-------------------->* Display *
	|      |                  |      |                     *         *
	*------*                  *------*                     ***********
	

		more 从标准输入读入数据  -  more01.c

	--------------------------------------------------------------------------------

	*------*                  *------*                     ***********
	|      |                  |      |                     *         *
	| who  |----------------->| more |-------------------->* Display *
	|      |                  |      |                     *         *
	*------*                  *------*                     ***********
	                             ^                              |
	                             |                              |
	                             |                              |
	                   *------------------*                     |
	                   *                  *                     |
	 /dev/tty -------> *     kernel       * <-------------------*
	                   *                  *
	                   *------------------*
			
		more 从键盘读用户的输入  -  more02.c

学会这种思路，先构建最简单的结构，然后再次基础上，慢慢增加组件，使得系统逐渐丰满起来。

#### 思考的问题
要编写一个完善的 more 还有很多工作要做：

 1. 如何知道文件中已显示的百分比？
 2. 如何反白显示文字？
 3. 如何确定每一页的行数？
 4. 如何使程序能够处理各种类型的终端？

### 工作步骤
在研究 more 的过程中展示了解决问题的步骤：

	首先分析一个实际存在的程序，弄清它的功能，分析它的实现原理，然后自己编写一个。
	通过对程序的不断完善来更多地了解 Unix 系统和它的工作原理。

这也是本书采用的主要方法。

### Unix 的概要图
Unix 系统内存被分为 **系统空间** 和 **用户空间** ，内核和它的数据结构位于系统空间，用户程序位于用户空间，用户通过终端连接到系统，文件存放在磁盘上，各种各样的设备被内核直接管理，用户程序可以通过内核来访问设备，最后还有网络连接，用户可以通过网络接入系统。 

### Unix 的发展历史
要是注意的话就会发现，有时候一项功能可以用不同的函数来实现，这有两个原因。

一是 Unix 是由不同的机构完善的，如 AT&T 和 BSD，对于同一个要解决的问题，他们采用了不同的函数名来实现。

另一个原因是 Unix 自身的发展需要兼容，当有一个新的服务可以替代老的服务时，人们并不会把老的系统调用去掉，而是增加新的系统调用，这就使以前编写的程序也可以顺利地运行。

在本书中也有这样的情况，可以用不同的函数来做同一件事情，作为系统程序员，这是经常的和不可避免的。

### 小结

 * 计算机系统中包含了很多系统资源，如硬盘、内存、外围设备、网络连接等，程序利用这些资源来对数据进行存储、转换和处理。
 * 多用户系统需要一个中央管理程序，Unix 的内核就是这样的程序，它可以对程序和资源进行管理。
 * 用户程序要访问设备必须经过内核。
 * 一些 Unix 的系统功能是由多个程序的协作而实现的。
 * 要编写系统程序，必须对系统调用和相关的数据结构有深入的理解。


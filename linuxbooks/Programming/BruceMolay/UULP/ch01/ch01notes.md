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




## Blob Object
`blob` 文件通常用来存放文件内容。

	------------------------
	|blob		|size	|
	------------------------
	|file contents		|
	|			|
	|			|
	------------------------

既然 git 架构了一个虚拟的文件系统，那么就可以使用 git 提供的命令查看 blob 对象的内容了，下面是一个实例，当然在演示前，要先得到该对象的 SHA 标识值。

	kysnail@mydebianwork:BPL$ git ls-tree -r HEAD
	100644 blob ba5ef4b0acd99909426244ab69d14b7d52fd99b1	ch01/bill.c
	100644 blob 598b70842f78f9f10e72be5c885b3ede46551608	ch01/fred.c
	100644 blob 103ef88608bebc60a82fe6585abc3503ab7d6556	ch01/lib.h
	100644 blob 515c8ebe5445bc541fd2290a31f4205b2ee9f0ab	ch01/program.c
	You have new mail in /var/mail/kysnail
	kysnail@mydebianwork:BPL$ git show ch01/fred.c
	kysnail@mydebianwork:BPL$ git show 598b70842f78f9f10e72be5c885b3ede46551608
	#include <stdio.h>

	void fred(int arg)
	{
		printf("fred: you passed %d\n", arg);
	}

**blob** 对象就是一个数据块，没有其他的属性，甚至没有文件名。正因为 blob 对象的内容中只存放数据，如果两个文件有相同的内容，必定会产生相同的 SHA 标识，所以 blob 对象与所在的位置、文件名是否被改变没有任何关系。

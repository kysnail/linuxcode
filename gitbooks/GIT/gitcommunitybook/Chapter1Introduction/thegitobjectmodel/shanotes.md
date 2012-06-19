## SHA
在 git 中所有需要表示的东西都会由一个哈希值进行索引。比如下面的这个例子。

	kysnail@mydebianwork:BPL$ pwd
	/work/repo/git/gh/linuxcode/BPL

	# 查看指定 423c3ba8888de883bd6a8629648a998964f3ba8f 的 patch 信息。
	# 提交该版本时，为此次 commit 对象生成了一个哈希值对象名。
	kysnail@mydebianwork:BPL$ git log -1 -p 423c3ba8888de883bd6a8629648a998964f3ba8f
	commit 423c3ba8888de883bd6a8629648a998964f3ba8f
	Author: kysnail <lifeofprogrammer@gmail.com>
	Date:   Tue Aug 30 13:13:33 2011 +0800

	    Start reading Beginning Linux Programming

	diff --git a/BPL/ch01/bill.c b/BPL/ch01/bill.c
	new file mode 100644
	index 0000000..ba5ef4b
	--- /dev/null
	+++ b/BPL/ch01/bill.c
	@@ -0,0 +1,6 @@
	+#include <stdio.h>
	+
	+void bill(char *arg)
	+{
	+       printf("bill: you passed %s\n", arg);
	+}
	diff --git a/BPL/ch01/fred.c b/BPL/ch01/fred.c
	new file mode 100644
	index 0000000..598b708
	--- /dev/null
	+++ b/BPL/ch01/fred.c
	@@ -0,0 +1,6 @@
	+#include <stdio.h>
	+
	+void fred(int arg)
	+{
	+       printf("fred: you passed %d\n", arg);
	+}
	diff --git a/BPL/ch01/lib.h b/BPL/ch01/lib.h
	new file mode 100644
	index 0000000..103ef88
	--- /dev/null
	+++ b/BPL/ch01/lib.h
	@@ -0,0 +1,6 @@
	+/*
	+       This is lib.h. It declares the function fred and bill for users.
	+*/
	+
	+void bill(char *);
	+void fred(int);
	diff --git a/BPL/ch01/program.c b/BPL/ch01/program.c
	new file mode 100644
	index 0000000..515c8eb
	--- /dev/null
	+++ b/BPL/ch01/program.c
	@@ -0,0 +1,7 @@
	+#include "lib.h"
	+
	+int main()
	+{
	+       bill("Hello World!");
	+       exit(0);
	+}

	kysnail@mydebianwork:BPL$ pwd
	/work/repo/git/gh/linuxcode/BPL

	## 可以看到，为 tree 对象生成了一个哈希值标识。
	kysnail@mydebianwork:BPL$ git ls-tree HEAD
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01

	## 使用 -r 递归选项，可以查看到对于每一个条件的文件 blob 对象，也同样会生成一个对应的哈希值标识。
	kysnail@mydebianwork:BPL$ git ls-tree -r HEAD
	100644 blob ba5ef4b0acd99909426244ab69d14b7d52fd99b1	ch01/bill.c
	100644 blob 598b70842f78f9f10e72be5c885b3ede46551608	ch01/fred.c
	100644 blob 103ef88608bebc60a82fe6585abc3503ab7d6556	ch01/lib.h
	100644 blob 515c8ebe5445bc541fd2290a31f4205b2ee9f0ab	ch01/program.c

### 这样做的优点：

 * Git只要比较对象名，就可以很快的判断两个对象是否相同。
 * 因为在每个仓库（repository）的“对象名”的计算方法都完全一样，如果同样的内容存在两个不同的仓库中，就会存在相同的“对象名”下。
 * Git还可以通过检查对象内容的SHA1的哈希值和“对象名”是否相同，来判断对象内容是否正确。

**Refs**

 * [git使用笔记(zt)](http://hi.baidu.com/rwen2012/blog/item/2b72cd13289f43dbf6039e06.html)

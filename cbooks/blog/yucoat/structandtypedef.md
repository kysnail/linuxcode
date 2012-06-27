##结构体struct和typedef后面接指针的含义。
在C语言里面，struct是用来定义新的数据类型——结构体，typedef是给数据类型取别名。
据说这两个关键词同时使用有助于减少代码量和增加代码的可读性（不过我认为它当typedef和struct在一起的时候反而降低了代码的可读性），很多时候为了方便，我们常常讲stuct与typedef放在一起用。

像这样的代码是比较好理解的，就是取FileInfo为sturct file的别名嘛。

	typedef struct file {
		...
	}FileInfo;

但是在严奶奶的《数据结构》那本书里面却充满了这样的用法：

	typedef struct file {
		...
	}FileInfo, *FileP

这种用法让我感到很迷惑，经过了本人多方考证和验证，它是这么个意思：

 * 给struct file        取个别名为FileInfo
 * 给struct file *      取个别名为FileP

说也怪啊。你说用 `typedef struct … FileInfo `增 加代码的可读性，我勉强可以接受。
但是你说用 `typedef struct … *FileP` 可以增加代码的可读性，我真的是撞邪了。当我面对下面一行代码的时候

	FileP p

要不是其中的“P”，我还真的想不到变量“P”是一个指针。



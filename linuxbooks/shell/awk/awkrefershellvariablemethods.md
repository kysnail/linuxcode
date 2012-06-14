## awk 引用 shell 变量的几种常见方法

### "'$var'"
这种写法大家无需改变用 `'` 括起 awk 程序的习惯，是老外常用的写法。如：

	$ var="test"
	$ awk 'BEGIN{print "'$var'"}'
	test

这种写法其实就是把一对单引号分成了两段单引号，中间的 shell 变量直接按照 shell 变量的引用方式即可，但是如果 var 中含空格，为了 shell 不把空格作为分隔符，便应该如下使用：

	$ var="this is a test"
	$ awk 'BEGIN{print "'"$var"'"}'
	this is a test
	$

也就是在 shell 变量的两边加上一对双引号即可。

### export 变量，使用 ENVIRON["var"] 形式

	First, you need to export environment variables if you want them to be passed in the environment
	of child process like awk.
	
	Second, you can use ENVIRON["name"] to get an environment variable in awk. So the following works 
	for me:

	$ export file=tau
	$ export f=2.54
	$ export order=even
	$ awk '{sum+=$2}; END {print ENVIRON["file"] "_" ENVIRION["f"] "_" ENVIRON["order"] "_v1.xls", sum/NR}'

`ENVIRON` 为 awk 中的内置环境变量数组。

	$ var="this is a test"; export var
	$ awk 'BEGIN{print ENVIRON["var"]}'
	this is a test
	$ 

### 当然也可以使用 -v 选项

	$ var="this is a test"
	$ awk -v nvar="$var" 'BEGIN{print nvar}'
	this is a test
	$ 

这样便把系统变量定义成了 awk 变量。

如果在 awk 是这种格式的话 `awk 'script' file` 也可以这样引用 shell 变量 `awk 'script' awkvar="shellvar" filename`。

	awk 'END {print awkvar}' awkvar="$shellvar" filename

**Refs**

 * [How to print variable inside awk](http://stackoverflow.com/questions/1829074/how-to-print-variable-inside-awk)
 * [awk引用shell变量的几种常见方法 ](http://blog.sina.com.cn/s/blog_3d2d79aa0100h4x1.html)

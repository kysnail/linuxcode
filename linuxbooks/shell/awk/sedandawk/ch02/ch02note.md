## Chapter 2 - Understanding Basic Operations
在阅读 **Learning the vi and vim** 这本书的时候，提到了 vi 实际上是 **ex** 命令的界面模式。

	vi is the visual mode of the more general, underlying line editor, which is ex.

而 sed 和 awk 都起源于 **ed** 命令，这两个命令的名称类似，功能也蛮相近。既然两者起源相同，那么最好从而这的共同点入手了：

 1. They are invoked using similar syntax.
 2. They are both stream-oriented, reading input from text files one line at a time and directing the reault to standard output.
 3. They use regular expression for pattern matching.
 4. They allow the user to specify instructions in a script.






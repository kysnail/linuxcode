# ctags
ctags 会标记程序中的一些重要元素（函数，宏定义...）的定义位置。这样，我们就可以从这个元素的任意一个出现的位置，快速找到它的定义。ctags 可以配合多种编辑器，这里我们以 vim 为例。

## ctags 的安装

	sudo apt-get install ctags

## ctags 的使用

	$ ctags *

	ctrl+]	-> 跳转到定义
	ctrl+o	-> 返回

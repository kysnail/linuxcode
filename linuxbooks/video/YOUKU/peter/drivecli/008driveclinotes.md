## drive cli
本集介绍命令行使用的一些小技巧。通过修改配置，让我们的gnome-terminal更漂亮一些，通过快捷键的使用，让我们的bash操作更加高效。

### 1. 全屏+隐藏菜单栏
重新创建一个命令，并在其中配置 gnome-terminal 启动参数，实现全屏，无菜单栏效果。

	# vim /bin/myterminal
	> gnome-terminal --full-screen --hide-menubar

### 2. 修改 .bashrc 中的 PS1 变量

### 3. bash 自动补齐功能
具体的补齐功能也可以在 .bashrc 中查看，实际的补齐效果来源于 `/etc/bash_completion` 。

### 4. 软件的补齐功能
软件的补齐功能通常会存放在

	/etc/bash_completion.d/

中。比如 git 的参数补齐功能时。通常 apt-get 会自动帮助我们安装这些补全设置文件，源码安装时可能就没有这么方便了。

### 5. bash 命令编辑模式
默认 bash 使用 emacs 的编辑模式。

	gnome-terminal 下可以用 ^+arrowkey 单词间跳转。

可以使用下面的方式切换到 vim 模式。

	# set -o vi

### 6. ^+R 反向查找



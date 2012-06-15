## drive cli
本集介绍命令行使用的一些小技巧。通过修改配置，让我们的gnome-terminal更漂亮一些，通过快捷键的使用，让我们的bash操作更加高效。

### 1. 全屏+隐藏菜单栏
重新创建一个命令，并在其中配置 gnome-terminal 启动参数，实现全屏，无菜单栏效果。

	# vim /bin/myterminal
	> gnome-terminal --full-screen --hide-menubar


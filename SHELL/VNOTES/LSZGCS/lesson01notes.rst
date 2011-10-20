
查看本机所有的 shell 类型
=========================
::

	kysnail@ubunkysnail:~$ cat /etc/shells 
	# /etc/shells: valid login shells
	/bin/csh
	/bin/sh
	/usr/bin/es
	/usr/bin/ksh
	/bin/ksh
	/usr/bin/rc
	/usr/bin/tcsh
	/bin/tcsh
	/usr/bin/esh
	/bin/dash
	/bin/bash
	/bin/rbash
	/usr/bin/screen

查看当前 shell 类型
===================
::

	kysnail@ubunkysnail:~$ echo $SHELL
	/bin/bash

作为 Linux 的默认 shell 相较于其它 shell 的特点
===============================================

	- dos key 功能，即历史命令翻查功能。
	- 自动补全
	- 帮助提示

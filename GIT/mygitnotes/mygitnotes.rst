:kysnail
:TracingLife@gmail.com

Git Notes
=========

    Git 的常用操作。

移动文件
--------
    使用 Git 或 Subversion 这类版本管理工具时需要注意，由于文件的所有状态不仅仅被操作系统所监控，所在的版本
    控制系统也要监控你的文件修改状况，所以这时如果想要做文件移动操作就需要通知所在的版本控制系统了。::
	git mv ch02notes.rst ../ch02/
	git commit -m "Moved ch02notes into ch02 directory."

重命名文件
----------
    与 Linux 系统保持一致，并不提供诸如 cmd 下的 rename 命令，而是直接用 mv 命令进行操作。::
	git mv part1notes.txt part1notes.rst
	git commit -m "Changed part1notes from TXT to ReSTructured text."


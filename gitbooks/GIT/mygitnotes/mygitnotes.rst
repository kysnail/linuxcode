:author kysnail

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


重命名文件夹
------------
    下面是重命名文件夹的过程。 ::

	$ git mv TA\&SOJS/ TASOJS
	$ git status
	# On branch master
	# Changes to be committed:
	#   (use "git reset HEAD <file>..." to unstage)
	#
	#	renamed:    TA&SOJS/README -> TASOJS/README
	#	renamed:    TA&SOJS/ch01/ch01notes.mkd -> TASOJS/ch01/ch01notes.mkd
	#	renamed:    TA&SOJS/ch05/ch05notes.mkd -> TASOJS/ch05/ch05notes.mkd
	#

	[master d8c1f16] Rename folder name TA&SOJS to TASOJS.
	 3 files changed, 0 insertions(+), 0 deletions(-)
	 rename javascriptbooks/{TA&SOJS => TASOJS}/README (100%)
	 rename javascriptbooks/{TA&SOJS => TASOJS}/ch01/ch01notes.mkd (100%)
	 rename javascriptbooks/{TA&SOJS => TASOJS}/ch05/ch05notes.mkd (100%)

日常操作流程
------------
1. 不论在哪里，开始进行工作的第一步，应该首先 pull 操作。
::

    git pull

获取最新的版本后，才开始下一步的工作。

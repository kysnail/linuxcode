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


批量提交文件
------------
有时需要批量提交文件，可以使用如下的操作步骤完成： ::

	$ git add -A
	$ git status
	# On branch master
	# Changes to be committed:
	#   (use "git reset HEAD <file>..." to unstage)
	#
	#	new file:   ch01/ch01notes.mkd
	#	new file:   ch02/ch02notes.mkd
	#	new file:   ch03/ch03notes.mkd
	#	new file:   ch04/ch04notes.mkd
	#	new file:   ch05/ch05notes.mkd
	#	new file:   ch06/ch06notes.mkd
	#	new file:   ch07/ch07notes.mkd
	#	new file:   ch08/ch08notes.mkd
	#	new file:   ch09/ch09notes.mkd
	#

	$ git commit -m "Add new book - Simply JavaScript"
	[master 1633ba5] Add new book - Simply JavaScript
	 0 files changed, 0 insertions(+), 0 deletions(-)
	 create mode 100644 javascriptbooks/SJ/ch01/ch01notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch02/ch02notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch03/ch03notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch04/ch04notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch05/ch05notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch06/ch06notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch07/ch07notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch08/ch08notes.mkd
	 create mode 100644 javascriptbooks/SJ/ch09/ch09notes.mkd
	$ git push
	Password: 
	Counting objects: 16, done.
	Delta compression using up to 2 threads.
	Compressing objects: 100% (4/4), done.
	Writing objects: 100% (14/14), 1.09 KiB, done.
	Total 14 (delta 1), reused 0 (delta 0)
	To https://kysnail@github.com/kysnail/linuxcode.git
	   d0cee28..1633ba5  master -> master

git add -A
``````````
::

	$ git add -a
	error: unknown switch `a'
	usage: git add [options] [--] <filepattern>...

	    -n, --dry-run         dry run
	    -v, --verbose         be verbose

	    -i, --interactive     interactive picking
	    -p, --patch           interactive patching
	    -e, --edit            edit current diff and apply
	    -f, --force           allow adding otherwise ignored files
	    -u, --update          update tracked files
	    -N, --intent-to-add   record only the fact that the path will be added later
	    -A, --all             add all, noticing removal of tracked files
	    --refresh             don't add, only refresh the index
	    --ignore-errors       just skip files which cannot be added because of errors

取消对文件的修改
----------------
不想提交修改的文件，可以使用下面的操作解决：

::

        $ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 2 commits.
        #
        # Changed but not updated:
        #   (use "git add <file>..." to update what will be committed)
        #   (use "git checkout -- <file>..." to discard changes in working directory)
        #
        #       modified:   controlprocess.c
        #
        no changes added to commit (use "git add" and/or "git commit -a")
        $ git checkout -- controlprocess.c
        $ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 2 commits.
        #
        nothing to commit (working directory clean)

Ref:

undo
.. _undo: http://progit.org/book/zh/ch2-4.html


修改最后一次提交
----------------
有时提交完才发现，有些文件没有加，或是提交信息写错了，想要撤销，就可以使用 --amend 选项重新提交。

::

        $ git add mygitnotes/
        $ git commit -m "撤销对文件的修.
        $ git commit --amend
        $ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 2 commits.
        #
        # Changes to be committed:
        #   (use "git reset HEAD <file>..." to unstage)
        #
        #       modified:   mygitnotes/mygitnotes.rst
        #

这里添加中文注释的时候总会出问题，看来还是好好提高英文能力才是出路。


[Chages to be committed & Changed but not updated]同时存在的情况
----------------------------------------------------------------
下面的这个情况，同时存在未提交的和

::

        $ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 2 commits.
        #
        # Changes to be committed:
        #   (use "git reset HEAD <file>..." to unstage)
        #
        #       modified:   mygitnotes/mygitnotes.rst
        #
        # Changed but not updated:
        #   (use "git add <file>..." to update what will be committed)
        #   (use "git checkout -- <file>..." to discard changes in working directory)
        #
        #       modified:   mygitnotes/mygitnotes.rst
        #
        $ git commit -m "撤销对文件的修改"
        [master 02b7f19] 撤销对文件的修改
         1 files changed, 30 insertions(+), 0 deletions(-)
        $ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 3 commits.
        #
        # Changed but not updated:
        #   (use "git add <file>..." to update what will be committed)
        #   (use "git checkout -- <file>..." to discard changes in working directory)
        #
        #       modified:   mygitnotes/mygitnotes.rst
        #
        no changes added to commit (use "git add" and/or "git commit -a")

diff
----
如果想要进行 diff 操作，首先必须要保证该文件已经经过了 add 。比如，你新创建的一个文件，但没有进行 add 操作，在输入某些内容后，并反复修改后，突然
想查看一下到底修改了那些内容，对不起，git 并没有帮你跟踪文件的变化，如果你想让 git 帮你完整的跟踪，记住多提交！！


提交当前文件夹内的所有文件
--------------------------
$ git add .
$ git status
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
#       new file:   handlers.py
#       new file:   handlers.pyc
#       new file:   markup.py
#       new file:   rules.py
#       new file:   rules.pyc
#       new file:   simple_markup.py
#       new file:   test_output.html
#       new file:   util.py
#       new file:   util.pyc
#
$ git commit -a -m "Add source code of chapter 20."
[master 4e9b9e7] Add source code of chapter 20.
 9 files changed, 251 insertions(+), 0 deletions(-)
 create mode 100755 pythonbooks/BPFNTP/code/chapter20/handlers.py
 create mode 100644 pythonbooks/BPFNTP/code/chapter20/handlers.pyc
 create mode 100755 pythonbooks/BPFNTP/code/chapter20/markup.py
 create mode 100755 pythonbooks/BPFNTP/code/chapter20/rules.py
 create mode 100644 pythonbooks/BPFNTP/code/chapter20/rules.pyc
 create mode 100755 pythonbooks/BPFNTP/code/chapter20/simple_markup.py
 create mode 100644 pythonbooks/BPFNTP/code/chapter20/test_output.html
 create mode 100755 pythonbooks/BPFNTP/code/chapter20/util.py
 create mode 100644 pythonbooks/BPFNTP/code/chapter20/util.pyc
$ git status
# On branch master
# Your branch is ahead of 'origin/master' by 1 commit.
#
nothing to commit (working directory clean)

回滚操作
--------
最新发布了 GitHub Windows 版，我尝试了一下。在操作的过程中遇到了一个问题，从仓库中检出的 `linuxcode` 发生了自动转码的问题。本身 linuxcode 是我在 Linux 下的笔记，但当下载到 Windows 系统后，可能自动进行了文本行的转换。系统的日志显示原本的文件被删除了，并在后面追加了新的版本，并在后面追加了 ^M 的字母。

如果使用 `git status` 查看当前仓库，会发现一片飘红。既然是它进行了转换，那么可以回滚这个操作。简单说，也就是抛弃本地的修改。

    # git reset --hard HEAD

需要注意的是，回滚也会产生相应的 log 信息。

reset
.. _reset: http://www.fwolf.com/blog/post/441

高亮支持
--------

    # git config --global color.ui true

[Git颜色高亮](http://poiyzy.heroku.com/blog/2012/02/20/gityan-se-gao-liang/)

终端高亮显示GIT分支信息
-----------------------

    PS1="[\u@\h:\W\[\033[0;32m\]\$(git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/')\033[0m]\$ "

有趣的 \\ 文件
--------------
查看我的笔记目录

::

        [kangyushi@fedora16 linuxcode]$ ll
        total 112
        -rw-r--r--  1 kangyushi ie2  921 Jul 17 16:28 \
        drwxr-xr-x  4 kangyushi ie2 4096 Jul 10 15:10 algorithmbooks
        drwxr-xr-x  3 kangyushi ie2 4096 Jun 11 16:25 assemblybooks
        .....

第一个居然是名为 \ 的文件夹。查看其内容：

::

        $ vim \\
        --------
        1 开启 KVM 支持。
        2 # Please enter the commit message for your changes. Lines starting
        3 # with '#' will be ignored, and an empty message aborts the commit.
        4 # On branch master
        5 # Changes to be committed:
        6 #   (use "git reset HEAD <file>..." to unstage)
        7 #
        8 #       new file:   qemu-kvm-support.md
        9 #
        10 diff --git a/kernelbooks/qemu/qemu-kvm-support.md b/kernelbooks/qemu/qemu-kvm-support.md
        11 new file mode 100644
        12 index 0000000..e2df2a8
        13 --- /dev/null
        14 +++ b/kernelbooks/qemu/qemu-kvm-support.md
        15 @@ -0,0 +1,15 @@
        16 +## 开启 KVM 支持
        17 +
        18 +### 编译时，添加如下选项：
        19 +
        20 +       $ tar zxvf qemu-1.0.1.tar.gz &&
        21 +       cd qemu-1.0.1 &&
        22 +       mkdir mybin &&
        23 +       ./configure --prefix=`pwd`/mybin --enable-kvm &&   <== --enable-kvm 开启 kvm 支持。
        24 +       make && make install
        25 +
        26 +### 启动时，添加下列选项：
        27 +
        28 +       # ./qemu-system-x86_64 
        29 +       -hda /media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img
        30 +       -machine accel=kvm

显示为上一次的 commit 消息，具体怎么来的不知道，但文件名，内容却都很有意思。

使用 `git st` 命令查看时，也会提示为 untracked 文件：

::

        [kangyushi@fedora16 linuxcode]$ git status
        # On branch master
        # Your branch is ahead of 'origin/master' by 1 commit.
        #
        # Changes not staged for commit:
        #   (use "git add <file>..." to update what will be committed)
        #   (use "git checkout -- <file>..." to discard changes in working directory)
        #
        #       modified:   gitbooks/GIT/mygitnotes/mygitnotes.rst
        #
        # Untracked files:
        #   (use "git add <file>..." to include in what will be committed)
        #
        #       "\\"
        #       linuxbooks/Debian/debian-apt-get-notes.md
        no changes added to commit (use "git add" and/or "git commit -a")


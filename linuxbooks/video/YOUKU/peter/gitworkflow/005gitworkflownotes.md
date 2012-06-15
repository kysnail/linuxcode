## git workflow
看看git如何辅助正在单兵作战的你。就像Linus曾经说的，如果一个操作可以比以往快很多的实现，那人们就会用一种全新的方式来使用这个操作。这句话正适用于git出现之后的版本控制。

svn、cvs 这些版本管理工具都是在代码完成后，需要提交 patch 后，才想到版本管理工具。但是 git 让版本控制与写代码进行了融合。

### 创建 project

	[kysnail@mydbian 004]$ mkdir proj
	[kysnail@mydbian 004]$ cd proj
	[kysnail@mydbian proj]$ ls
	[kysnail@mydbian proj]$ vim hello.c
	[kysnail@mydbian proj]$ ls
	hello.c
	[kysnail@mydbian proj]$ git init
	Initialized empty Git repository in /home/kysnail/mywork/004/proj/.git/
	[kysnail@mydbian proj]$ git add 
	Nothing specified, nothing added.
	Maybe you wanted to say 'git add .'?
	[kysnail@mydbian proj]$ git add .
	[kysnail@mydbian proj]$ git config --global alias.ci "commit -a -v"
	[kysnail@mydbian proj]$ git ci
	[master (root-commit) 64530a5] 1st
	 1 files changed, 1 insertions(+), 0 deletions(-)
	 create mode 100644 hello.c
	[kysnail@mydbian proj]$ vim /home/kysnail/.gitconfig 
	[kysnail@mydbian proj]$ git config --global alias.throw "reset --hard HEAD"
	[kysnail@mydbian proj]$ git config --global alias.throwh "reset --hard HEAD^"
	[kysnail@mydbian proj]$ git config 
	[kysnail@mydbian proj]$ vim /home/kysnail/.gitconfig 
	[kysnail@mydbian proj]$ cat /home/kysnail/.gitconfig
	[core]
		editor = vim
	[color]
		ui = true
	[user]
		name = kysnail
		email = TracingLife@gmail.com
	[alias]
		ci = commit -a -v
		throw = reset --hard HEAD
		throwh = reset --hard HEAD^

### git 回滚操作

	[kysnail@mydbian proj]$ vim hello.c 
	[kysnail@mydbian proj]$ git ci
	[master 40f07d0] 2nd
	 1 files changed, 2 insertions(+), 0 deletions(-)
	[kysnail@mydbian proj]$ git diff
	[kysnail@mydbian proj]$ vim hello.c 
	[kysnail@mydbian proj]$ git diff
	diff --git a/hello.c b/hello.c
	index c47213d..5c4135c 100644
	--- a/hello.c
	+++ b/hello.c
	@@ -1,3 +1,4 @@
	 1
	+3
	 2
	 
	[kysnail@mydbian proj]$ git throw
	HEAD is now at 40f07d0 2nd
	[kysnail@mydbian proj]$ git diff
	[kysnail@mydbian proj]$ vim hello.c 
	[kysnail@mydbian proj]$ git throwh
	HEAD is now at 64530a5 1st
	[kysnail@mydbian proj]$ vim hello.c 
	[kysnail@mydbian proj]$ 

### git 回滚指定修改
首先对 hello.h & hello.c 两个文件都进行修改。

	# Please enter the commit message for your changes. Lines starting
	# with '#' will be ignored, and an empty message aborts the commit.
	# On branch master
	# Changes to be committed:
	#   (use "git reset HEAD <file>..." to unstage)
	#
	#       modified:   hello.c
	#       modified:   hello.h
	#
	diff --git a/hello.c b/hello.c
	index d00491f..1191247 100644
	--- a/hello.c
	+++ b/hello.c
	@@ -1 +1,2 @@
	 1
	+2
	diff --git a/hello.h b/hello.h
	index 0cfbf08..48082f7 100644
	--- a/hello.h
	+++ b/hello.h
	@@ -1 +1 @@
	-2
	+12

这里不想要对 hello.h 的修改，可以使用下面的命令完成。

	[kysnail@mydbian proj]$ git checkout hello.h
	[kysnail@mydbian proj]$ git ci
	# Please enter the commit message for your changes. Lines starting
	# with '#' will be ignored, and an empty message aborts the commit.
	# On branch master
	# Changes to be committed:
	#   (use "git reset HEAD <file>..." to unstage)
	#
	#       modified:   hello.c
	#
	diff --git a/hello.c b/hello.c
	index d00491f..1191247 100644
	--- a/hello.c
	+++ b/hello.c
	@@ -1 +1,2 @@
	 1
	+2

### git stash & git stash apply
对于之前做的所有操作，先隐藏起来

	[kysnail@mydbian proj]$ git stash
	Saved working directory and index state WIP on master: 0185e93 nice
	HEAD is now at 0185e93 nice

然后，上面隐藏的 hello.h 的修改，可以用下面的命令调出

	[kysnail@mydbian proj]$ git stash apply
	# On branch master
	# Changed but not updated:
	#   (use "git add <file>..." to update what will be committed)
	#   (use "git checkout -- <file>..." to discard changes in working directory)
	#
	#	modified:   hello.h
	#
	no changes added to commit (use "git add" and/or "git commit -a")

这样，就可以使得我们在中间对 hello.c 所做的修改记录不会污染 git 仓库。

	# Please enter the commit message for your changes. Lines starting
	# with '#' will be ignored, and an empty message aborts the commit.
	# On branch master
	# Changes to be committed:
	#   (use "git reset HEAD <file>..." to unstage)
	#
	#       modified:   hello.c
	#       modified:   hello.h
	#
	diff --git a/hello.c b/hello.c
	index 1191247..f429349 100644
	--- a/hello.c
	+++ b/hello.c
	@@ -1,2 +1,3 @@
	 1
	 2
	+meet you
	diff --git a/hello.h b/hello.h
	index 0cfbf08..35b00ec 100644
	--- a/hello.h
	+++ b/hello.h
	@@ -1 +1,2 @@
	 2
	+nice to

### git branch
使用 `git branch` 避免污染主分支。

	[kysnail@mydbian proj]$ git branch
	* master
	[kysnail@mydbian proj]$ git checkout -b tmp
	Switched to a new branch 'tmp'
	[kysnail@mydbian proj]$ git branch
	  master
	* tmp
	[kysnail@mydbian proj]$ tig
	-bash: tig: command not found
	[kysnail@mydbian proj]$ vim hello.h 
	[kysnail@mydbian proj]$ git ci
	[tmp 6402db3] on tmp
	 1 files changed, 1 insertions(+), 0 deletions(-)
	[kysnail@mydbian proj]$ tig
	[kysnail@mydbian proj]$ git checkout master
	Switched to branch 'master'
	[kysnail@mydbian proj]$ tig
	[kysnail@mydbian proj]$ git branch -D tmp
	Deleted branch tmp (was 6402db3).
	[kysnail@mydbian proj]$ 

### 回到项目比较早期的状态
先使用 git log 等工具，查考要回到状态的提交号，一般是前六位即可，比如这里的 64530a5 。

	[kysnail@mydbian proj]$ git checkout 64530a5 -b tmp
	Switched to a new branch 'tmp'
	[kysnail@mydbian proj]$ git branch
	  master
	* tmp
	[kysnail@mydbian proj]$ tig
	[kysnail@mydbian proj]$ ls
	hello.c
	[kysnail@mydbian proj]$ vim hello.c 
	[kysnail@mydbian proj]$ git checkout master
	Switched to branch 'master'
	[kysnail@mydbian proj]$ git branch -D tmp
	Deleted branch tmp (was 64530a5).
	[kysnail@mydbian proj]$ 

### git add .
扫描当前项目中的所有改动。

### .gitignore
把想忽略的文件添加到 .gitignore 中即可。









## git init
git 的基本配置和使用，帮助初学者快速上手。涉及

 * git diff
 * git config
 * tig

等。让我们不用读文档，而是在实际操作中窥豹于一管。

### git install

	$ sudo apt-get install git

### git 常用操作

	$ mkdir proj
	$ cd proj
	$ git init
	Initialized empty Git repository in /home/kysnail/mywork/004/proj/.git/
	$ ls -a
	.  ..  .git
	$ touch README
	$ git status
	# On branch master
	#
	# Initial commit
	#
	# Untracked files:
	#   (use "git add <file>..." to include in what will be committed)
	#
	#	README
	nothing added to commit but untracked files present (use "git add" to track)
	$ git commit
	# On branch master
	#
	# Initial commit
	#
	# Untracked files:
	#   (use "git add <file>..." to include in what will be committed)
	#
	#	README
	nothing added to commit but untracked files present (use "git add" to track)		

==> 可以看到 git 默认不会跟踪新加的文件，你必须要提示让其跟踪。

	$ git add README
	$ git commit -m "1st"
	[master (root-commit) b4d1f87] 1st
	 Committer: kysnail <kysnail@mydbian.com>
	Your name and email address were configured automatically based
	on your username and hostname. Please check that they are accurate.
	You can suppress this message by setting them explicitly:

	    git config --global user.name "Your Name"
	    git config --global user.email you@example.com

	If the identity used for this commit is wrong, you can fix it with:

	    git commit --amend --author='Your Name <you@example.com>'

	 0 files changed, 0 insertions(+), 0 deletions(-)
	 create mode 100644 README
	$ git confit --global user.name "kysnail"
	git: 'confit' is not a git command. See 'git --help'.

	Did you mean this?
		config
	$ git config --global user.name "kysnail"
	$ git config --global user.email "TracingLife@gmail.com"
	$ cat /home/kysnail/.gitconfig 
	[core]
		editor = vim
	[color]
		ui = true
	[user]
		name = kysnail
		email = TracingLife@gmail.com

	$ vim README 
	$ git add README
	$ git commit -m "see if the name is right?"
	[master ef7dd31] see if the name is right?
	 1 files changed, 1 insertions(+), 0 deletions(-)
	$ git log
	commit ef7dd31e2973f5ded603119fca6133d56f1d5809
	Author: kysnail <TracingLife@gmail.com>
	Date:   Sat Jun 16 00:15:25 2012 +0800

	    see if the name is right?

	commit b4d1f87c9f509ff536c4e9747d5fc1719538ab15
	Author: kysnail <kysnail@mydbian.com>
	Date:   Sat Jun 16 00:12:43 2012 +0800

	    1st

### git log -p(patch)
查看修改内容：

	$ git log -p
	commit ef7dd31e2973f5ded603119fca6133d56f1d5809
	Author: kysnail <TracingLife@gmail.com>
	Date:   Sat Jun 16 00:15:25 2012 +0800

	    see if the name is right?

	diff --git a/README b/README
	index e69de29..d00491f 100644
	--- a/README
	+++ b/README
	@@ -0,0 +1 @@
	+1

	commit b4d1f87c9f509ff536c4e9747d5fc1719538ab15
	Author: kysnail <kysnail@mydbian.com>
	Date:   Sat Jun 16 00:12:43 2012 +0800

	    1st

	diff --git a/README b/README
	new file mode 100644
	index 0000000..e69de29
	$ 

就可以看到 patch 内容了。

### tig

	sudo apt-get install tig



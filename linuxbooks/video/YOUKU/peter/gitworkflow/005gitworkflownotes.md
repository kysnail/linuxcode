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

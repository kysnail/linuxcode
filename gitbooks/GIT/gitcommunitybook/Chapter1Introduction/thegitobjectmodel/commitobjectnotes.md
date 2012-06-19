## Commit Object
**commit** 对象通常指向 tree 对象的一个物理状态（physical state），并添加了一些描述信息，诸如，

 * how we got there
 * why

这东西汉语还真不好翻译，英语的描述还是比较精确。

	The "commit" object links a physical state of a tree with description of how we got there and why.

		ae668...
	---------------------------------
	|commit		|size		|
	---------------------------------
	|tree		|c4ec5		|
	|parent		|a149e		|
	|author		|Scott		|
	|committer	|Scott		|
	---------------------------------
	|my commit message goes here	|
	|and it is really, really cool	|
	---------------------------------

### git show --pretty=raw
你可以使用 `--pretty=raw` 选型，查看某个 commit 对象。

	kysnail@mydebianwork:ch01$ git show --pretty=raw 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	commit 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	tree f5f30cb9c6010e671e3ac960201a3689134f8043
	parent b1ccd0d9162b35c68989d37d9c4f3295b94b096b
	author kysnail <TracingLife@gmail.com> 1339793203 +0800
	committer kysnail <TracingLife@gmail.com> 1339793203 +0800

	    1. 虚拟终端使用技巧；2. bash 使用技巧。

	diff --git a/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md b/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md
	new file mode 100644
	index 0000000..32d3672
	--- /dev/null
	+++ b/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md
	@@ -0,0 +1,5 @@
	+## drive cli
	+本集介绍命令行使用的一些小技巧。通过修改配置，让我们的gnome-terminal更漂亮一些，通过快捷键的使用，让我们的bash操作更加高效。
	+
	+
	+

	## 加上 -s 选项，只提供精简版信息。
	kysnail@mydebianwork:ch01$ git show -s --pretty=raw 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	commit 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	tree f5f30cb9c6010e671e3ac960201a3689134f8043
	parent b1ccd0d9162b35c68989d37d9c4f3295b94b096b
	author kysnail <TracingLife@gmail.com> 1339793203 +0800
	committer kysnail <TracingLife@gmail.com> 1339793203 +0800

	    1. 虚拟终端使用技巧；2. bash 使用技巧。

### git log --pretty=raw

	kysnail@mydebianwork:ch01$ git log -1 --pretty=raw -p 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	commit 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	tree f5f30cb9c6010e671e3ac960201a3689134f8043
	parent b1ccd0d9162b35c68989d37d9c4f3295b94b096b
	author kysnail <TracingLife@gmail.com> 1339793203 +0800
	committer kysnail <TracingLife@gmail.com> 1339793203 +0800

	    1. 虚拟终端使用技巧；2. bash 使用技巧。

	diff --git a/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md b/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md
	new file mode 100644
	index 0000000..32d3672
	--- /dev/null
	+++ b/linuxbooks/video/YOUKU/peter/drivecli/008driveclinotes.md
	@@ -0,0 +1,5 @@
	+## drive cli
	+本集介绍命令行使用的一些小技巧。通过修改配置，让我们的gnome-terminal更漂亮一些，通过快捷键的使用，让我们的bash操作更加高效。
	+
	+
	+

	## -1 ----> 指定显示一条提交信息
	## -s ----> 显示精简版信息
	## --pretty=raw
	###The raw format shows the entire commit exactly as stored in the commit object. Notably, the SHA1s are
        ###displayed in full, regardless of whether --abbrev or --no-abbrev are used, and parents information show the
        ###true parent commits, without taking grafts nor history simplification into account.
	kysnail@mydebianwork:ch01$ git log -1 -s --pretty=raw -p 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	commit 9b6bc8a6940a09fb6cfba98f82c1ec4fecf80f77
	tree f5f30cb9c6010e671e3ac960201a3689134f8043
	parent b1ccd0d9162b35c68989d37d9c4f3295b94b096b
	author kysnail <TracingLife@gmail.com> 1339793203 +0800
	committer kysnail <TracingLife@gmail.com> 1339793203 +0800

	    1. 虚拟终端使用技巧；2. bash 使用技巧。

## commit 对象详解
一个 commit 对象有以下几个部分组成：

**tree**

	a tree: The SHA1 name of a tree object (as defined below), representing the contents of a direcotry at a certain
	point in time.

**parent(s)**

	parent(s): The SHA1 name of some number of commits which represent the immediately previous step(s) in the history
	of the project. The example above has one parent; merge commits have more than one.
	-----------------------------------------------------------------------------------------------------------
	kysnail@mydebianwork:ch01$ git show -s --pretty=raw c1421c602e14011ec31618dc8be333dedf46ff27
	commit c1421c602e14011ec31618dc8be333dedf46ff27
	tree 450737d813fb553879d527a32032fdbe226439bb
	parent 870f4338fbb6678de286d3cb7509b1f599aab38e
	parent 85bdaa669e3fe56586337c26286b0ddced8a3c1b
	author kysnail <lifeofprogrammer@gmail.com> 1339035495 +0800
	committer kysnail <lifeofprogrammer@gmail.com> 1339035495 +0800

	    Merge branch 'master' of github.com:kysnail/linuxcode
	-----------------------------------------------------------------------------------------------------------
	A commit with no parents is called a "root" commit, and represents the initial revision of a project. Each
	project must have at least one root. A project can also have multiple roots, though that isn't common (or
	necessaryily a good idea).

**author**

	an author: The name of the persion responsible for this change, together with its date.

**committer**

	a committer: The name of the person who actually created the commit, with the date it was done. This may be
	different from the author; for example, if the author wrote a patch ane emailed it to another person who
	used the patch to create the commit.

**comment**

	a comment describing this commit.

## 需要注意的问题
一个提交(commit)本身并没有包括任何信息来说明其做了哪些修改; 所有的修改(changes)都是通过与父提交(parents)的内容比较而得出的. 值得一提的是, 尽管git可以检测到文件内容不变而路径改变的情况, 但是它不会去显式(explicitly)的记录文件的更名操作.　(你可以看一下 git diff 的 -M　参数的用法)

一般用 git commit 来创建一个提交(commit), 这个提交(commit)的父对象一般是当前分支(current HEAD),　同时把存储在当前索引(index)的内容全部提交.





#Chapter 1 - Getting Started

## Installing Ruby

    ruby -v

### Binary Distributions
基于 RPM 的 Linux 

	http://www.rpmfind.net

Debian 这样基于 dpkg 的Linux

	# apt-get install ruby1.8
	or
	# apt-cache search ruby interpreter

对于 Windows 用户

	http://rubyinstaller.rubyforge.org

### Building Ruby from Source
1. 下载源码 [ruby-lang](http://www.ruby-lang.org)

	三种格式
	1. Tarball 格式的稳定版（stable release）(推荐)
	2. 稳定版快照（stable snapshot）
	3. Nightly 开发版快照（nightly development snapshot）

如果你打算经常下载上面提到的两种快照之一，那么直接订阅源码库（source repository）更方便。

2. 解压源码

	# tar xzf snapshot.tar.gz

这回安装 Ruby 源代码树（source tree）到 ruby/ 子目录中。在那个目录中可以找到一个名为 README 的文件，它详细解释了安装过程。总的来说，在基于 POSIX 的系统上编译 Ruby，使用的 4 个命令与编译大多数开放源代码程序所使用的命令相同：

	# ./configure && make && make test && make install

也可以在别的环境上（包括 Windows）编译 Ruby，还需要使用一个像 cygwin 这样的 POSIX 模拟环境，或者使用自带的编译器——参照发行版 win32 子目录中的 README.win32 。

## Running Ruby
同 Python 一样，有两种方式运行 Ruby：

	1. 以交互的方式输入代码直接执行；
	2. 先创建程序文件，然后再运行。

如果你想了解 Ruby 的源码，可以用下面的方法检出源码

	The Very Latest Ruby
	
	这本书发行的时候，估计 Ruby 还是在用 CVS 做版本管理工具。
	CVS Adress: http://www.cvshome.org/

	Check Out
	# cvs -z4 -d :pserver:anonymous@cvs.ruby-lang.org:/src login
	(Logging in to anonymous@cvs.ruby-lang.org)
	CVS password: ENTER
	# cvs -z4 -d :pserver:anonymous@cvs.ruby-lang.org/src checkout ruby 

	完整的源代码树（包含开发者所作的最新改动）将会被拷贝到你的本地机器上的 ruby 子目录。

	这个命令将会导出源代码开发树的主分支。如果你想导出 Ruby 1.8 分支，在第二个命令的 checkout 后面加入 -r ruby_1_8。

	如果你想用 CVSup 镜像工具（可以从 http://www.cvsup.org 自由获得），你可以从 ruby-lang 的网站 http://cvs.ruby-lang/cvsup 上
	找到 Ruby 的 supfiles 。	

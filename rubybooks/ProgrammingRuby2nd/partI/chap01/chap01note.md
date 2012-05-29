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

	在我的实验机器上 
    
    [root@Fedora14 ~]# uname -a
    Linux Fedora14 2.6.35.6-45.fc14.x86_64 #1 SMP Mon Oct 18 23:57:44 UTC 2010 x86_64 x86_64 x86_64 GNU/Linux
    [root@Fedora14 ~]# ruby
    Command not found. Install package 'ruby' to provide command 'ruby'? [N/y] 
    
     * Running.. 
     * Resolving dependencies.. 
    The following packages have to be updated:
     ruby-libs-1.8.7.352-1.fc14.x86_64	Libraries necessary to run Ruby
    Proceed with changes? [N/y] The transaction did not proceed.
    Failed to install packages: user declined simulation
    [root@Fedora14 ~]# ruby
    Command not found. Install package 'ruby' to provide command 'ruby'? [N/y] 
     * Running.. 
    
     * Resolving dependencies.. 
    The following packages have to be updated:
     ruby-libs-1.8.7.352-1.fc14.x86_64	Libraries necessary to run Ruby
    Proceed with changes? [N/y] The transaction did not proceed.
    Failed to install packages: user declined simulation
    [root@Fedora14 ~]# yum install ruby
    Loaded plugins: langpacks, presto, refresh-packagekit
    Adding en_US to language list
    Setting up Install Process
    Resolving Dependencies
    --> Running transaction check
    ---> Package ruby.x86_64 0:1.8.7.352-1.fc14 set to be installed
    --> Processing Dependency: ruby-libs(x86-64) = 1.8.7.352-1.fc14 for package: ruby-1.8.7.352-1.fc14.x86_64
    --> Running transaction check
    ---> Package ruby-libs.x86_64 0:1.8.7.352-1.fc14 set to be updated
    --> Finished Dependency Resolution
    
    Dependencies Resolved
    
    ================================================================================================================================================
     Package                          Arch                          Version                                    Repository                      Size
    ================================================================================================================================================
    Installing:
     ruby                             x86_64                        1.8.7.352-1.fc14                           updates                        346 k
    Updating for dependencies:
     ruby-libs                        x86_64                        1.8.7.352-1.fc14                           updates                        1.9 M
    
    Transaction Summary
    ================================================================================================================================================
    Install       1 Package(s)
    Upgrade       1 Package(s)
    
    Total download size: 2.2 M
    Is this ok [y/N]: y
    Downloading Packages:
    Setting up and reading Presto delta metadata
    Processing delta metadata
    Download delta size: 305 k
    ruby-libs-1.8.7.302-1.fc14_1.8.7.352-1.fc14.x86_64.drpm                                                                  | 305 kB     00:05     
    Finishing rebuild of rpms, from deltarpms
    <delta rebuild>                                                                                                          | 1.9 MB     00:04     
    Presto reduced the update size by 85% (from 1.9 M to 305 k).
    Package(s) data still to download: 346 k
    ruby-1.8.7.352-1.fc14.x86_64.rpm                                                                                         | 346 kB     00:05     
    Running rpm_check_debug
    Running Transaction Test
    Transaction Test Succeeded
    Running Transaction
      Updating       : ruby-libs-1.8.7.352-1.fc14.x86_64                                                                                        1/3 
      Installing     : ruby-1.8.7.352-1.fc14.x86_64                                                                                             2/3 
      Cleanup        : ruby-libs-1.8.7.302-1.fc14.x86_64                                                                                        3/3 
    
    Installed:
      ruby.x86_64 0:1.8.7.352-1.fc14                                                                                                                
    
    Dependency Updated:
      ruby-libs.x86_64 0:1.8.7.352-1.fc14                                                                                                           
    
    Complete!

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

### Interactive Ruby
同 Python 一样，只需要在 shell 下执行 `ruby` 命令既可以进入 ruby 的交互执行环境中。

	[root@Fedora14 ~]# ruby
	puts "Hello, World!"    	==> puts 表达式 （等同于 Python 中的 print）
	^D							==> 文件结束符
	Hello, World!
	[root@Fedora14 ~]# 

	^ + D ==> 退出交互执行环境。

可以发现，这种执行方式很麻烦，必须每次输入 `^D` 才可以看到对应的执行结果。

我想如果 ruby 只有上面这种交互执行方式，也就不会有现在 ruby 的火爆了。通常大家会使用 `irb (Interactive Ruby)` 这个 Ruby Shell 进行交互执行。它的功能包括：

  * command-line history
  * line-editing
  * job control

需要注意通常 `irb` 环境也需要单独安装，这点不如 Python 爽。

    [root@Fedora14 ~]# irb
    Command not found. Similar command is: 'erb'
    [root@Fedora14 ~]# 
    [root@Fedora14 ~]# yum install irb
    Loaded plugins: langpacks, presto, refresh-packagekit
    Adding en_US to language list
    Setting up Install Process
    Resolving Dependencies
    --> Running transaction check
    ---> Package ruby-irb.noarch 0:1.8.7.352-1.fc14 set to be installed
    --> Finished Dependency Resolution
    
    Dependencies Resolved
    
    ================================================================================================================================================
     Package                          Arch                           Version                                  Repository                       Size
    ================================================================================================================================================
    Installing:
     ruby-irb                         noarch                         1.8.7.352-1.fc14                         updates                         305 k
    
    Transaction Summary
    ================================================================================================================================================
    Install       1 Package(s)
    
    Total download size: 305 k
    Installed size: 1.0 M
    Is this ok [y/N]: y
    Downloading Packages:
    Setting up and reading Presto delta metadata
    Processing delta metadata
    Package(s) data still to download: 305 k
    ruby-irb-1.8.7.352-1.fc14.noarch.rpm                                                                                                                                               | 305 kB     00:05     
    Running rpm_check_debug
    Running Transaction Test
    Transaction Test Succeeded
    Running Transaction
      Installing     : ruby-irb-1.8.7.352-1.fc14.noarch                                                                                                                                                   1/1 
    
    Installed:
      ruby-irb.noarch 0:1.8.7.352-1.fc14                                                                                                                                                                      
    
    Complete
    [root@Fedora14 ~]# irb
    irb(main):001:0> 

一旦启动 irb ，就可以键入 Ruby 代码了。

    [root@Fedora14 ~]# irb
    irb(main):001:0> def sum(n1, n2)
    irb(main):002:1> n1 + n2
    irb(main):003:1> end
    => nil
    irb(main):004:0> sum(3, 4)
    => 7
    irb(main):005:0> sum("cat", "dog")
    => "catdog"
    irb(main):006:0> quit
    [root@Fedora14 ~]# 

可以发现一个细节， `n1 + n2` 的逻辑关系并不需要像 Python 那样通过缩进表现出来，这点需要注意。



	一定要注意最上面的那种交互式执行方式与 `irb` 这种方式的区别。





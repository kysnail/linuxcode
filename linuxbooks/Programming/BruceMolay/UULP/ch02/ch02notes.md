# 第 2 章 - 用户、文件操作与联机帮助：编写 who 命令

**概念与技巧**

 * 联机帮助的作用与使用方法
 * Unix 的文件操作函数：open、read、write、lseek、close
 * 文件的建立与读写
 * 文件描述符
 * 缓冲：用户级的缓冲与内核级的缓冲
 * 内核模式、用户模式和系统调用的代价
 * Unix 表示时间的方法与时间格式间的转换
 * 借助 utmp 文件来列出已登录的用户
 * 系统调用中的错误检测与处理

**相关的系统调用**

 * open、read、write、creat、lseek、close
 * perror

**相关命令**

 * man
 * who
 * cp
 * login

## 2.2 关于命令 who
本章的第一个程序通过对以下 3 个问题的解答来学习 who 命令：

 1. who 命令能做些什么？
 2. who 命令是如何工作的？
 3. 如何编写 who？

**命令也是程序**
在 Unix 系统中增加新的命令是一件很容易的事。把程序的可执行文件放到以下任意一个目录就可以了：

	/bin
	/usr/bin
	/usr/local/bin

## 2.3 问题 1 ：who 命令能做些什么

	==$ who
	zhou		tty1         2012-08-27 12:19 (:0)
	zhou 		pts/1        2012-08-31 10:19 (:0.0)
	kang		pts/2        2012-08-31 13:46 (kang-pc)
	kang		pts/4        2012-08-28 09:12 (:12.0)
	kang		pts/7        2012-08-28 10:07 (:12.0)
	kang		pts/8        2012-08-29 15:01 (:12.0)
	liu   		pts/3        2012-08-30 13:26 (:11.0)
	liu   		pts/11       2012-08-30 13:25 (:11.0)
	luru   		pts/13       2012-08-31 10:24 (:14.0)
	kang		pts/0        2012-08-31 13:44 (kang-pc)
	liru   		pts/10       2012-08-31 09:08 (:14.0)

每一行代表一个已经登录的用户，第 1 列是用户名，第 2 列是终端名，第 3 列是登录时间，第 4 列是用户的登录地址，某些版本的 who 命令在默认状态下不给出第 4 列的内容。

**阅读手册**
Unix 的联机帮助分为很多节。

	第 1 小节中是关于用户命令的帮助；
	第 2 小节中是关于系统调用的帮助；
	第 5 小节中是关于配置文件的帮助；

**who 命令的其他 3 种形式**

 * who am i
 * who am I
 * whoami

## 2.4 问题 2： who 命令是如何工作的
学习 Unix 系统编程的好处在于，最权威的资料，系统都已经提供过了。你只需要学会如何在 Unix 中获取这些资料的技巧即可。

**从 Unix 中学习 Unix**

以下 4 项技巧会有助于你的学习：

 * 阅读联机帮助
 * 搜索联机帮助
 * 阅读 .h 文件
 * 从参阅部分（SEE ALSO）得到启示

### 阅读联机帮助

	man who

### 搜索联机帮助

	man -k utmp
	man 4 utmp 
	
### 阅读 .h 文件
从 utmp 的联机帮助中可以知道，utmp 中的数据结构定义在 `/usr/include/utmp.h` 中。

	在 Unix 系统中，大多数的头文件都存放在 /usr/include 这个目录里，当 C 语言编译器在源程序中发现如下的定义：
	
	#include <stdio.h>

	它会到 /usr/include 中寻找相应的头文件。

最主要的是查看这里的 utmp 结构，查看过程中一定要注意被标记为

	兼容 - compatibility 

的行，这种行更可能出现平台差异。

**who 的工作原理**

	
	             打开 utmp

	     *-----> 读取记录-------*
	     |                      |
	     *------ 显示记录       |
	                            |
	             关闭utmp <-----*

通过阅读 who 和 utmp 的联机帮助，以及头文件 `/usr/include/utmp.h`，可以知道 who 的工作原理，who 通过读文件来获得需要的信息，而每个登录的用户在文件中都有对应的记录。

文件中的结构数组存放登录用户的信息，所以直接的想法就是把记录一个一个地读出并显示出来，是不是就这么简单呢？

虽然没有看过 who 的源代码，但从联机帮助中可以了解 who 要完成的功能以及实现原理，所涉及的数据结构的信息也可以从头文件中获取。接下来是实践的时候了。
		
## 2.5 问题3：如何编写 who
通过分析可以确认，在编写 who 程序时只有两件事情是要做的：

 * 从文件中读取数据结构
 * 将结构中的信息以合适的形式显示出来

### 2.5.1 问题：如何从文件中读取数据结构
可以调用 `getc` 和 `fgets` 函数从文件中读字符或字符串，但是如何读出数据结构中的信息呢？当然可以用 getc 逐个字节地读取，但这样太繁琐，而且效率很低。

	要找一种可以一次读出整个数据结构的方法。

这时就要向 man 寻求帮助，但 man 的 `-k` 选项（根据关键字查找）只支持一个关键字的查找。为了更方便的查到想要的信息，可以使用下面的命令：

	man -k file | grep read
	-----------------------
	不过在我的测试机上 fedora16，上面的命令无法找到 read 函数。

	man 2 read
	----------
	同样也会提示无法找到。
	No manual entry for read in section 2

对于 read 函数，需要注意下面的内容：

	On error, -1 is returned, and errno is set appropriately. In this case it is left unspecified whether the file position (if any) changes.

这个系统调用可以将文件中一定数目的字节读入一个缓冲区，因为每次都要读入一个数据结构，所以要用 `sizeof(struct utmp)` 来指定每次读入的字节书。read 函数需要一个文件描述符作为输入参数，如何得到文件描述符呢？

	在 read 联机帮助的最后部分有以下描述：

	RELATED INFORMATION(called SEE ALSO in some versions)
	-----------------------------------------------------
	在我的测试机上，已没有了这个信息。

连着几个都无法找到书上给出的那些知道信息，看来需要重新思考一下问题的症结了。经过查证，可能是相应的 manpages 没有安装。

	In Fedora16
	-----------

	Install man-pages
	-----------------
	[root@fedora16 kangyushi]# yum install man-pages
	Loaded plugins: aliases, fastestmirror, langpacks, merge-conf, presto, refresh-packagekit, refresh-updatesd
	Repository google-chrome is listed more than once in the configuration
	Loading mirror speeds from cached hostfile
	 * fedora: mirrors.163.com
	 * updates: www.ftp.ne.jp
	Resolving Dependencies
	--> Running transaction check
	---> Package man-pages.noarch 0:3.32-14.fc16 will be installed
	--> Finished Dependency Resolution

	Dependencies Resolved

	==================================================================================================
	 Package                           Arch           Version             Repository          Size
	==================================================================================================
	Installing:
	 man-pages                         noarch         3.32-14.fc16        fedora              4.9 M

	Transaction Summary
	==================================================================================================
	Install  1 Package

	Total download size: 4.9 M
	Installed size: 4.9 M
	Is this ok [y/N]: y
	Downloading Packages:
	man-pages-3.32-14.fc16.noarch.rpm                                               | 4.9 MB     01:10
	Running Transaction Check
	Running Transaction Test
	Transaction Test Succeeded
	Running Transaction
	  Installing : man-pages-3.32-14.fc16.noarch                                                                                                                                                             1/1
	yum-updatesd not on the bus
	  Verifying  : man-pages-3.32-14.fc16.noarch                                                                                                                                                             1/1

	Installed:
	  man-pages.noarch 0:3.32-14.fc16

	Complete!

	---------------------------------------------------------------------------------------------------
	mandb - create or update the manual page index caches
	-----------------------------------------------------
	[root@fedora16 kangyushi]# man 2 page		<---- 仍然提示没有相应的信息。
	No manual entry for page in section 2
	[root@fedora16 kangyushi]# mandb
	Purging old database entries in /usr/share/man...
	Processing manual pages under /usr/share/man...
	Updating index cache for path `/usr/share/man/man3'. Wait...mandb: warning: /usr/share/man/man3/Coro::Intro.3pm.gz: whatis parse for Coro::Intro(3pm) failed
	Updating index cache for path `/usr/share/man/man1'. Wait...mandb: warning: /usr/share/man/man1/faxformat.1.gz: whatis parse for faxformat(1) failed
	mandb: warning: /usr/share/man/man1/mprof-report.1.gz: whatis parse for mprof-report(1) failed
	Updating index cache for path `/usr/share/man/man8'. Wait...done.
	Checking for stray cats under /usr/share/man...
	Checking for stray cats under /var/cache/man...
	Purging old database entries in /usr/share/man/pt_BR...
	Processing manual pages under /usr/share/man/pt_BR...
	Purging old database entries in /usr/share/man/oc...
	Processing manual pages under /usr/share/man/oc...
	Purging old database entries in /usr/share/man/ar...
	Processing manual pages under /usr/share/man/ar...
	Purging old database entries in /usr/share/man/lv...
	Processing manual pages under /usr/share/man/lv...
	Purging old database entries in /usr/share/man/te...
	Processing manual pages under /usr/share/man/te...
	Purging old database entries in /usr/share/man/zh_HK...
	Processing manual pages under /usr/share/man/zh_HK...
	Purging old database entries in /usr/share/man/it...
	Processing manual pages under /usr/share/man/it...
	Purging old database entries in /usr/share/man/de.UTF-8...
	Processing manual pages under /usr/share/man/de.UTF-8...
	Purging old database entries in /usr/share/man/ast...
	Processing manual pages under /usr/share/man/ast...
	Purging old database entries in /usr/share/man/cs...
	Processing manual pages under /usr/share/man/cs...
	Purging old database entries in /usr/share/man/vi...
	Processing manual pages under /usr/share/man/vi...
	Purging old database entries in /usr/share/man/fa...
	Processing manual pages under /usr/share/man/fa...
	Purging old database entries in /usr/share/man/sl...
	Processing manual pages under /usr/share/man/sl...
	Purging old database entries in /usr/share/man/da...
	Processing manual pages under /usr/share/man/da...
	Purging old database entries in /usr/share/man/fo...
	Processing manual pages under /usr/share/man/fo...
	Processing manual pages under /usr/share/man/en...
	Updating index cache for path `/usr/share/man/en/man5'. Wait...done.
	Checking for stray cats under /usr/share/man/en...
	Checking for stray cats under /var/cache/man/en...
	Purging old database entries in /usr/share/man/tr...
	Processing manual pages under /usr/share/man/tr...
	Purging old database entries in /usr/share/man/ug...
	Processing manual pages under /usr/share/man/ug...
	Purging old database entries in /usr/share/man/sr...
	Processing manual pages under /usr/share/man/sr...
	Purging old database entries in /usr/share/man/he...
	Processing manual pages under /usr/share/man/he...
	Purging old database entries in /usr/share/man/pt...
	Processing manual pages under /usr/share/man/pt...
	Purging old database entries in /usr/share/man/ro...
	Processing manual pages under /usr/share/man/ro...
	Purging old database entries in /usr/share/man/en_AU...
	Processing manual pages under /usr/share/man/en_AU...
	Purging old database entries in /usr/share/man/pl.UTF-8...
	Processing manual pages under /usr/share/man/pl.UTF-8...
	Purging old database entries in /usr/share/man/sv...
	Processing manual pages under /usr/share/man/sv...
	Purging old database entries in /usr/share/man/th...
	Processing manual pages under /usr/share/man/th...
	Purging old database entries in /usr/share/man/nn...
	Processing manual pages under /usr/share/man/nn...
	Purging old database entries in /usr/share/man/io...
	Processing manual pages under /usr/share/man/io...
	Purging old database entries in /usr/share/man/fr...
	Processing manual pages under /usr/share/man/fr...
	Purging old database entries in /usr/share/man/fi...
	Processing manual pages under /usr/share/man/fi...
	Purging old database entries in /usr/share/man/es...
	Processing manual pages under /usr/share/man/es...
	Purging old database entries in /usr/share/man/bg...
	Processing manual pages under /usr/share/man/bg...
	Purging old database entries in /usr/share/man/ps...
	Processing manual pages under /usr/share/man/ps...
	Purging old database entries in /usr/share/man/sk...
	Processing manual pages under /usr/share/man/sk...
	Purging old database entries in /usr/share/man/ta...
	Processing manual pages under /usr/share/man/ta...
	Purging old database entries in /usr/share/man/bn...
	Processing manual pages under /usr/share/man/bn...
	Purging old database entries in /usr/share/man/lt...
	Processing manual pages under /usr/share/man/lt...
	Purging old database entries in /usr/share/man/et...
	Processing manual pages under /usr/share/man/et...
	Purging old database entries in /usr/share/man/ko...
	Processing manual pages under /usr/share/man/ko...
	Purging old database entries in /usr/share/man/ca@valencia...
	Processing manual pages under /usr/share/man/ca@valencia...
	Purging old database entries in /usr/share/man/el...
	Processing manual pages under /usr/share/man/el...
	Purging old database entries in /usr/share/man/gl...
	Processing manual pages under /usr/share/man/gl...
	Purging old database entries in /usr/share/man/uk...
	Processing manual pages under /usr/share/man/uk...
	Purging old database entries in /usr/share/man/bs...
	Processing manual pages under /usr/share/man/bs...
	Purging old database entries in /usr/share/man/zh_CN...
	Processing manual pages under /usr/share/man/zh_CN...
	Updating index cache for path `/usr/share/man/zh_CN/man1'. Wait...mandb: warning: /usr/share/man/zh_CN/man1/testprns.1.gz: whatis parse for testprns(1) failed
	Updating index cache for path `/usr/share/man/zh_CN/man8'. Wait...done.
	Checking for stray cats under /usr/share/man/zh_CN...
	Checking for stray cats under /var/cache/man/zh_CN...
	Purging old database entries in /usr/share/man/cy...
	Processing manual pages under /usr/share/man/cy...
	Purging old database entries in /usr/share/man/pl...
	Processing manual pages under /usr/share/man/pl...
	Purging old database entries in /usr/share/man/eu...
	Processing manual pages under /usr/share/man/eu...
	Purging old database entries in /usr/share/man/ja...
	Processing manual pages under /usr/share/man/ja...
	Purging old database entries in /usr/share/man/de...
	Processing manual pages under /usr/share/man/de...
	Purging old database entries in /usr/share/man/sq...
	Processing manual pages under /usr/share/man/sq...
	Purging old database entries in /usr/share/man/ru...
	Processing manual pages under /usr/share/man/ru...
	Purging old database entries in /usr/share/man/en_GB...
	Processing manual pages under /usr/share/man/en_GB...
	Purging old database entries in /usr/share/man/hr...
	Processing manual pages under /usr/share/man/hr...
	Purging old database entries in /usr/share/man/fr.UTF-8...
	Processing manual pages under /usr/share/man/fr.UTF-8...
	Purging old database entries in /usr/share/man/hu...
	Processing manual pages under /usr/share/man/hu...
	Purging old database entries in /usr/share/man/ms...
	Processing manual pages under /usr/share/man/ms...
	Purging old database entries in /usr/share/man/id...
	Processing manual pages under /usr/share/man/id...
	Purging old database entries in /usr/share/man/ca...
	Processing manual pages under /usr/share/man/ca...
	Purging old database entries in /usr/share/man/nb...
	Processing manual pages under /usr/share/man/nb...
	Purging old database entries in /usr/share/man/zh_TW...
	Processing manual pages under /usr/share/man/zh_TW...
	Purging old database entries in /usr/share/man/nl...
	Processing manual pages under /usr/share/man/nl...
	Purging old database entries in /usr/share/man/ml...
	Processing manual pages under /usr/share/man/ml...
	Purging old database entries in /usr/share/man/ku...
	Processing manual pages under /usr/share/man/ku...
	Purging old database entries in /usr/share/man/eo...
	Processing manual pages under /usr/share/man/eo...
	Purging old database entries in /usr/local/share/man...
	Processing manual pages under /usr/local/share/man...
	24 man subdirectories contained newer manual pages.
	4354 manual pages were added.
	0 stray cats were added.
	0 old database entries were purged.

经过以上的操作后，再次执行上面的操作例子，就都正常了。前面还试图安装了中文版的 manpage ，用后不推荐。如果只是临时更改 man page 的语言，则推荐使用

	export LANG=xxx

的方式，更改当前 shell 的语言即可。

### 2.5.2 答案：使用 open、read 和 close

**open** - 打开一个文件：

	这个系统调用在进程和文件之间建立一条连接，这个连接被称为文件描述符，它就像一条由进程通向内核的管道。

使用 open 的过程中，需要注意下面的内容：

	1. 打开文件是内核提供的服务，如果在打开过程中内核检测到任何错误，这个系统调用就会返回 -1 。
	2. 当一个文件已经被打开，是否允许再次打开呢？当然是允许的，否则两个用户就无法同时使用 who 命令了。
	3. 如果文件被顺利打开，内核就会返回一个正整数的值，这个数值就叫做文件描述符。

刚才讲过，打开文件会建立进程和文件之间的连接，文件描述符就是用来唯一标识这个连接的，如果同时打开好几个文件，它们所对应的文件描述符是不同的，如果将一个文件打开多次，对应的文件描述符也不相同。

还有就是最重要的一点：

	必须通过文件描述符对文件进行操作。

**read** - 从文件读取数据 ：

	ssize_t numberead = read(int fd, void *buf, size_t qty)

`read` 这个系统调用请求内核从 fd 所指定的文件中读取 qty 字节的数据，存放到 buf 所指定的内存空间中内核如果成功地读取了数据，就返回所读取的字节数目，否则返回 -1 。

**close** - 关闭文件：

	int result = close(int fd)

`close` 这个系统调用会关闭进程和文件 fd 之间的连接，如果关闭的过程中出现错误，close 返回 -1 。

### who1.c
在我的测试机（Fedora16）上，`utmp.h` 文件存放在

	/usr/include/bits/utmp.h
	-----------------------
	/* The structure describing an entry in the user accounting database.  */
	struct utmp
	{
	  short int ut_type;		/* Type of login.  */
	  pid_t ut_pid;			/* Process ID of login process.  */
	  char ut_line[UT_LINESIZE];	/* Devicename.  */
	  char ut_id[4];		/* Inittab ID.  */
	  char ut_user[UT_NAMESIZE];	/* Username.  */
	  char ut_host[UT_HOSTSIZE];	/* Hostname for remote login.  */
	  struct exit_status ut_exit;	/* Exit status of a process marked
					   as DEAD_PROCESS.  */
	/* The ut_session and ut_tv fields must be the same size when compiled
	   32- and 64-bit.  This allows data files and shared memory to be
	   shared between 32- and 64-bit applications.  */
	#if __WORDSIZE == 64 && defined __WORDSIZE_COMPAT32
	  int32_t ut_session;		/* Session ID, used for windowing.  */
	  struct
	  {
	    int32_t tv_sec;		/* Seconds.  */
	    int32_t tv_usec;		/* Microseconds.  */
	  } ut_tv;			/* Time entry was made.  */
	#else
	  long int ut_session;		/* Session ID, used for windowing.  */
	  struct timeval ut_tv;		/* Time entry was made.  */
	#endif

	  int32_t ut_addr_v6[4];	/* Internet address of remote host.  */
	  char __unused[20];		/* Reserved for future use.  */
	};

	/* Backwards compatibility hacks.  */
	#define ut_name		ut_user
	#ifndef _NO_UT_TIME
	/* We have a problem here: `ut_time' is also used otherwise.  Define
	   _NO_UT_TIME if the compiler complains.  */
	# define ut_time	ut_tv.tv_sec
	#endif
	#define ut_xtime	ut_tv.tv_sec
	#define ut_addr		ut_addr_v6[0]

执行的结果，查看源代码：

	src/who1.c
	----------
	==$ ./who1
	reboot   ~        1346041151 (3.4.7-1.fc16.x86_64)
	runlevel ~        1346041169 (3.4.7-1.fc16.x86_64)
	sunxuebi tty1     1346041185 (:0)
	sunxuebi pts/0    1346320491 ()
	sunxuebi pts/1    1346379541 (:0.0)
	kangyush pts/2    1346497537 (kangyushi-pc.xause.com)
		 pts/3    1346304391 ()
		 pts/4    1346069090 ()
		 pts/5    1346068862 ()
		 pts/6    1346069174 ()
		 pts/7    1346080626 ()
	kangyush pts/4    1346116324 (:12.0)
		 pts/1    1346305086 ()
	kangyush pts/7    1346119624 (:12.0)
		 pts/8    1346217940 ()
	kangyush pts/8    1346223667 (:12.0)
	kangyush pts/9    1346143668 ()
	lipeng   pts/3    1346304395 (:11.0)
		 pts/9    1346306427 ()
		 pts/10   1346322577 ()
		 pts/11   1346246264 ()
		 pts/12   1346390743 ()
	lipeng   pts/11   1346304354 (:11.0)
	liurui   pts/13   1346379896 (:14.0)
	liurui   pts/14   1346305938 ()
		 pts/14   1346394415 ()
	kangyush pts/0    1346488648 (kangyushi-pc.xause.com)
	liurui   pts/10   1346375337 (:14.0)
	sunxuebi pts/12   1346400318 (:0.0)

遗留的问题有：

	1. 如何消除空白记录
	2. 正确显示登录时间
		ut_time 这个字段在头文件中被定义为 time_t 类型，但还不知道 time_t 类型的数据如何处理。
	
### who2.c
针对 `who1.c` 的两个问题，继续编写 `who` 的第 2 个版本，解决问题的方法还是通过阅读联机帮助和头文件。

#### 1. 消除空白记录
系统自带的 who 命令仅列出已登录用户的信息，而刚才编写的 `who1.c` 除了列出已登录的，还会显示其他的信息，而这些都来自于 `utmp` 文件。

	实际上 utmp 包含所有终端的信息，甚至那些尚未被用到的终端的信息也会存放在 utmp 中。

所以要修改刚才的程序，做到能够区分出哪些终端对应活动的用户。一种简单的思路是：

	过滤掉那些用户名为空的记录，但这样做是有问题的，如刚才的输出中，用户名为 LOGIN 的那一行对应的是控制台，而不是一个真正的用户。
	----------------------------------------------------------------------------------------------------------------------------
	我的测试机上没有这一项！

最好的办法是能够指出某一条记录确实对应着已登录的用户。

	而这 Unix 系统也早就考虑到了。

在 `/usr/inlcude/bits/utmp.h` 中，有以下内容：

	/* Values for the `ut_type' field of a `struct utmp'.  */
	#define EMPTY		0	/* No valid user accounting information.  */

	#define RUN_LVL		1	/* The system's runlevel.  */
	#define BOOT_TIME	2	/* Time of system boot.  */
	#define NEW_TIME	3	/* Time after system clock changed.  */
	#define OLD_TIME	4	/* Time when system clock changed.  */

	#define INIT_PROCESS	5	/* Process spawned by the init process.  */
	#define LOGIN_PROCESS	6	/* Session leader of a logged in user.  */
	#define USER_PROCESS	7	/* Normal process.  */
	#define DEAD_PROCESS	8	/* Terminated process.  */

	#define ACCOUNTING	9

utmp 结构中有一个成员 `ut_type`，当它的值为 7(`USER_PROCESS`) 时，表示这是一个已经登录的用户。根据这一点，对原来的程序做以下修改，就可以消除空白行：

	show_inf(struct utmp *utbufp)
	{
		if (utbufp->ut_type != USER_PROCESS)		/* users only */
			return;
		printf("%-8.8s", utbufp->ut-name);		/* the username */
	}

#### 2. 以可读的方式显示登录时间
首先还是要寻求男人帮忙了：

	==$ man -k time | grep transform
	asctime (3)          - transform date and time to broken-down time or ASCII
	asctime_r (3)        - transform date and time to broken-down time or ASCII
	ctime (3)            - transform date and time to broken-down time or ASCII
	ctime_r (3)          - transform date and time to broken-down time or ASCII
	gmtime (3)           - transform date and time to broken-down time or ASCII
	gmtime_r (3)         - transform date and time to broken-down time or ASCII
	localtime (3)        - transform date and time to broken-down time or ASCII
	localtime_r (3)      - transform date and time to broken-down time or ASCII
	mktime (3)           - transform date and time to broken-down time or ASCII

	==$ man -k time | grep -i convert
	asctime (3p)         - convert date and time to a string
	asctime_r (3p)       - convert date and time to a string
	ctime (3p)           - convert a time value to a date and time string
	ctime_r (3p)         - convert a time value to a date and time string
	function::ctime (3stap) - Convert seconds since epoch into human readable date/time string
	function::tz_ctime (3stap) - Convert seconds since epoch into human readable date/time string, with local time zone
	getdate (3)          - convert a date-plus-time string to broken-down time
	getdate (3p)         - convert user format date and time
	getdate_err (3)      - convert a date-plus-time string to broken-down time
	getdate_err (3p)     - convert user format date and time
	getdate_r (3)        - convert a date-plus-time string to broken-down time
	globaltime (1)       - International multiclock timeconverter for the Xfce Desktop Environment. It is part of Orage
	gmtime (3p)          - convert a time value to a broken-down UTC time
	gmtime_r (3p)        - convert a time value to a broken-down UTC time
	localtime (3p)       - convert a time value to a broken-down local time
	localtime_r (3p)     - convert a time value to a broken-down local time
	mktime (3p)          - convert broken-down time into time since the Epoch
	strftime (3p)        - convert date and time to a string
	strptime (3)         - convert a string representation of time to a time tm structure
	tz_convert (1)       - Timezone converter from operating system tz format into libical format used by Orage and several other calander tools.
	wcsftime (3p)        - convert date and time to a wide-character string

很多记录都涉及到 `/usr/include/time.h` 这个头文件，这里面有很多有用的信息。

	注：
	---
	在我的测试机上，情况要复杂的多！

##### (1) Unix 存储时间的方式：`time_t` 数据类型
Unix 中时间是用一个整数来表示的，它的数值是从 1970 年 1 月 1 日 0 时开始所经过的秒数，在头文件 `time.h` 中有以下内容：

	typedef long int time_t;

存储时间的结构 `time_t` 实际上就是 `long int` 。

##### (2) 将 `time_t` 显示出来：`ctime`
`ctime` 将表示时间的整数值转换成人们日常所使用的时间形式。在联机帮助的第 3 节有 `ctime` 的详细说明：

`ctime(3)` 函数要输入一个指向 `time_t` 的指针，返回的时间字符串类似于以下格式：

	Wed Jun 30 21:49:08 1993'n
	    ^^^^^^^^^^^^^^^
	----------------------------
	看到这里的时间了吧，1993 啊！
	----------------------------
	测试程序的 format string 为 "%12.12s" 仅显示 12 个字符，也就是
	----------------------------
	Jun 30 21:49

注意：并不是所有的字符串内容都需要，需要的是用 `^` 标识出来的部分，接下来就很容易处理了，将 `ctime` 返回的字符串从第 4 个字符看是，输出 12 个字符：

	printf("%12.12s", ctime(&t) + 4)
	---------------------------------
	这是我第一次见 printf 中的参数可以这样用，可能也正好符合 ctime 函数的含义吧，它返回

		 char *ctime(const time_t *timep);

	字符指针，作为指针当然可以进行 +4 的偏移操作了。
	-----------------------------------------------
	另一个需要注意的问题是， %12.12.s 的写法。

	1. 先看一下 placeholder 的含义：

		Format placeholder
		------------------
		Formatting takes place via placeholders within the format string.

		Syntax
		------
		The syntax for a format placeholder is 

			%[parameter][flags][width][.precision][length]type

		more accurate one.

			%[flag][min width][precision][length modifier][conversion specifier]

	2. 分析两个 12 的含义：
	
		第一个 12 表示最小宽度，也就是说，无论后面的字符串有多短，输出的结果最少要占用 12 个字符位。
		第二个 12 表示精度，即如果字符串的长度超过了 12 个，则需要做截取处理。

	3. Refs

		http://www.cprogramming.com/tutorial/printf-format-strings.html
	
##### (3) 把刚才学的两点综合起来
现在明白了如何消除空白记录和如何正确地显示 `ut_time` 中的时间值，可以着手重新编写 `who2.c` 如下：

	Notes:
	------
	鉴于这本书实在是有些年头了，很多文件位置的指向也都不对了。

	/etc/utmp	->	/var/run/utmp or /var/log/wtmp or /var/log/btmp

	man -k file | grep utmp    ->     man utmp    -> FILES
							       /var/run/utmp
							       /var/log/wtmp

这里为了与系统 who 命令进行对比，先将 `SHOWHOST` 选项关闭：

	/*#define SHOWHOST*/

输出结果：

	sunxuebi tty1     Sep  5 16:18
	sunxuebi pts/0    Sep  5 16:18
	lipeng   pts/2    Sep 11 19:04
	kangyush pts/3    Sep  5 16:19
	kangyush pts/4    Sep  5 16:20
	liurui   pts/5    Sep  6 09:35
	sunxuebi pts/1    Sep  6 14:50
	kangyush pts/7    Sep 13 16:56
	kangyush pts/8    Sep  7 09:44
	kangyush pts/10   Sep 13 15:41
	kangyush pts/6    Sep 11 14:25
	sunxuebi pts/9    Sep 13 14:55

这里的 who 只列出了 3 个字段：

 * 用户名
 * 终端类型
 * 登录时间

有些版本的 who 还会列出用户所在主机的信息，这个功能在 who2 中通过与编译选项 SHOWHOST 控制。

### 2.5.6 回顾与展望
这一章是从这样一个简单的问题开始的：

	Unix 的 who 命令是如何工作的？
	接下来分 3 步走：

		1. 首先弄清 who 的功能；
		2. 然后通过联机帮助和头文件知道了 who 的工作原理；
		3. 最后，通过编写自己的 who 来检验对知识的掌握程度。

在这 3 步中，学习了如何使用联机帮助，如何使用头文件，了解了记录登录信息的 `utmp` 文件的结构，知道了 Unix 处理时间的方式，学会了通过相关主题来获取信息，这些知识对掌握 Unix 编程时很重要的。通过编写程序，更加深化了对知识的理解和掌握。

## 2.6 编写 cp （读和写）


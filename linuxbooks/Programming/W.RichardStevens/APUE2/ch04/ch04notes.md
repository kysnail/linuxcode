# Chapter 4 - Files and Directories

## 4.2. stat, fstat, and lstat Functions

 1. stat  -> 返回指定文件名的结构信息；
 2. fstat -> 返回指定文件描述符的结构信息；
 3. lstat -> 返回文件链接的结构信息。

## 4.3. File Types
UNIX 系统的文件类型有：

 * Regular file
 * Directory file
 * Block special file
 * Character special file
 * FIFO
 * Socket
 * Symbolic link

### Figure 4.3. Print type of file for eache command-line argument

**Execution**

    src/fig4.3.c
    gcc fig4.3.c err.c
    -----------------------------------------------------------------------------------------------------------
    ==$ ./a.out /etc/passwd /etc /dev/initctl /dev/log /dev/tty /dev/scsi/host0/bus0/target0/lun0/cd /dev/cdrom
    ./a.out: regular
    /etc/passwd: regular
    /etc: directory
    /dev/initctl: fifo
    /dev/log: socket
    /dev/tty: character special
    /dev/scsi/host0/bus0/target0/lun0/cd: lstat error: No such file or directory
    /dev/cdrom: lstat error: No such file or directory

查看 **ST_ISXXX** 宏：

    #ifndef _LINUX_STAT_H
    #define _LINUX_STAT_H
    
    #ifdef __KERNEL__
    
    #include <asm/stat.h>
    
    #endif
    
    #if defined(__KERNEL__) || !defined(__GLIBC__) || (__GLIBC__ < 2)
    
    #define S_IFMT  00170000                              <-- S_IFMT
    #define S_IFSOCK 0140000
    #define S_IFLNK	 0120000
    #define S_IFREG  0100000
    #define S_IFBLK  0060000
    #define S_IFDIR  0040000
    #define S_IFCHR  0020000
    #define S_IFIFO  0010000
    #define S_ISUID  0004000
    #define S_ISGID  0002000
    #define S_ISVTX  0001000
    
    #define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)       <-- S_ISLINK
    #define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)       <-- S_ISREG
    #define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)       <-- S_ISDIR
    #define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)       <-- S_ISCHR
    #define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)       <-- S_ISBLK
    #define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)       <-- S_ISFIFO
    #define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)      <-- S_ISSOCK
    
    #define S_IRWXU 00700
    #define S_IRUSR 00400
    #define S_IWUSR 00200
    #define S_IXUSR 00100
    
    #define S_IRWXG 00070
    #define S_IRGRP 00040
    #define S_IWGRP 00020
    #define S_IXGRP 00010
    
    #define S_IRWXO 00007
    #define S_IROTH 00004
    #define S_IWOTH 00002
    #define S_IXOTH 00001
    
    #endif

## 4.4. Set-User-ID and Set-Group-ID
本节需要注意下面这点内容：

	Because a process that is running set-user-ID to some other user usually assumes extra
	permissions, it must be written carefully.

它的意思简单来说就是，当设置了正确的标志位后，普通用户就有可能获取超越其规定权限的可能。这是为了应对诸如

	/etc/passwd
	/etc/shadow

类文件而存在的。

## 4.5 File Access Permissions
进程每次打开、创建或删除一个文件时，内核就会进行文件访问权限测试，这一点需要注意。

	The file access tests that the kernel performs each time a process open, creates, or deletes a file depend
	on the owners of the file (st_uid and st_gid), the effective IDs of the process (effective user ID and 
	effective group ID), and the supplementary group IDs of the process, if supported. The owner IDs are 
	properties of the file, whereas the two effective IDs and the supplementary group IDs are properties of 
	the process. 

## 4.6. Ownership of new Files and Directories
直观理解，那个进程创建了文件/目录，当然相应的权限模式就应该与创建进行相同了。但是对于文件的组 ID 则有不同的实现方式：

 1. The group ID of a new file can be the effective group ID of the process.
 2. The group ID of a new file can be the group ID of the directory in which the file is being created.

在 Linux 中，两种方式都可以，只需要设置相应的标志位即可。一个使用了第二种模式的例子便是：

	/var/spool/mail

## 4.7. access Function
access 函数也进行访问权限测试，但与 4.5 节所讲的 File Access Permissions 稍有不同。

access 函数是按实际用户 ID 和实际组 ID 进行访问权限测试的，相应的测试也分为 4 步。

**Execution**

	src/fig4.8.c
	gcc fig4.8.c err.c 
	--------------------------------------------------------------------------------------------------
	==$ ls -l a.out 
	-rwxr-xr-x 1 kangyushi ie2 10151 Aug 22 09:31 a.out

	==$ ./a.out a.out 
	read access OK
	open for reading OK

	==$ ls -l /etc/shadow
	---------- 1 root root 2031 Aug  2 15:51 /etc/shadow

	==$ ./a.out /etc/shadow
	access error for /etc/shadow: Permission denied
	open error for /etc/shadow: Permission denied

	==$ su                                               <-- become superuser
	Password:                                            <-- enter superuser password
	[root@fedora16 src]# ls -l a.out
	-rwxr-xr-x 1 kangyushi ie2 10151 Aug 22 09:31 a.out
	[root@fedora16 src]# ./a.out /etc/shadow             <-- 默认情况下，对于 /etc/shadow 可读
	read access OK                                       <-- 因为按照实际用户ID=进程有效用户ID来进行
	open for reading OK                                  <-- 测试的话，当前用户 ID 为 root。
	[root@fedora16 src]# chown root a.out                <-- change file's user ID to root
	[root@fedora16 src]# ls -l a.out 
	-rwxr-xr-x 1 root ie2 10151 Aug 22 09:31 a.out
	[root@fedora16 src]# chmod u+s a.out                 <-- and turn on set-user-ID bit
	[root@fedora16 src]# ls -l a.out                     <-- check owner and SUID bit
	-rwsr-xr-x 1 root ie2 10151 Aug 22 09:31 a.out       <-- 这里的 a.out 显红色背景。
	[root@fedora16 src]# exit                            <-- go back to normal user
	exit

	==$ ls -l a.out 
	-rwsr-xr-x 1 root ie2 10151 Aug 22 09:31 a.out

	==$ ./a.out /etc/shadow                              <-- 由于 set-user-ID 的作用是
	access error for /etc/shadow: Permission denied      <-- 当执行此文件时，将进程的有效用户ID设置为
	open for reading OK                                  <-- 文件所有者的用户ID(st_uid)。
	                                                     <-- 那么当前进程的实际用户ID就为root，但access
	                                                     <-- 函数会测试实际用户的访问权限，也就是 kang 
	                                                     <-- 的访问权限，那么必然 access error 。
	==$ ll
	total 24
	-rwsr-xr-x 1 root      ie2 10151 Aug 22 09:31 a.out
	-rw-r--r-- 1 kangyushi ie2  2038 Aug 20 19:34 err.c
	-rw-r--r-- 1 kangyushi ie2  1182 Aug 20 19:39 fig4.3.c
	-rw-r--r-- 1 kangyushi ie2   824 Aug 22 09:29 fig4.8.c

现实中可能会出现这种状况：

	一个进程可能已经因设置用户 ID 以超级用户权限进行，它仍可能想验证其实际用户能否访问一个给定的文件。

这时 access 就派上用场了。access 函数是按 **实际用户 ID** 和 **实际组 ID** 进行访问权限测试的。

## 4.8. umask Function
umask 刚开始接触还是比较饶人的，相关的概念很多，这个模式位，那个模式位的。先看一段我觉得对于 umask 最直观的解释吧：

	1. 我们创建文件的默认权限是怎么来的？
	2. 如何改变这个默认权限呢？
	3. umask是什么？ 
	4. 当我们登录系统之后创建一个文件总是有一个默认权限的，那么这个权限是怎么来的呢？
	---------------------------------------------------------------------------------
	这就是umask干的事情。
	umask设置了用户创建文件的默认权限，它与chmod的效果刚好相反，umask设置的是权限“补码”，而chmod设置的是文件权限码。a
	一般在/etc/profile、$ [HOME]/.bash_profile或$[HOME]/.profile中设置umask值。 

	5. 如何计算umask值？ 
	---------------------------------------------------------------------------------
	umask命令允许你设定文件创建时的缺省模式，对应每一类用户(文件属主、同组用户、其他用户)存在一个相应的umask值中的数字。
	对于文件来说，这一数字的最大值分别是6。系统不允许你在创建一个文本文件时就赋予它执行权限，必须在创建后用chmod命令增加这一权限。
	目录则允许设置执行权限，这样针对目录来说，umask中各个数字最大可以到7。 

	该命令的一般形式为：umask nnn 其中nnn为umask置000 - 777。 
	我们只要记住 umask 是从权限中“拿走”相应的位即可。 
	如：umask值为022，则默认目录权限为755，默认文件权限为644。 

还有一个比较好的解释：

	linux中的 umask 函数主要用于：在创建新文件或目录时 屏蔽掉新文件或目录不应有的访问允许权限。
	文件的访问允许权限共有9种，分别是：rwxrwxrwx
	它们分别代表：用户读 用户写 用户执行 组读 组写 组执行 其它读 其它写 其它执行

	屏蔽的规则如下：
	--------------------------------------------------------------------------------
	1. 不管屏蔽码是多少，

		·新创建的文件默认不具有可执行允可权限。

		·新创建的目录默认具有可执行允可权限。

	2. 屏蔽码的格式为八进制格式，共三个八进制数。可设置如下 002 或 022 或 ......

	3. 其中的每一个八进制数由三位表示，分别是 读 写  执行

		4  2  1

	例如 002 用二进制表示为： 0 0 0 -- 0 0 0 -- 0 1 0

		4 2 1  4 2 1  4 2 1

	4. 产生的文件为 umask 值求反后的允可权限，即

	对于文件： ~002 = 664（新创建文件所应具有的访问权限）

	对于目录： ~002 = 775（新创建目录所应具有的访问权限）

对于 umask 数值不太直观的问题， **Single UNIX Specification** 提供了符号形式的 umask 命令。

	==$ umask
	0022

	==$ umask -S
	u=rwx,g=rx,o=rx

	==$ umask 027

	==$ umask
	0027

	==$ umask -S
	u=rwx,g=rx,o=

与八进制格式不同的地方在于，符号表示方式指定了许可的权限，而非拒绝的权限。

	Unlike the octal format, the symbolic format specifies which permissions are to be allowed (i.e., clear
	in the file creation mask) instead of which ones are to be denied (i.e., set in the file creation mask)

查看下面的示例：

	==$ umask
	0022

	==$ umask -S
	u=rwx,g=rx,o=rx

	==$ umask 027

	==$ umask
	0027

	==$ umask -S
	u=rwx,g=rx,o=

**Execution**

	src/fig4.9.c
	gcc fig4.9.c err.c
	------------------
	==$ ll
	-rw------- 1 kangyushi ie2    0 Aug 24 21:14 bar
	-rw-rw-rw- 1 kangyushi ie2    0 Aug 24 21:14 foo

至于如何计算出这个结果的，强烈建议参看源代码。

## 4.9. chmod and fchmod Functions
这两个函数的作用就是用来修改文件权限位的。

	These two functions allow us to change the file access permissions for an existing file.

**Execution**

	src/fig4.12.c
	gcc fig4.12.c err.c
	-------------------
	==$ ll bar foo
	-rw------- 1 kangyushi ie2 0 Aug 24 21:25 bar
	-rw-rw-rw- 1 kangyushi ie2 0 Aug 24 21:25 foo

	==$ ll bar foo
	-rw-r--r-- 1 kangyushi ie2 0 Aug 24 21:25 bar
	-rw-rwSrw- 1 kangyushi ie2 0 Aug 24 21:25 foo	<== 这里由于 S 的设置，在终端中带有背景色

同样建议查看源码，其中有详细的解释。

这里还有一点需要注意的是， **chmod** 函数更新的只是 i 节点最近一次被更改的时间。而 **ls -l** 列出的是最后修改文件内容的时间。

	The chmod function updates only the time that the i-node was last changed.
	By default, ls -l lists the time when the contents of the file were last modified.

还留有一些疑问的内容是关于 **sticky bit** 的，带后面更深入的学习后，再返到这里来理解吧。

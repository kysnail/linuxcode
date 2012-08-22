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

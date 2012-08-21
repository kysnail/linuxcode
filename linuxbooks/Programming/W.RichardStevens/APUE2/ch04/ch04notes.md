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

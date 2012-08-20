### Chapter 3 - File I/O

#### 3.2. File Descriptors
查看了一下 **Linux Kernel 2.4.20** 的内核代码，找到了 **OPEN_MAX** 所在的定义文件：

	file: include/linux/Limits.h
	kernel: 2.4.20
	----------------------------
	#ifndef _LINUX_LIMITS_H
	#define _LINUX_LIMITS_H

	#define NR_OPEN	        1024

	#define NGROUPS_MAX       32	/* supplemental group IDs are available */
	#define ARG_MAX       131072	/* # bytes of args + environ for exec() */
	#define CHILD_MAX        999    /* no limit :-) */
	#define OPEN_MAX         256	/* # open files a process may have */
	#define LINK_MAX         127	/* # links a file may have */
	#define MAX_CANON        255	/* size of the canonical input queue */
	#define MAX_INPUT        255	/* size of the type-ahead buffer */
	#define NAME_MAX         255	/* # chars in a file name */
	#define PATH_MAX        4096	/* # chars in a path name including nul */
	#define PIPE_BUF        4096	/* # bytes in atomic write to a pipe */
	#define XATTR_NAME_MAX   255	/* # chars in an extended attribute name */
	#define XATTR_SIZE_MAX 65536	/* size of an extended attribute value (64k) */
	#define XATTR_LIST_MAX 65536	/* size of extended attribute namelist (64k) */

	#define RTSIG_MAX	  32

	#endif

#### 3.6 lseek Function
How to determine the current *offset*.

	off_t 	currpos;
	currpos = lseek(fd, 0, SEEK_CUR);

This technique can also be used to determine if a file is capable of seeking.

**Demo - Test whether standard input is capable of seeking.**

	src/fig3.1.c

**Execution**

	==$ ./a.out 
	cannot seek

	==$ ./a.out < /etc/mo
	modprobe.d/     modules-load.d/ mono/           motd

	==$ ./a.out < /etc/motd 
	seek OK

	==$ cat < /etc/motd | ./a.out 
	cannot seek

	==$ ./a.out < /var/spool/cron/FIFO
	-bash: /var/spool/cron/FIFO: Permission denied
	
##### Figure 3.2 Create a file with a hole in it 

**Demo**

	src/fig3.2.c
	src/err.c

**Execution**

	==$ od -c file.hole   
	0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
	0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
	*
	0040000   A   B   C   D   E   F   G   H   I   J
	0040012

**od** command look at the contents of the file. The **-c** flag tells it to print the constents as characters.

compare the file we've just create with a file of the same size, but without holes.

	==$ ll -s file.hole file.nohole 
	 8 -rw-r--r-- 1 kangyushi ie2 16394 Aug 17 21:23 file.hole
	20 -rw-r--r-- 1 kangyushi ie2 16394 Aug 17 21:28 file.nohole

#### 3.7 read Function

	#inlcude <unistd.h>
	
	ssize_t read(int filedes, void *buf, size_t nbytes)

本节有两点需要注意：

1. In ISO C: the type `void *` is used for generic pointers.
2. `ssize_t` -> signed integer & `size_t` -> unsigned integer.

#### 3.10 File Sharing

 * process table -> process table entry
 * file table -> file table entry
 * file descriptor -> file table entry
 * file status flags
 * v-node vs i-node
 * lseek & `O_APPEND`

上面几个概念是本节需要注意区分的。

还有一句，不太好理解，估计需要后续的知识补充。

	Note the difference in scope between the file descriptor flags and the file status flags.
	The formor apply only to a single descriptor in a single process, whereas the latter apply to
	all descriptors in any process that point to the given file table entry.

#### 3.11 Atomic Operations

##### Appending to a File
为什么需要 Atomic Operations ？

	任何一个需要多个函数调用的操作都不可能是原子操作，因为在两个函数调用之间，内核有可能
	会临时挂起该进程。正是由于这种逻辑上的问题，才需要针对这种多函数调用的情况进行原子化处理。

对于 `O_APPEND` 模式写文件的操作，UNIX 系统提供了一种机制，帮助实现原子操作，即在 open 文件时，指定 `O_APPEND` 模式。

##### Creating a File
调用 open 函数的 `O_CREAT` 和 `O_EXCL` 创建文件时，实际上系统是将其作为一个原子操作存在的。

##### Atomic Operation
In general, the term *atomic* operation refers to an operation that might be composed of multiple steps. If the operation perfomed atomically, either all the steps are performed, or none are performed. It must not be possible for a subset of the steps to be performed. 

#### 3.12 dup and dup2 Functions
`dup` & `dup2` 

	The new file descriptor that is returned as the value of the functions shares 
	the same file table entry as the filedes argument.

`dup` & `dup 所做的工作也可以由 `fcntl` 函数完 他们之间的区别也在于是否能够保证 Atomic 。

#### 3.13 sync, fsync, and fdatasync Functions
传统的 UNIX 系统上，Linux 的 I/O 操作分为三个阶段：

 1. 将文件写入 kernel 中的 buffer cache 或 page cache；
 2. 将 cache 中的文件写入输出队列 - `delayed write`；
 3. 当满足一定规则时， 才真正写入磁盘。

既然分为了三部分进行操作，那必然也会遇到 Atomic Operation 的问题。为了解决实际文件系统与高速缓存的一致性问题，引入了上面三个函数。

 1. sync -> 强制完成第二步，将文件写入输出队列；
 2. fsync -> 强制完成第二、三步，将文件写入磁盘；
 3. fdatasync -> 与 fsync 的功能类似，但是不会同步更新文件属性。

#### 3.14 fcntl Function

##### Figure 3.10. Print the file flags for specified descriptor
**Execution**

    src/fig3.10.c 
    gcc fig3.10.c err.c
    -------------------------------------------------
    ==$ ./a.out 0 < /dev/tty
    read only
    
    ==$ ./a.out 1 > temp.foo
    ==$ cat temp.foo 
    write only
    
    ==$ ./a.out 2 2>>temp.foo 
    write only, append
    
    ==$ ./a.out 5 5<>temp.foo 
    read write
    
这里需要注意最后一条指令：

	The clause 5<>temp.foo opens the file temp.foo for reading and writing on the file descriptor 5.

##### Figure 3.11. Turn on one or more of the file status flags for a descriptor
本节相对比较难理解，需要后面在返回来看。

	src/fig3.11.c

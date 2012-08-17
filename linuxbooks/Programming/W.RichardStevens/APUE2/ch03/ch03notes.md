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
	

##Device Drivers, Part 2: Writing Your First Linux Driver in the Classroom

从驱动安装的角度，看 Linux 相较于 Windows 的优越性。

    Windows 上安装完系统后，需要重启机器，这在很多服务器环境中是不可接受的。
    而在 Linux 上驱动的安装与卸载可以动态完成，并不会影响系统的运行。

### Dynamically loading drivers
可以动态加载的驱动又被称为模块，通常会被预编译为 **.ko** 结尾的文件。预编译模块的组织结构类似于内核源码树，通常存放在

    /lib/modules/<kernel_version>/kernel

`kernel_version` 的值可以由 `uname -r` 获取。

	---------------------------------------------------------------------
	Linux pre-built modules
	---------------------------------------------------------------------
	[root@CentOS55 ch02]# uname -r
	2.6.18-194.el5
	[root@CentOS55 ch02]# ls /lib/modules/`uname -r`/kernel
	arch  crypto  drivers  fs  lib  net  sound
	[root@CentOS55 ch02]# ls /usr/src/linux/
	arch     init            mm              scripts
	block    ipc             Module.kabi     security
	crypto   kabi_whitelist  Module.markers  sound
	drivers  kernel          Module.symvers  symsets-2.6.18-194.el5.tar.gz
	fs       lib             net             usr
	include  Makefile        samples
	[root@CentOS55 ch02]# 

### linux 内核源码存放位置
通常会将源码存放到 

    /usr/src/linux 

下。如果有多个版本，则可以将其指向 /usr/src/linux 目录，这样方便开发。

### CentOS 55 源码安装
安装的时侯选择内核源码包，会在安装完成后的 /usr/src/kernels 目录中找到对应的 linux-2.6.34.tar.bz2 包。将源码包解压后，指向上面的地址即可。

    [root@CentOS55 src]# ln -s /usr/src/kernels/linux-2.6.34 
    /usr/src/linux
    [root@CentOS55 src]# pwd
    /usr/src
    [root@CentOS55 src]# ll
    total 20
    drwxr-xr-x 2 root root 4096 Jan 27  2010 debug
    drwxr-xr-x 3 root root 4096 May 16 09:39 kernels
    lrwxrwxrwx 1 root root   29 May 16 09:43 linux -> usr/src/kernels/linux-2.6.34
    drwxr-xr-x 4 root root 4096 Mar 21 16:38 redhat

现在有这样一个问题，我不能确定这个内核源码是我拷入的，还是系统给安装的。因为查看 `uname -r` 得到的结果与这里提供的源码包版本并不相同。

查看 CentOS55 系统提供有对应的源码 rpm 包，

    kernel-2.6.18-194.el5.i686.rpm
    kernel-debug-2.6.18-194.el5.i686.rpm
    kernel-debug-devel-2.6.18-194.el5.i686.rpm
    kernel-devel-2.6.18-194.el5.i686.rpm
    kernel-doc-2.6.18-194.el5.noarch.rpm
    kernel-headers-2.6.18-194.el5.i386.rpm

与 `uname -r` 所查到的版本一致。

#### 重新安装内核源码

	[root@CentOS55 ch02]# rpm -fe `rpm -q kernel`      => 这里的选项参数可能有问题，这里的 -e 选项并不能够移除，可能需要 --force 选项，才能生效。
	error: Failed dependencies:
		kernel >= 2.6.12-1.1411_FC5 is needed by (installed) pcmciautils-014-5.i386
		kernel >= 2.6 is needed by (installed) gnome-volume-manager-2.15.0-5.el5.i386

	[root@CentOS55 ch02]# rpm -ivh kernel-2.6.18-194.el5.i686.rpm 
	warning: kernel-2.6.18-194.el5.i686.rpm: Header V3 DSA signature: NOKEY, key ID e8562897
	Preparing...                ########################################### [100%]
		package kernel-2.6.18-194.el5.i686 is already installed

	[root@CentOS55 ch02]# rpm --replacepkgs 
	rpm: only installation, upgrading, rmsource and rmspec may be forced
	[root@CentOS55 ch02]# rpm --replacepkgs -ivh kernel-2.6.18-194.el5.i686.rpm 
	warning: kernel-2.6.18-194.el5.i686.rpm: Header V3 DSA signature: NOKEY, key ID e8562897
	Preparing...                ########################################### [100%]
	   1:kernel                 ########################################### [100%]

这是实际是安装 Linux 内核，而不是源码，安装源码的过程如下：

	应该是安装 `kernel-debug-2.6.18-194.el5.i686.rpm` 即可。

### 模块操作常用命令
模块加载命令通常位于 `/sbin` 目录中。

    * lsmod
    * insmod <module_file>
    * modprobe <module>
    * rmmod <module>


    [root@CentOS55 fs]# pwd
    /lib/modules/2.6.18-194.el5/kernel/fs
    [root@CentOS55 fs]# ll *fat msdos
    fat:
    total 68
    -rwxr--r-- 1 root root 59472 Apr  3  2010 fat.ko
    
    msdos:
    total 20
    -rwxr--r-- 1 root root 15048 Apr  3  2010 msdos.ko
    
    vfat:
    total 24
    -rwxr--r-- 1 root root 18244 Apr  3  2010 vfat.ko

    [root@CentOS55 fs]# /sbin/insmod vfat/vfat.ko 
    insmod: error inserting 'vfat/vfat.ko': -1 Unknown symbol in module
    [root@CentOS55 fs]# dmesg | tail -3
    vfat: Unknown symbol fat_add_entries
    vfat: Unknown symbol fat_sync_inode
    vfat: Unknown symbol fat_detach
    [root@CentOS55 fs]# /sbin/insmod fat/fat.ko 
    [root@CentOS55 fs]# /sbin/insmod vfat/vfat.ko 
    [root@CentOS55 fs]# lsmod | head -5
    bash: lsmod: command not found
    [root@CentOS55 fs]# /sbin/lsmod | head -5
    Module                  Size  Used by
    vfat                   15937  0 
    fat                    51165  1 vfat
    autofs4                29253  3 
    hidp                   23105  2 
    [root@CentOS55 fs]# /sbin/rm
    rmmod  rmt    
    [root@CentOS55 fs]# /sbin/rmmod vfat fat
    [root@CentOS55 fs]# /sbin/modprobe vfat
    [root@CentOS55 fs]# /sbin/rmmod vfat fat
    [root@CentOS55 fs]# /sbin/lsmod | head -5
    Module                  Size  Used by
    autofs4                29253  3 
    hidp                   23105  2 
    rfcomm                 42457  0 
    l2cap                  29505  10 hidp,rfcomm
    [root@CentOS55 fs]# /sbin/modprobe vfat
    [root@CentOS55 fs]# /sbin/lsmod | head -5
    Module                  Size  Used by
    vfat                   15937  0 
    fat                    51165  1 vfat
    autofs4                29253  3 
    hidp                   23105  2 

### Our First Linux Driver

	/usr/include -- 一般应用程序使用
	/usr/src/linux -- 模块使用

关于内核，最有意思的莫过于它是 C 语言面向对象方式的实现。

	Our interesting fact about the kernel is that it is an object-oriented implementation in C, as
	we will observe even with our first driver. Any Linux driver has a constructor and a destructor.
	The module's constructor is called when the module is successfully loaded into the kernel, and 
	the destructor when rmmod succeeds in unloading the module. These two are like normal functions 
	in the driver, except that they are specified as the init and exit functions, respectively, by
	the macros module_init() and module_exit(), which are defined in the kernel header module.h.

我的第一个 kernel 程序如下：

	nclude <linux/module.h>
	#include <linux/version.h>
	#include <linux/kernel.h>
	 
	static int __init ofd_init(void) /* Constructor */
	{
	    printk(KERN_INFO "Namaskar: ofd registered");
	    return 0;
	}

	static void __exit ofd_exit(void) /* Destructor */
	{
	    printk(KERN_INFO "Alvida: ofd unregistered");
	}

	module_init(ofd_init);
	module_exit(ofd_exit);

	MODULE_LICENSE("GPL");
	MODULE_AUTHOR("Anil Kumar Pugalia <email_at_sarika-pugs_dot_com>");
	MODULE_DESCRIPTION("Our First Driver");

注意下面几点：

	1. 没有使用 stdio.h ，这里需要 kernel.h 。
		stdio.h 	=> a user-space header
		kernel.h	=> a kernel space header
	2. 使用 printf 的内核版本 printk 。


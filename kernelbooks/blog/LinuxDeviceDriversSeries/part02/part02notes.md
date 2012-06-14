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


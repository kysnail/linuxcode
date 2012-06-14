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



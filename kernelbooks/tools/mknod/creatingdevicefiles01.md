## Creating device files
关于创建设备文件的文章，查到了不少，但很多可能由于时间的原因，与我使用的机器都不同：

### Creating devicd files - Linux From Scratch

#### Installation of MAKEDEV
Install MAKEDEV by running the following commands:

	sed "s/# 9/9/" MAKEDEV >/dev/MAKEDEV &&
	chmod 755 /dev/MAKEDEV

#### Creating the /dev entries
Create the device files by running the following commands:

	cd /dev && ./MAKEDEV -v generic

The "generic" parameter passed to the MAKEDEV script doesn't create all the devices you might need, such as audio devices, hdc, hdd and others. If you seem to be missing something tell MAKEDEV to create it. To create hdc replace generic with hdc. You can also add hdc to neneric, so you would execute 

	./MAKEDEV -v generic hdc

to create the generic set of devices file, plus the files you need to be able to access hdc (and hdc1, hdc2, etc)

Please note that this script dates back from 1997 and therefore can be outdated and not support newer hardware. If you need device file which aren't known by this script please read the Deocumentation/devices.txt file in a Linux source tree. This file lists all the major and minor numbers for all the devices files that the kernel knows about. With this list you can create such device files yourself. See mknod man page for more information on how to make device files yourself.

#### Command explanations

	sed "s/# 9/9/" MAKEDEV >/dev/MAKEDEV

By default the Makedev script only creates the hda1-hda8 and hdb1-hdb8 devices. By replacing "#9# by "9"'s in the MAKEDEV script, it will create hda1-hda20,

	chmod 755 /dev/MAKEDEV

This sets the permissions of the MAKEDEV script to mode 754 which makes it executable only for owner and group and readable by everybody.

#### Contents
The MAKEDEV package contains the MAKEDEV script.

#### Description
MAKEDEV is a script that can aid you in creating the necessary static device files that usually reside in the /dev directory.


**Refs**

 * [Creating device files](http://archive.linuxfromscratch.org/lfs-museum/2.4.3/LFS-BOOK-INTEL-2.4.3-HTML/ch06-createdev.html)
 * [8.5. 创建设备节点 - FreeBSD 使用手册](http://docs.freebsd.org/doc/5.3-RELEASE/usr/share/doc/zh_CN.GB2312/books/handbook/kernelconfig-nodes.html)


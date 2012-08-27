# 目标
使用 debootstrap 工具制作一个 Debian 基础系统。

## U disk
最好准备一个 U 盘进行操作，这样不会影响主机。

	[root@fedora16 kangyushi]# umount /dev/sdc1
	[root@fedora16 kangyushi]# mkfs.ext3 /dev/sdc1
	mke2fs 1.41.14 (22-Dec-2010)
	Filesystem label=
	OS type: Linux
	Block size=4096 (log=2)
	Fragment size=4096 (log=2)
	Stride=0 blocks, Stripe width=0 blocks
	244800 inodes, 978424 blocks
	48921 blocks (5.00%) reserved for the super user
	First data block=0
	Maximum filesystem blocks=1002438656
	30 block groups
	32768 blocks per group, 32768 fragments per group
	8160 inodes per group
	Superblock backups stored on blocks:
		32768, 98304, 163840, 229376, 294912, 819200, 884736

	Writing inode tables: done
	Creating journal (16384 blocks): done
	Writing superblocks and filesystem accounting information: done

	This filesystem will be automatically checked every 34 mounts or
	180 days, whichever comes first.  Use tune2fs -c or -i to override.

卸载 /dev/sdc1 分区后，对其进行格式化操作。

## 准备安装目录
准备 Debian 系统的安装目录，并将其挂在到 `/root/minisys` 目录下：

	[root@fedora16 ~]# mkdir /root/minisys
	[root@fedora16 ~]# mount /dev/sdc1 /root/minisys
	[root@fedora16 ~]# ll /root/minisys
	total 16
	drwx------ 2 root root 16384 Aug 27 16:33 lost+found

## install debootstrap tool

	# apt-get install debootstrap

## install a Debian base system

	[root@fedora16 minisys]# debootstrap --arch i386 lenny /root/minisys/ http://mirrors.163.com/debian-archive
	I: Retrieving InRelease
	I: Failed to retrieve InRelease
	I: Retrieving Release
	W: Cannot check Release signature; keyring file not available /usr/share/keyrings/debian-archive-keyring.gpg
	I: Retrieving Packages
	I: Validating Packages
	I: Resolving dependencies of required packages...
	I: Resolving dependencies of base packages...
	I: Checking component main on http://mirrors.163.com/debian-archive...
	I: Retrieving libacl1
	I: Validating libacl1
	I: Retrieving adduser
	I: Validating adduser
	I: Retrieving apt-utils
	I: Validating apt-utils
	I: Retrieving apt
	I: Validating apt
	I: Retrieving aptitude
	I: Validating aptitude
	I: Retrieving libattr1
	I: Validating libattr1
	I: Retrieving base-files
	I: Validating base-files
	I: Retrieving base-passwd
	I: Validating base-passwd
	I: Retrieving bash
	I: Validating bash
	......
	I: Configuring debian-archive-keyring...
	I: Configuring apt...
	I: Configuring libept0...
	I: Configuring apt-utils...
	I: Configuring aptitude...
	I: Configuring tasksel-data...
	I: Configuring tasksel...
	I: Base system installed successfully.

	[root@fedora16 minisys]# pwd
	/root/minisys
	[root@fedora16 minisys]# ll
	total 96
	drwxr-xr-x  2 root root  4096 Aug 27 17:38 bin
	drwxr-xr-x  2 root root  4096 Mar  5 04:52 boot
	drwxr-xr-x  4 root root 12288 Aug 27 17:38 dev
	drwxr-xr-x 39 root root  4096 Aug 27 17:38 etc
	drwxr-xr-x  2 root root  4096 Mar  5 04:52 home
	drwxr-xr-x 10 root root  4096 Aug 27 17:37 lib
	drwx------  2 root root 16384 Aug 27 16:33 lost+found
	drwxr-xr-x  2 root root  4096 Aug 27 17:32 media
	drwxr-xr-x  2 root root  4096 Mar  5 04:52 mnt
	drwxr-xr-x  2 root root  4096 Aug 27 17:32 opt
	drwxr-xr-x  2 root root  4096 Mar  5 04:52 proc
	drwxr-xr-x  2 root root  4096 Aug 27 17:32 root
	drwxr-xr-x  2 root root  4096 Aug 27 17:38 sbin
	drwxr-xr-x  2 root root  4096 Sep 16  2008 selinux
	drwxr-xr-x  2 root root  4096 Aug 27 17:32 srv
	drwxr-xr-x  2 root root  4096 Aug 12  2008 sys
	drwxrwxrwt  2 root root  4096 Aug 27 17:38 tmp
	drwxr-xr-x 10 root root  4096 Aug 27 17:32 usr
	drwxr-xr-x 13 root root  4096 Aug 27 17:32 var

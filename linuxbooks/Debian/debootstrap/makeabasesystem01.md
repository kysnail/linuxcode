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

## Base System Configuration
使用 chroot 进入 Base System，然后进行必要的基本设定。

	[root@fedora16 minisys]# chroot /root/minisys/ env -i HOME=/root /bin/bash --login
	fedora16:/# ls -al
	total 104
	drwxr-xr-x 21 root root  4096 Aug 27 09:38 .
	drwxr-xr-x 21 root root  4096 Aug 27 09:38 ..
	drwxr-xr-x  2 root root  4096 Aug 27 09:38 bin
	drwxr-xr-x  2 root root  4096 Mar  4 20:52 boot
	drwxr-xr-x  4 root root 12288 Aug 27 09:38 dev
	drwxr-xr-x 39 root root  4096 Aug 27 09:38 etc
	drwxr-xr-x  2 root root  4096 Mar  4 20:52 home
	drwxr-xr-x 10 root root  4096 Aug 27 09:37 lib
	drwx------  2 root root 16384 Aug 27 08:33 lost+found
	drwxr-xr-x  2 root root  4096 Aug 27 09:32 media
	drwxr-xr-x  2 root root  4096 Mar  4 20:52 mnt
	drwxr-xr-x  2 root root  4096 Aug 27 09:32 opt
	drwxr-xr-x  2 root root  4096 Mar  4 20:52 proc
	drwxr-xr-x  2 root root  4096 Aug 27 09:32 root
	drwxr-xr-x  2 root root  4096 Aug 27 09:38 sbin
	drwxr-xr-x  2 root root  4096 Sep 16  2008 selinux
	drwxr-xr-x  2 root root  4096 Aug 27 09:32 srv
	drwxr-xr-x  2 root root  4096 Aug 12  2008 sys
	drwxrwxrwt  2 root root  4096 Aug 27 09:38 tmp
	drwxr-xr-x 10 root root  4096 Aug 27 09:32 usr
	drwxr-xr-x 13 root root  4096 Aug 27 09:32 var
	fedora16:/#

基本系统大约 147M 左右，但不同的系统可能会有所差别。	

	--------------------------------------------------------------------------------------
	fedora16:/# du -sh
	190M    .
	fedora16:/# apt-get clean
	fedora16:/# du -sh
	147M    .
	
	--------------------------------------------------------------------------------------
	
如果希望在基本系统中执行一些与系统相关的命令，应该现在该基本系统中加载 `proc` 文件系统，并且其反映的一些信息都是当前系统的信息。

	fedora16:/# ps
	Cannot find /proc/version - is /proc mounted?
	fedora16:/# ps -aef
	Cannot find /proc/version - is /proc mounted?
	fedora16:/# mount -t proc proc /proc/
	fedora16:/# ps -aef
	UID        PID  PPID  C STIME TTY          TIME CMD
	root         1     0  0 04:19 ?        00:00:00 /sbin/init
	root         2     0  0 04:19 ?        00:00:00 [kthreadd]
	root         3     2  0 04:19 ?        00:00:00 [ksoftirqd/0]
	root         6     2  0 04:19 ?        00:00:00 [migration/0]
	......
	1003     25964 25962  0 10:53 ?        00:00:00 sshd: kangyushi@pts/3
	1003     25965 25964  0 10:53 ?        00:00:00 -bash
	1003     26093 25965  0 10:54 ?        00:00:00 vim makeabasesystem01.md
	root     26100   884  0 10:54 ?        00:00:00 sleep 60
	root     26103 25947  0 10:55 ?        00:00:00 ps -aef

## 将编译好的 Kernel 安装到 Debian Base System 中

	[root@fedora16 kangyushi]# cp /home/kangyushi/work/makekernel/3.5.2/ver01/build/kernel/System.map /root/minisys/boot/System.map-3.5.2
	[root@fedora16 kangyushi]# cp /home/kangyushi/work/makekernel/3.5.2/ver01/build/kernel/.config /root/minisys/boot/config-3.5.2
	[root@fedora16 kangyushi]# cp /home/kangyushi/work/makekernel/3.5.2/ver01/build/kernel/arch/x86_64/boot/bzImage /root/minisys/boot/vmlinuz-3.5.2

## Making initrd.img file

	=====> 登录基本系统
	[root@fedora16 kangyushi]# sudo chroot /root/minisys/ env -i HOME=/root /bin/bash --login
	
	=====> 保证这两个目录是非挂载状态
	fedora16:/# umount /proc/
	fedora16:/# umount /proc/
	umount: /proc/: not mounted
	fedora16:/# umount /sys/
	umount: /sys/: not mounted

	=====> 挂载目录
	fedora16:/# mount -t proc proc /proc
	fedora16:/# mount -t sysfs sys /sys
	fedora16:/# mount -t devpts devpts /dev/pts

	=====> 需要安装 mkinitramfs 工具
	fedora16:/# mkinitramfs -o /boot/initrd.img-3.5.2
	bash: mkinitramfs: command not found

	initrd-tools 这个名称可能有问题
	fedora16:/# apt-get install initrd-tools
	Reading package lists... Done
	Building dependency tree... Done
	E: Couldn't find package initrd-tools

	=====> 需要使用 bootcd-mkinitramfs 工具制作文件系统
	fedora16:/# apt-get install bootcd-mkinitramfs
	Reading package lists... Done
	Building dependency tree... Done
	The following extra packages will be installed:
	  bootcd bootcd-i386 busybox dosfstools fdutils file genisoimage initramfs-tools klibc-utils libcap2 libklibc libmagic1 libvolume-id0 mtools realpath syslinux syslinux-common udev wodim
	Suggested packages:
	  ssh discover discover1 cdrkit-doc floppyd
	The following NEW packages will be installed:
	  bootcd bootcd-i386 bootcd-mkinitramfs busybox dosfstools fdutils file genisoimage initramfs-tools klibc-utils libcap2 libklibc libmagic1 libvolume-id0 mtools realpath syslinux syslinux-common udev
	  wodim
	0 upgraded, 20 newly installed, 0 to remove and 0 not upgraded.
	Need to get 3601kB of archives.
	After this operation, 10.6MB of additional disk space will be used.
	Do you want to continue [Y/n]? y
	WARNING: The following packages cannot be authenticated!
	  libvolume-id0 udev libmagic1 file libcap2 busybox dosfstools fdutils genisoimage libklibc klibc-utils initramfs-tools mtools realpath syslinux-common syslinux wodim bootcd-i386 bootcd
	  bootcd-mkinitramfs
	Install these packages without verification [y/N]? y
	Get:1 http://mirrors.163.com lenny/main libvolume-id0 0.125-7+lenny3 [77.0kB]
	Get:2 http://mirrors.163.com lenny/main udev 0.125-7+lenny3 [255kB]
	Get:3 http://mirrors.163.com lenny/main libmagic1 4.26-1 [369kB]
	Get:4 http://mirrors.163.com lenny/main file 4.26-1 [44.1kB]
	........
	Setting up syslinux (2:3.71+dfsg-5) ...
	Setting up wodim (9:1.1.9-1) ...
	Setting up bootcd-i386 (3.10+nmu1) ...
	Setting up bootcd (3.10+nmu1) ...
	Setting up bootcd-mkinitramfs (3.10+nmu1) ...
	update-initramfs: deferring update (trigger activated)
	Processing triggers for initramfs-tools ...
	fedora16:/#

	=====> 这里提示找不到模块信息，这是由于没有做内核模块安装的步骤
	fedora16:/# mkinitramfs -o /boot/initrd.img-3.5.2
	Cannot find /lib/modules/3.4.7-1.fc16.x86_64

	=====> 内核模块安装的步骤
	[root@fedora16 linux-3.5.2]# make O=/home/kangyushi/work/makekernel/3.5.2/ver01/build/kernel/ modules_install INSTALL_MOD_PATH=/root/minisys
	  INSTALL Documentation/connector/cn_test.ko
	  INSTALL Documentation/filesystems/configfs/configfs_example_explicit.ko
	  INSTALL Documentation/filesystems/configfs/configfs_example_macros.ko
	  INSTALL arch/x86/crypto/blowfish-x86_64.ko
	  INSTALL arch/x86/crypto/camellia-x86_64.ko
	  INSTALL arch/x86/crypto/crc32c-intel.ko
	  INSTALL arch/x86/crypto/ghash-clmulni-intel.ko
	  INSTALL arch/x86/crypto/salsa20-x86_64.ko
	  INSTALL arch/x86/crypto/serpent-sse2-x86_64.ko
	  INSTALL arch/x86/crypto/sha1-ssse3.ko
	  INSTALL arch/x86/crypto/twofish-x86_64-3way.ko
	  INSTALL arch/x86/crypto/twofish-x86_64.ko
	  INSTALL arch/x86/kernel/microcode.ko
	  INSTALL arch/x86/kernel/test_nx.ko
	  INSTALL arch/x86/kvm/kvm-amd.ko
	  INSTALL arch/x86/kvm/kvm-intel.ko
	  INSTALL arch/x86/kvm/kvm.ko
	  INSTALL arch/x86/oprofile/oprofile.ko
	......
	  INSTALL /root/minisys/lib/firmware/keyspan_pda/keyspan_pda.fw
	  INSTALL /root/minisys/lib/firmware/keyspan_pda/xircom_pgs.fw
	  MKDIR   /root/minisys/lib/firmware/cpia2/
	  INSTALL /root/minisys/lib/firmware/cpia2/stv0672_vp4.bin
	  MKDIR   /root/minisys/lib/firmware/yam/
	  INSTALL /root/minisys/lib/firmware/yam/1200.bin
	  INSTALL /root/minisys/lib/firmware/yam/9600.bin
	  DEPMOD  3.5.2

这里需要注意，不要将模块安装命令写成了

	[root@fedora16 linux-3.5.2]# make O=/home/kangyushi/work/makekernel/3.5.2/ver01/build/kernel/ modules_install INSTALL_MOD_PATH=/root/minisys/ install

最后的 `install` 选项会将内核安装进去，但实际操作中往往会报错。错误大概的意思是说 

	/lib/modules

目录不存在这样的信息。从错误信息可以看到 `O` 选项对于 `install` 并不起作用。

	

	

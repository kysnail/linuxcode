## Coreboot + FILO
这种组合方式可以正常的启动系统。

但网上关于 **FILO** 的介绍很少，好像只有 Coreboot 网站上有比较完整的描述。

 * [Coreboot+FILO on qemu](http://www.coreboot.org/pipermail/coreboot/2009-April/046457.html)
 * [FILO](http://www.coreboot.org/FILO)

## Start QEMU with -pflash option
 /home/sunxuebin/myWorks/qemu-hardware-test/qemu-bin/bin/qemu-system-i386 -pflash /home/kangyushi/work/qemu/pflash/coreboot/corebootfilo.rom -hda /media/a7bea563-2e18-46c48701-cd2209737bf1/share/qemu-img/debian.img -boot menu=on

## FILO 0.6.0

	filo> root (hd0,0)
	filo> kernel /boot/vmlinuz-2.6.32-5-686 ro root=/dev/sda1
	filo> initrd /boot/initrd.img-2.6.32-5-686
	filo> boot

之前由于错误的配置了 文件系统 / 所在的位置，

    root=LABEL=/
    root=/dev/hda1
    root=/dev/hda0
    root=LABEL=/boot

等配置都没能让系统正常启动文件系统。会提示如下错误：

	Gave up waiting for root device. Common problems:
	-Boot args (cat /proc/cmdline)
	-Check rootdelay= (did the system wait long enough?)
	- Check root= (did the system wait for the right device?)
	- Missing modules (cat /proc/modules; ls /dev)
	ALERT! /dev/disk/by-uuid/3c809e3d-59c5-43c1-b119-fc277a418f43 does not exist.
	Dropping to a shell!

	BusyBox v1.17.1 (Debian 1:1.17.1-8) built in shell (ash)
	Enter 'help' for a list of built-in commands.

	/bin/sh: can't access tty; job control turned off
	(initramfs)

 * [Stuck at initramfs](http://forums.debian.net/viewtopic.php?f=17&t=81536)
 * [Boot problem - "Gave up waiting for root device."](http://ubuntuforums.org/showthread.php?t=1399810)

查来查去发现原来是分区路径指错了。能够找到问题的根源，全拜下面这条命令的福：

	(initramfs) blkid
	/dev/sda1: UUID="ddef5f0f-328b-4cae-b27f-bf95475f6209" TYPE="ext3"
	/dev/sda5: UUID="2037f12a-f11b-4f61-8a48-892177ec341a" TYPE="swap"
	(initramfs) 

## FILO 0.5.0
开始还尝试了这个版本，但所提供的命令实在太少，就换到了上面那个较新的版本。


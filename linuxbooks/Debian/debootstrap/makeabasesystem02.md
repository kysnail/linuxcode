# Install Base System

	[root@fedora16 minisys]# mkdir /root/minisys
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
	I: Configuring aptitude...
	I: Configuring tasksel-data...
	I: Configuring tasksel...
	I: Base system installed successfully.
	[root@fedora16 minisys]#

# Configure The Base System
Now you've got a real Debian system, though rather lean, on disk. **chroot** into it.

	[root@fedora16 minisys]# chroot /root/minisys/ env -i HOME=/root /bin/bash --login
	fedora16:/#

加载 proc 文件系统，用以执行与系统相关的命令；

	fedora16:/# mount -t proc proc /proc/
	fedora16:/# ps -aef

# Install mkinitramfs tools

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
	Do you want to continue [Y/n]? Y
	WARNING: The following packages cannot be authenticated!
	  libvolume-id0 udev libmagic1 file libcap2 busybox dosfstools fdutils genisoimage libklibc klibc-utils initramfs-tools mtools realpath syslinux-common syslinux wodim bootcd-i386 bootcd
	  bootcd-mkinitramfs
	Install these packages without verification [y/N]? y
	Get:1 http://mirrors.163.com lenny/main libvolume-id0 0.125-7+lenny3 [77.0kB]
	......
	Setting up syslinux-common (2:3.71+dfsg-5) ...
	Setting up syslinux (2:3.71+dfsg-5) ...
	Setting up wodim (9:1.1.9-1) ...
	Setting up bootcd-i386 (3.10+nmu1) ...
	Setting up bootcd (3.10+nmu1) ...
	Setting up bootcd-mkinitramfs (3.10+nmu1) ...
	update-initramfs: deferring update (trigger activated)
	Processing triggers for initramfs-tools ...

# prepare kernel files.

	[root@fedora16 minisys]# cp /home/kangyushi/work/makekernel/2.6.28.10/ver01/build/kernel/arch/x86_64/boot/bzImage /root/minisys/boot/vmlinuz-2.6.28.10
	[root@fedora16 minisys]# cp /home/kangyushi/work/makekernel/2.6.28.10/ver01/build/kernel/.config /root/minisys/boot/config-2.6.28.10
	[root@fedora16 minisys]# cp /home/kangyushi/work/makekernel/2.6.28.10/ver01/build/kernel/System.map /root/minisys/boot/System.map-2.6.28.10

# install modules

	[root@fedora16 linux-2.6.28.10]# make O=/home/kangyushi/work/makekernel/2.6.28.10/ver01/build/kernel modules_install INSTALL_MOD_PATH=/root/minisys
	  INSTALL arch/x86/kernel/test_nx.ko
	  INSTALL drivers/hid/hid-dummy.ko
	  INSTALL drivers/scsi/scsi_wait_scan.ko
	  DEPMOD  2.6.28.10
	[root@fedora16 linux-2.6.28.10]#

# make initrd

	fedora16:/# ls -alh /boot/initrd.img-2.6.28.10
	-rw-r--r-- 1 root root 1.6M Aug 30 05:40 /boot/initrd.img-2.6.28.10

# create qemu img file

	[root@fedora16 os]# qemu-img create debian-lenny.raw 2G
	Formatting 'debian-lenny.raw', fmt=raw size=2147483648
	[root@fedora16 os]# mkfs.ext2 -F debian-lenny.raw
	mke2fs 1.41.14 (22-Dec-2010)
	Filesystem label=
	OS type: Linux
	Block size=4096 (log=2)
	Fragment size=4096 (log=2)
	Stride=0 blocks, Stripe width=0 blocks
	131072 inodes, 524288 blocks
	26214 blocks (5.00%) reserved for the super user
	First data block=0
	Maximum filesystem blocks=536870912
	16 block groups
	32768 blocks per group, 32768 fragments per group
	8192 inodes per group
	Superblock backups stored on blocks:
		32768, 98304, 163840, 229376, 294912

	Writing inode tables: done
	Writing superblocks and filesystem accounting information: done

	This filesystem will be automatically checked every 31 mounts or
	180 days, whichever comes first.  Use tune2fs -c or -i to override.
	[root@fedora16 os]# mkdir my-mnt
	[root@fedora16 os]# mount -o loop debian-lenny.raw ./my-mnt/
	[root@fedora16 os]# rsync -rvl /root/minisys/ ./my-mnt/
	sending incremental file list
	bin/
	bin/bash
	bin/busybox
	bin/cat
	bin/chgrp
	......
	var/log/btmp
	var/log/dmesg
	var/log/dpkg.log
	var/log/faillog
	var/log/lastlog
	var/log/wtmp
	var/log/apt/
	var/log/apt/term.log
	var/log/fsck/
	var/log/fsck/checkfs
	var/log/fsck/checkroot
	var/mail/
	var/opt/
	var/run/
	var/run/motd
	var/run/utmp
	var/spool/
	var/spool/mail -> ../mail
	var/spool/cron/
	var/spool/cron/crontabs/
	var/tmp/

	sent 215873301 bytes  received 161039 bytes  86413736.00 bytes/sec
	total size is 215296561  speedup is 1.00

# check qemu img file



# 验证内核有效性
本文希望使用一种比较简洁的方式来验证所编译内核的有效性。大体思路是，将所编译好的文件拷贝到 Linux 的 boot 目录之下，并在 `grub.cfg` 文件中添加待检测内核的条目。重启系统，选择需要验证的内核即可。

## 操作系统准备
做验证的前提是，先提供一个完整的操作系统环境。可以直接使用已安装好操作系统，也可以使用快照方式创建镜像，这样在出错环境下，可以轻松恢复到之前的状态。

### 创建系统快照

	# qemu-img create -f qcow2 -b /media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img debiansnapshot.img
	Formatting 'debiansnapshot.img', fmt=qcow2 size=5368709120 backing_file='/media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img' encryption=off cluster_size=65536

开启系统，并查看内核版本。

	# uanme -a 
	Linux debian 2.6.32-5-686 #1 SMP Wed Jan 12 04:01:41 UTC 2011 i686 GNU/Linux

### 导入内核文件
将编译好的内核及相关文件传入 debiansnapshot.img 系统中。

	# ls -alh
	总用量 23M
	drwxr-xr-x  3 root root 4.0K  8月 28 17:23 .
	drwxr-xr-x 23 root root 4.0K  7月 17 16:52 ..
	-rw-r--r--  1 root root 109K  1月 12 2011 config-2.6.32-5-686
	-rw-r--r--  1 root root 119K  8月 28 17:06 config-3.5.2
	drwxr-xr-x  3 root root 4.0K  8月 28 17:16 grub
	-rw-r--r--  1 root root 8.2M  5月 14 15:30 initrd.img-2.6.32-5-686
	-rw-r--r--  1 root root 4.0M  8月 28 17:03 initrd.img-3.5.2
	-rw-r--r--  1 root root 1.3M  1月 12 2011 System.map-2.6.32-5-686
	-rw-r--r--  1 root root 2.4M  8月 28 17:03 System.map-3.5.2
	-rw-r--r--  1 root root 2.2M  1月 12 2011 vmlinuz-2.6.32-5-686
	-rw-r--r--  1 root root 4.6M  8月 28 17:03 vmlinuz-3.5.2

### 配置 grub.cfg 文件

	menuentry 'Debian GNU/Linux, with Linux 3.5.2 (For testing use only)' --class debian --class gnu-linux --class gnu --class os {
		insmod part_msdos
		insmod ext2
		set root='(hd0,msdos1)'
		search --no-floppy --fs-uuid --set ddef5f0f-328b-4cae-b27f-bf95475f6209
		echo    'Loading Testing Environmnt Linux 3.5.2 ...'
		linux   /boot/vmlinuz-3.5.2 root=UUID=ddef5f0f-328b-4cae-b27f-bf95475f6209 ro  quiet
		echo    'Loading initial ramdisk ...'
		initrd  /boot/initrd.img-3.5.2
	}

在 `grub.cfg` 文件中添加新版本的 `entry` 。

### 重启系统查看
重启后选择上面添加的条目，进入系统后，查看内核版本：

	# uname -a
	Linux debian 3.5.2 #1 SMP Wed Aug 22 16:33:57 CST 2012 x86_64 GNU/Linux


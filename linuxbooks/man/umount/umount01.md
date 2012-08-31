# device is busy.
没有将 usb 做 umount 操作，直接将其从系统拔除，结果是，相应的设备文件被持续占用着！

	[root@fedora16 kernel]# df -lhT
	Filesystem                       Type      Size  Used Avail Use% Mounted on
	rootfs                           rootfs     50G  7.8G   42G  16% /
	devtmpfs                         devtmpfs  3.9G     0  3.9G   0% /dev
	tmpfs                            tmpfs     3.9G  1.2M  3.9G   1% /dev/shm
	/dev/sda2                        ext4       50G  7.8G   42G  16% /
	tmpfs                            tmpfs     3.9G   53M  3.9G   2% /run
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /sys/fs/cgroup
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /media
	/dev/sda6                        ext4      406G  218G  169G  57% /home
	/dev/sda5                        ext4     1021M   62M  909M   7% /tmp
	/dev/sda1                        ext4      497M  112M  360M  24% /boot
	/dev/mapper/vg_ie2server-lv_home ext4      410G  350G   40G  90% /media/a7bea563-2e18-46c4-8701-cd22
	/dev/sdc1                        ext3      3.7G  1.9G  1.7G  53% /root/minisys	<-- 这个 U 盘实际已被移除了。

然后再次进行 umount 操作的时候，就会发生下面的错误。

	[root@fedora16 kernel]# umount /dev/sdc1
	umount: /root/minisys: device is busy.
		(In some cases useful info about processes that use
		 the device is found by lsof(8) or fuser(1))
	[root@fedora16 kernel]# fuser -m /dev/sdc1
	/dev/sdc1:               1   414   437   820   826   827   834   838   851   852   855   857   859  72  1074  1076  1081  1084  1085  1102  1103  1122  1137  1164  1176  1187m  1190  1221  1245  1246 73  1574  1581  1584  1585m  1589  1598  1624  1636  1672  1673  1674  1679  1911  1927  1928  1929 89  2301  2496  2503  2654  2656  2658  2669  2676  2715  4084  4085  4086  4102  4103  4119  4122  8  4239  4240  4241  4246  4247  4254  4260  4263  4265  4268  4269  4282  4585  4589  4591  4593  4 13372 13399 13404 13481 13568 13576 13625 13837 14025 14083 14103 14179 14222 14337 14338 14339 14523742 23743 23759 23760 23776 23779 23783 23788 23826 23827 23839 23845 23854 23855 23857 23861 23863946 23948 23949 23986 24064 24276 24284 24286 24313 24315 24318 24323 24324 24337 24353 27321
	[root@fedora16 kernel]# umount -f /dev/sdc1
	umount2: Device or resource busy
	umount: /root/minisys: device is busy.
		(In some cases useful info about processes that use
		 the device is found by lsof(8) or fuser(1))
	umount2: Device or resource busy

查看 man ，`-f` 选项本身就是用于强制删除的，但在这里并不起作用。

	-f:
	---
	Force umount (in case of an unreachable NFS system).
	(Requires kernel 2.1.116 or later.)

最后用 `-l` 去除了所占用的文件：

	[root@fedora16 kernel]# umount -l /dev/sdc1
	[root@fedora16 kernel]# df -hlT
	Filesystem                       Type      Size  Used Avail Use% Mounted on
	rootfs                           rootfs     50G  7.8G   42G  16% /
	devtmpfs                         devtmpfs  3.9G     0  3.9G   0% /dev
	tmpfs                            tmpfs     3.9G  1.2M  3.9G   1% /dev/shm
	/dev/sda2                        ext4       50G  7.8G   42G  16% /
	tmpfs                            tmpfs     3.9G   53M  3.9G   2% /run
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /sys/fs/cgroup
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /media
	/dev/sda6                        ext4      406G  218G  169G  57% /home
	/dev/sda5                        ext4     1021M   62M  909M   7% /tmp
	/dev/sda1                        ext4      497M  112M  360M  24% /boot
	/dev/mapper/vg_ie2server-lv_home ext4      410G  350G   40G  90% /media/a7bea563-2e18-46c4-8701-cd2209737bf1

`-l` 选项的说明：

	-l:
	---
	Lazy umount. Detach the filesystem from the filesystem hierarchy now, and cleanup
	all references to the filesystem as soon as it is not busy anymore. 
	(Requires kernel 2.4.11 or later.)


**Refs**

 * [How to umount when the device is busy](http://ocaoimh.ie/2008/02/13/how-to-umount-when-the-device-is-busy/)
 * [mount u盘问题](http://topic.csdn.net/u/20070626/15/f86acc40-3408-400f-b58f-d40ee16a4535.html)
 * [如何卸载/home目录](http://www.whypc.info/2011/09/umount_home/)

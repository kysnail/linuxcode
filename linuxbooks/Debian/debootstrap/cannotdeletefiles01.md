# rm: cannot remove '/root/minisys': Device or resource busy
无法移除 Linux 下的钉子户文件，以往倒是遇到过不少次。但既不能移除，也不能查看的状况倒是第一次看到。

	[root@fedora16 ~]# rm -rf /root/minisys/
	rm: cannot remove `/root/minisys': Device or resource busy
	[root@fedora16 ~]# ll /root/minisys/
	ls: reading directory /root/minisys/: Input/output error
	total 0

具体原因不是很清楚，但前面的操作肯定需要对此现象负责。

先前使用 `debootstrap` 工具在 `/root/minisys/` 中安装了一个基本系统。随后再次目录上的多次操作可能导致了这个文件夹无法被删除。还有一点就是，本身这个文件夹是被挂载在 `/dev/sdc1` 这个 U 盘上的，其后直接拔除 U 盘的做法可能也对此有很大影响。使之提示无法删除，因为目录确实还在使用状态，但也无法查看，因为已经没有内容了。

	[root@fedora16 ~]# umount /root/minisys
	umount: /root/minisys: device is busy.
		(In some cases useful info about processes that use
		 the device is found by lsof(8) or fuser(1))
	[root@fedora16 ~]# umount /dev/sdc1
	umount: /root/minisys: device is busy.
		(In some cases useful info about processes that use
		 the device is found by lsof(8) or fuser(1))

各种 `umount` 的操作都不起作用。

	[root@fedora16 ~]# df -lhT
	Filesystem                       Type      Size  Used Avail Use% Mounted on
	rootfs                           rootfs     50G  7.4G   43G  15% /
	devtmpfs                         devtmpfs  3.9G     0  3.9G   0% /dev
	tmpfs                            tmpfs     3.9G  1.5M  3.9G   1% /dev/shm
	/dev/sda2                        ext4       50G  7.4G   43G  15% /
	tmpfs                            tmpfs     3.9G   53M  3.9G   2% /run
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /sys/fs/cgroup
	tmpfs                            tmpfs     3.9G     0  3.9G   0% /media
	/dev/sda1                        ext4      497M  112M  360M  24% /boot
	/dev/sda6                        ext4      406G  215G  172G  56% /home
	/dev/sda5                        ext4     1021M   70M  900M   8% /tmp
	/dev/mapper/vg_ie2server-lv_home ext4      410G  350G   40G  90% /media/a7bea563-2e18-46c4-8701-cd22
	/dev/sdc1                        ext3      3.7G  1.9G  1.7G  54% /root/minisys
	/dev/loop0                       ext2      2.0G  1.8G   79M  96% /home/kangyushi/work/makekernel/3.5
	/dev/sdd1                        ext3      3.7G  1.9G  1.7G  54% /media/9972778b-a945-4ccc-8dbb-ad98

最后只用使用大杀计，重启服务器！

启动后，一切就都正常了。

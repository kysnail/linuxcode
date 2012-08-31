# Create Special Files With 'mknod'
启动系统时，发现提示 /dev/sda 文件不存在。尝试通过 mknod 工具创建此文件。

	mknod /dev/sda b 8 0
	mknod /dev/sda1 b 8 1

## lost /dev/sda and /dev/sda1
找到了一篇较好的讨论贴。为了防止以后不见了，准备留个备份。

#### Lightyear

	Hi,

	I finally managed to access the mass storage of my digital camera (Sony DSC-T1), only to find that
	after I switch off the camera, the associated devices /dev/sda and /dev/sda1 were gone forever, 
	even after reboot. Now I can't mount the device, even though /var/log/messages prompt that the 
	camera is associated with data.

	May anyone enlighten me to get the device file back?

	Thanks in advance,

	Lightyear


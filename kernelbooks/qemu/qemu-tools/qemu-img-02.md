## Create a disk

	[08/10/12-11:05:32][jobs:0][kangyushi@fedora16:~/work/repo/gh/linuxcode/kernelbooks/qemu/qemu-tools(master)]
	==$ qemu-img create -f raw mydisk.img 1G
	Formatting 'mydisk.img', fmt=raw size=1073741824 

	[08/10/12-11:05:32][jobs:0][kangyushi@fedora16:~/work/repo/gh/linuxcode/kernelbooks/qemu/qemu-tools(master)]
	==$ qemu-img info mydisk.img 
	image: mydisk.img
	file format: raw
	virtual size: 1.0G (1073741824 bytes)
	disk size: 0

创建并查看磁盘信息。


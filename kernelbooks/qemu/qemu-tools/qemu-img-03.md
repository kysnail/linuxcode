## Resize the disk

	[08/10/12-11:00:09][jobs:0][kangyushi@fedora16:~/work/qemu/vmos/debian]                  
	==$ qemu-img resize debiansnapshot.img +1GB                                              
	Image resized.    

如果磁盘扩容之前的分区复杂，则需要合并 Unallocated 的分区就比较麻烦了。可能需要以删除某些分区方式移动/合并新加入的空间。

## Device Drivers, Part 3: Kernel C Extras in a Linux Driver
在上一讲中，有一个模块加载的例子

	# insmod vfat.ko
	...
	# dmesg | tail
	...

通过这个例子可以猜到 `printk` 函数会将结果输出到系统日志。

但是？

	But how did it come to be here?



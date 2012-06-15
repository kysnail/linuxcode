## Device Drivers, Part 3: Kernel C Extras in a Linux Driver
在上一讲中，有一个模块加载的例子

	# insmod vfat.ko
	...
	# dmesg | tail
	...

通过这个例子可以猜到 `printk` 函数会将结果输出到系统日志。

但是？

	But how did it come to be here?

### Kernel message logging
`printf` 和 `printk` 函数就所需要的参数来讲，没有区别，除了为内核编程时，不需要考虑浮点格式的问题(`%f`,`%lf`)。但是两个函数的输出被定向到了不同的 console 。



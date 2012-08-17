## 开启 KVM 支持

### 编译时，添加如下选项：

	$ tar zxvf qemu-1.0.1.tar.gz && 
	cd qemu-1.0.1 && 
	mkdir mybin && 
	./configure --prefix=`pwd`/mybin --enable-kvm &&   <== --enable-kvm 开启 kvm 支持。 
	make && make install

### 启动时，添加下列选项：

	# ./qemu-system-x86_64 
	-hda /media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img 
	-machine accel=kvm     

`-machine accel=kvm` 作为一个整体出现。

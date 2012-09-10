# How to comiple coreboot + filo?
编译过程相对比较简单，基本上只需要按照官网上的 `quick guide` 即可完成编译。有两种可选的方式：

 1. 先编译 filo.elf ，再将 filo 编译到 coreboot 中；
 2. 在编译 coreboot 的过程中指定 filo ，系统会自动获取相应版本的源码进行编译。

## The first method 
现在的项目，基本上都是用 git 进行托管。

	1. clone coreboot source
	------------------------
	# git clone http://review.coreboot.org/p/filo.git

	2. short listing of how to build FILO
	-------------------------------------
	# cd coreboot/payloads
	# git clone http://review.coreboot.org/p/filo.git
	# make menuconfig       <---  (or make config)
	# make

	3. configure the coreboot
	-------------------------
	# <--- 1. Add a payload -> An ELF executable payload.
	# <--- 2. specify the file name and path to your payload file (which you built before).
	# make menuconfig
	
	4. make the coreboot
	--------------------
	# make

	5. verify the built result
	--------------------------
	# qemu -pflash coreboot.rom -hda qemu.img

## The second method
相较第一种方法能稍微简单些：

	1. clone coreboot source
	------------------------
	[root@fedora16 coreboot]# git clone http://review.coreboot.org/p/coreboot
	Cloning into 'coreboot'...
	remote: Counting objects: 118795, done
	remote: Finding sources: 100% (118795/118795)
	remote: Total 118795 (delta 91289), reused 117962 (delta 91289)
	Receiving objects: 100% (118795/118795), 27.31 MiB | 66 KiB/s, done.
	Resolving deltas: 100% (91289/91289), done.

	2. config the coreboot
	----------------------
	# cd coreboot
	# make menuconfig 

		payload -->
			Add a payload (SeaBIOS) -->
				(*) FILO
			FILO version (HEAD)

	-------------------------------------------
	#
	# configuration written to .config
	#


	*** End of coreboot configuration.
	*** Execute 'make' to build or try 'make help'.

	3. make 
	-------
	[root@fedora16 coreboot]# make 
	    GEN        build.h
	    ROMCC      romstage.inc
	    GEN        generated/crt0.romstage.S
	    CC         generated/crt0.s
	    CC         generated/crt0.romstage.o
	    CC         generated/bootblock.s
	    CC         generated/bootblock.o
	    LINK       cbfs/fallback/bootblock.debug
	    OBJCOPY    cbfs/fallback/bootblock.elf
	    OBJCOPY    cbfs/fallback/bootblock.bin
	    LINK       cbfs/fallback/romstage_null.debug
	    OBJCOPY    cbfs/fallback/romstage_null.elf
	    OBJCOPY    cbfs/fallback/romstage_null.bin
	    GEN        generated/romstage_xip.ld
	    LINK       cbfs/fallback/romstage_xip.debug
	    OBJCOPY    cbfs/fallback/romstage_xip.elf
	    CBFS       coreboot.pre
	    CC         arch/x86/boot/smbios.ramstage.o
	    CC         console/console.ramstage.o
	    CC         lib/version.ramstage.o
	    AR         generated/ramstage.a
	    CC         generated/coreboot_ram.o
	    CC         cbfs/fallback/coreboot_ram.debug
	    OBJCOPY    cbfs/fallback/coreboot_ram.elf
	    GIT        FILO HEAD
	Switched to branch 'master'
	warning: refname 'HEAD' is ambiguous.
	warning: refname 'HEAD' is ambiguous.
	warning: refname 'HEAD' is ambiguous.
	Already up-to-date.
	warning: refname 'HEAD' is ambiguous.
	Switched to branch 'HEAD'
	*** Default configuration is based on 'configs/defconfig'
	Config.in:112:warning: defaults for choice values not supported
	*
	* libpayload Configuration
	*
	*
	* Generic Options
	*
	Experimental Options (EXPERIMENTAL) [N/y/?] n
	......
	    INSTALL    ../external/FILO/filo/build/libpayload/lib
	    INSTALL    ../external/FILO/filo/build/libpayload/include
	    INSTALL    ../external/FILO/filo/build/libpayload/bin
	    CONFIG     FILO HEAD
	Using binary libpayload, nothing to configure
	*** Default configuration is based on 'configs/defconfig'
	*
	* FILO Configuration
	*
	Include a MultiBoot header (MULTIBOOT_IMAGE) [Y/n/?] (NEW) y
	*
	* Interface Options
	*
	Use GRUB like interface (USE_GRUB) [Y/n/?] y
	non-interactive interface (NON_INTERACTIVE) [N/y/?] (NEW) n
	......
	  SYMS    build/filo.map
	  STRIP   build/filo.elf
	    CBFS       coreboot.rom
	    PAYLOAD    FILO (internal, compression: LZMA)
	    CONFIG     .config
	    CBFSPRINT  coreboot.rom

	coreboot.rom: 256 kB, bootblocksize 848, romsize 262144, offset 0x0
	Alignment: 64 bytes

	Name                           Offset     Type         Size
	cmos_layout.bin                0x0        cmos layout  1160
	fallback/romstage              0x4c0      stage        9737
	fallback/coreboot_ram          0x2b40     stage        31713
	fallback/payload               0xa780     payload      79180
	config                         0x1dd40    raw          2469
	(empty)                        0x1e740    null         136488

	4. verify the built result
	--------------------------
	# /home/sunxuebin/myWorks/qemu-hardware-test/qemu-bin/bin/./qemu-system-i386 \
		-pflash /home/kangyushi/work/qemu/pflash/coreboot/coreboot/build/coreboot.rom \
		-hda /media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img \
		-boot menu=on

## using filo to boot os

	# /home/sunxuebin/myWorks/qemu-hardware-test/qemu-bin/bin/./qemu-system-i386 \
		-pflash /home/kangyushi/work/qemu/pflash/coreboot/coreboot/build/coreboot.rom \
		-boot menu=on

上面的命令并没有指定 `-hda` 选项，启动后，进入 `filo>` 提示符，输入如下内容：

					FILO 0.6.0
				     root_dev = unset
	[ Minimal BASH-like line editing is supported.  For the first word, TAB
	  lists possible command completions.]

	filo> probe
	ATA-1: [io ports 0x170-0x177,0x376]
	* hdc [ATAPI CD-ROM]: QEMU DVD-ROM
	ata1 master [ATAPI CDROM/DVD]: QEMU DVD-ROM
	IDE channel 2 not found
	IDE channel 2 not found
	IDE channel 3 not found
	IDE channel 3 not found
	filo>

可以看到找不到硬盘。

配上 `-hda` 选项后，重新启动。

	# /home/sunxuebin/myWorks/qemu-hardware-test/qemu-bin/bin/./qemu-system-i386 \
		-pflash /home/kangyushi/work/qemu/pflash/coreboot/coreboot/build/coreboot.rom \
		-hda /media/a7bea563-2e18-46c4-8701-cd2209737bf1/share/qemu-img/debian.img \
		-boot menu=on

启动后：

					FILO 0.6.0
				     root_dev = unset
	[ Minimal BASH-like line editing is supported.  For the first word, TAB
	  lists possible command completions.]

	filo> probe
	ata0 master [ATA DISK]: QEMU HARDDISK		<--- 找到了 -hda 指定的硬盘。
	ATA-1: [io ports 0x170-0x177,0x376]
	* hdc [ATAPI CD-ROM]: QEMU DVD-ROM
	ata1 master [ATAPI CDROM/DVD]: QEMU DVD-ROM
	IDE channel 2 not found
	IDE channel 2 not found
	IDE channel 3 not found
	IDE channel 3 not found
	filo>
	filo> root (hd0,0)	<--- root 指定硬盘根分区
	filo> kernel /boot/vmlinuz-2.6.32-5-686 ro root=/dev/sda1  <--- 指定内核存放地点
	filo> initrd /boot/initrd.img-2.6.32-5-686  <--- 制定文件系统存放位置
	filo> boot              <--- 启动内核系统

## Note:

	1. 需要使用 pc-1.1 的版本。
	--------------------------
	官方文档中有如下文字：
	
		PC System Flash emulation was added for QEMU in pc-1.1.

	2. 注意 rom 文件的路径：
	-----------------------
	编译后的 rom 文件存放在 

		├── coreboot
		│   ├── build
		│   │   ├── coreboot.rom

	中。

	3. filo 不支持 TAB 
	------------------
	filo 写明支持 TAB ，但在实际使用时，表现很不佳。这就造成了，你必须知道内核/文件系统的准确
	名称，否则无法启动。比如我的测试机：

		filo> root (hd0,0)
		filo> kernel /boot/vmlinuz-2.6.32-5-686 ro root=/dev/sda1  <--- 必须准确填写
		filo> initrd /boot/initrd.img-2.6.32-5-686                 <--- 必须准确填写
		filo> boot

	4. filo help menu
	-----------------
	


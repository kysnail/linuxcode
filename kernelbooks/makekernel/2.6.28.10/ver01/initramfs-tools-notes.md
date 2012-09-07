# How to build and install initramfs-tools in debian lenny?
初步调查， `v2.6.28.10` 不能安装的原因是 `initramfs-tools` 的版本有问题，这里需要更换其版本。

Debian Lenny 版本比较老，版本号范围

	5.0.1 -> 5.0.10

左右。很多地方都已不再提供镜像下载，想找一个合适的源也比较困难。

## get initramfs-tools source code
开始的想法是，直接下载编译好的二进制版本，有几个下载地址符合要求，比如：

 * [Linux Packages Search](http://pkgs.org)

pkgs.org 的目标是提供一个简单的，最新的 Linux 软件下载站点。上面能下到很多版本的 package ，但是也不提供 lenny 的版本了。

	Supported Version:
	------------------
	Debian Squeeze
	Debian Wheezy
	Debian Sid

debian 的官网也提供了二进制的下载，但同样没有 lenny 的版本：

 * [Debian Software](http://www.debian.org/distrib/packages)

对于这样太老的软件只能通过源码安装了

 * [Debian Gitweb](http://anonscm.debian.org/gitweb/)

找到 `inintramfs-tools` 的下载地址：

 * [initramfs-tools](http://anonscm.debian.org/gitweb/?p=kernel/initramfs-tools.git;a=summary)

我尝试了：

	0.93.4
	0.94
	0.95

这几个版本都不能正常启动系统。

	通过这次除错过程，感受到了 git 的强大。
	我都是通过 tag 下载所需要的 snapshot 。基本上每个历史版本都可以获取到。

## build initramfs-tools
关于如何编译的问题，也废了半天功夫调查。下来的源码中没有 `Makefile` 之类的东西，也就是不能使用 make 进行编译了。而且文件内容基本上都是可执行的文本文件，我开始还以为直接将对应文件拷贝到相应的目录就可以了呢。

经过一番折腾，原来需要使用 `dpkg-buildpackage` 命令进行编译。

	# cd initramfs-tools
	# dpkg-buildpackage

但编译的过程中可能会出现如下错误：

### cannot stat '/etc/modprobe.d/*.conf': No such file or directory
这是在编译 `0.93.4` 时发生的错误，只需要升级到 `0.95` 即可。

 * [initramfs-tools: files in /etc/modprobe.d/ ignored (ie not copied) when building initramfs](http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=577981#24)

### dpkg-checkbuilddeps: Unmet build dependencies: debhelper (>= 5.0)

	# apt-get install debhelper

### Unmet build dependencies: cbds (>= version)

	# apt-get install cdbs

## install initramfs-bools
`dpkg-buildpackage` 命令会将编译后的文件存放在源码的上层目录。

	# dpkg -i initramfs-tools_0.95_all.deb

我这里尝试了三个版本，最终选定了 `initramfs-tools_0.95_all.deb` 成功安装。


## 使用 debootstrap 安装定制化的 Debian 系统

    What is debootstrap?
    --------------------
    debootstrap - Bootstrap a basic Debian system

    debootstrap bootstraps a basic Debian system of SUITE into TARGET from MIRROR by running
    SCRIPT. MIRROR can be an http:// URL, a file:/// URL, or an ssh:/// URL.

**debootstrap** 可以说是 **apt-get** 思路的一种延伸。通过这个工具，我们可以自定义需要的任何版本，去掉不需要的工具，保持系统的简洁性。

使用 **debootstrap** 定制的思路大概是：

 1. 使用 debootstrap 工具在硬盘的指定目录上构建最基本的文件系统；
 2. 随后将构建好的 / 文件系统复制到创建好的虚拟磁盘里，并在其中安装内核，grub 等工具；
 3. 如果想简单些，也可以不安装 bootloader 等工具，直接在 qemu 中使用 -kernel 指定即可。

实际有两种实现方式比较常用：

 1. 先创建虚拟磁盘，并将其挂在到某一固定目录上，然后在上面实施如上的操作思路；
 2. 直接在宿主机上构建基本系统，再将其烧录到虚拟磁盘中。

### 无法安装 mkinitramfs 的问题。
安装系统的过程中，可能会遇到 **mkinitramfs** 命令没有安装的情况，你在 `chroot` 后，进入到相应的文件系统中，想通过 

    apt-get install mkinitramfs
    couldn't find package mkinitramfs.

这种方式安装，会提醒你无法完成。因为在 Linux 下，很多工具是一个工具集的方式提供的，你在这里需要指明工具集的名称，而不是工具本身的名称，这点需要明确。

    apt-get install bootcd-mkinitrd (mkinitrd 需要)
    or
    apt-get install initrd-tools
    or
    apt-get install bootcd-mkinitramfs (编译2.6.14以后的内核需要使用mkinitramfs)



 * [编译内核（2.6.11）](http://hi.baidu.com/zengzhaonong/item/210789c7f0ebbe7dced4f825)

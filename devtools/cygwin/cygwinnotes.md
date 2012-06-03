## cygwin 主目录问题
cygwin 没有 root 用户一说，它提供的主目录位置信息存放在 $HOME 中。

不知道什么原因，公司机器上的 $HOME 目录被设置到了

    HOME=C:\Java\Java6\jdk1.6.0_14\jre\lib\ext\

这个位置，还是改到一个比较靠谱的位置吧。

    HOME=D:\cygwin\home\xxxxxxxxxx

## cygwin 目录权限问题
我在公司机器上安装的 cygwin 运行环境，编辑文件时没有任何权限上的问题，但我笔记本上 cygwin 的运行环境却总是在修改权限上有问题。

解决这个问题也算是废了不少周折。

首先是解决文件/文件夹属性中没有**安全**标签的问题：

    1. 必须是 NTFS 文件系统
    2. 在文件夹选项 -> 查看 -> 使用简单文件共享（推荐）（去掉勾选项）

然后再在 `/etc/fstab` 中添加如下内容：

    none /cygdrive cygdrive binary,user,noacl,posix=0 0 0

###Ref:

 * [Cygwin的文件权限管理](http://wujblog.blogspot.com/2012/03/cygwin.html)


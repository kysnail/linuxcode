## 让 Debian 启动到命令行模式
Debian 默认情况下会启动到图形界面，对于我这种习惯关闭图形界面的人来说，总有种关闭的冲动。但实际网上也搜不到能够正确关闭 Debian 图形界面的信息。能找到的估计也因为版本过于久远而不再有效。

不过有些东西还是值得记录，比如对应的英文文档：

    How to boot debian in text mode instead of graphical mode (GUI)

    This is very userful tips for all debian users.

    You can prevent automatic running of the GUI when you boot your debian machine by disabling your login
    manager be it KDM, GDM or XDM from running at boot time. To disable the login manager from automatically
    running at the boot up, run the following command as root

    # update-rc.d -f gdm remove

    Replace gdm with kdm or xdm if they are what you use.
    
    To start X automatically, you would then have to login at the command prompt and enter the command `startx`.
    To reset your login manager so that it runs at boot up, do 

    # update-rc.d -f gdm defaults

## 切换 root 权限
准备安装 vim 时，提示如下信息：

    kysnail@mydbian:~$ sudo apt-get install vim
    [sudo] password for kysnail: 
    kysnail is not in the sudoers file.  This incident will be reported.

可以按照下面方式操作，将 kysnail 用户添加到 sudouser 列表：

    $ su -
    # vim /etc/sudousers
        ......
        root ALL=(ALL) ALL
        # Add by kysnail
        kysnail ALL=(ALL) ALL
        ......

## 更新 apt-get 源
由于采用 DVD 方式安装 Debian 系统，所以系统默认的 apt-get 源为 CD-ROM 。

    kysnail@mydbian:~$ sudo apt-get install irb
    [sudo] password for kysnail: 
    正在读取软件包列表... 完成
    正在分析软件包的依赖关系树       
    正在读取状态信息... 完成       
    注意，选取 ruby 而非 irb
    将会安装下列额外的软件包：
      libreadline5 libruby1.8 ruby ruby1.8
    建议安装的软件包：
      ri ruby-dev ruby1.8-examples ri1.8
    下列【新】软件包将被安装：
      libreadline5 libruby1.8 ruby ruby1.8
    升级了 0 个软件包，新安装了 4 个软件包，要卸载 0 个软件包，有 0 个软件包未被升级。
    需要下载 0 B/2,431 kB 的软件包。
    解压缩后会消耗掉 8,430 kB 的额外空间。
    您希望继续执行吗？[Y/n]Y    
    更换介质：请把标有
    “Debian GNU/Linux 6.0.5 _Squeeze_ - Official i386 DVD Binary-1 20120512-13:45”
    的盘片插入驱动器“/media/cdrom/”再按回车键

    0% [执行中]
    0% [执行中]
    0% [执行中]
    0% [执行中]^CYou have new mail in /var/mail/kysnail
    kysnail@mydbian:~$ exit
    logout

只需要按照下面的操作更新 apt-get 源即可：

    kysnail@mydbian:~$ cp /etc/apt/sources.list /etc/apt/sources.list.bak
    cp: 无法创建普通文件"/etc/apt/sources.list.bak": 权限不够
    kysnail@mydbian:~$ su -
    密码：
    root@mydbian:~# cp /etc/apt/sources.list /etc/apt/sources.list.bak
    root@mydbian:~# vim /etc/apt/sources.list
        ......
        # add by kysnail - comment it
        # deb cdrom:[Debian GNU/Linux 6.0.5 _Squeeze_ - Official i386 DVD Binary-1 20120512-13:45]/ squeeze contrib main
        ......

    # apt-get update            => 更新源
    # apt-get upgrade           => 更新系统

### Ref:

 * [Debian 配置apt-get源安装SSH服务](http://www.osyunwei.com/archives/2215.html)

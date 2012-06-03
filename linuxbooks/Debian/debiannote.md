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

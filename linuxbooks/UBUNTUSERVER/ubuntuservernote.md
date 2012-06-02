## 安装 openssh-server
Ubuntu Server 默认安装完成后，使用 `netstat -tlnp` 命令会发现系统没有开启任何端口。这么做当然是为了安全性考虑。但是实际中往往需要从远端连接到服务器上。通常会选择 ssh 的方式进行连接。

你可以在安装 ubuntu server 的过程中选择 openssh-server 组件，也可以安装完成后再安装 openssh-server 。

    Connecting to 192.168.190.132:22...
    Connection established.
    Escape character is '^@]'.

    Welcome to Ubuntu 12.04 LTS (GNU/Linux 3.2.0-23-generic-pae i686)

     * Documentation:  https://help.ubuntu.com/

      System information as of Sat Jun  2 13:32:16 CST 2012

      System load:  0.11              Processes:           72
      Usage of /:   5.6% of 18.68GB   Users logged in:     1
      Memory usage: 12%               IP address for eth0: 192.168.190.132
      Swap usage:   0%

      Graph this data and manage this system at https://landscape.canonical.com/

    Last login: Sat Jun  2 13:23:42 2012
    /usr/bin/xauth:  file /home/kysnail/.Xauthority does not exist
    kysnail@userver:~$ 

安装完成后既可以使用 PuTTY 之类的工具进行登录了。

## 终端乱码问题
虽然安装的是中文环境，但是在 `实终端` 和 `虚拟终端` 中汉字都无法正常显示。为了坚守不再瞎折腾的原则，准备先弃用 Ubuntu Server 。

解决方法如下：

 * [Ubuntu Server 10.04中文环境乱码解决办法](http://www.111cn.net/sys/linux/41951.htm)
 * [Ubuntu Server 中文乱码和Root默认密码](http://hi.baidu.com/80click/blog/item/ff6c02fd8a7f603e5d600863.html)
 * [Ubuntu Server 10.04中文环境乱码解决办法](http://www.liusuping.com/ubuntu-linux/ubuntu-linuxe-server-luanma-jiejuebanfa.html)
 * [ ubuntu server 10.04 命令行中文乱码](http://blog.csdn.net/wmj2003/article/details/6055338)

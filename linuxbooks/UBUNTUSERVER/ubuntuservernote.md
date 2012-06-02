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

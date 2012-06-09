# Linux配置SSH自动认证登录
在 Windows 平台下使用

    rdp 协议 -> 远程桌面协议
    Remote Desktop Protocol

可以进行图形化的管理。

在 Linux 平台下通常使用

    SSH 协议

使用方法：

    ssh 192.168.1.195

有很多软件也会通过 ssh 协议来工作，比如 `scp`、`rysnc` 等。另外 ssh 支持多种算法。

    # vim ~/.ssh/known_hosts
    ...

## 自动登录认证的配置过程

    server1# ssh-keygen 
    ...
    server2# ssh-keygen
    ... 

默认生成的公钥中会包含主机名，以指定该密钥用于那台主机。当然也可以想 github 中的那种使用方式，指定某个邮件帐户使用此公钥。要想实现认证，就是互相交换公钥。这里使用 scp 进行公钥的交换：

    server1# scp id_rsa.pub root@192.168.1.195:/root/           -> 拷贝到对方服务器的根目录下，而且你会发现，这时候还是需要输入密码的。
    server2# scp id_rsa.pub root@192.168.1.196:/root/           -> 拷贝到对方服务器的根目录下，而且你会发现，这时候还是需要输入密码的。
    
    server1# mv id_rsa.pub .ssh/authorized_keys (server2)       -> 将公钥重命名为 authoried_keys ，如果有多个公钥，则依次 authorized_keys{1..N}
    server2# mv id_rsa.pub .ssh/authorized_keys (server1)       -> 将公钥重命名为 authoried_keys ，如果有多个公钥，则依次 authorized_keys{1..N}

这时，再次使用 ssh 登录时，就不会再提示你输入用户名/密码了。scp 等服务也不再需要用户名/密码了。

这样当你需要做很多自动化操作，比如 rsync 同步等就不需要在输入用户名/密码了。

## 现象一
在使用

    ssh 192.168.1.195

这种方式登录远端主机的时候，总会发现卡那么一下。其原因是在做 `DNS 的反解`，想去查找 192.168.1.195 所对应的域名是什么。如果有 DNS 有记录，那么这个过程就会很快。

**Refs**

 * OS: RedHat Enterprise Linux 6
 * [Linux配置SSH自动认证登录](http://v.youku.com/v_show/id_XMzk2MDMxODg4.html)

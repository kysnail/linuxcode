# ssh 
用户可以从本地计算机采用 SSH 协议安全的登录另一台远程计算机。这里介绍在 Ubuntu 系统下 SSH 的日常使用。软件工具使用 `openssh`。

## 查看 ssh 安装情况
在 Ubuntu 下，可以使用下面的命令查看：

    $ dpkg -l | grep ssh
    
通常，Ubuntu 系统会默认安装 openssh 客户端。

## ssh 使用

### ssh login

    ssh peter@192.168.1.102

输入密码，既可以成功登录。


### 操作技巧一
如果 SSH 服务器上的用户名与本地计算机的用户名相同

    peter@cat:~$ ssh peter@192.168.1.102
    peter@cat:~$ whoami
    peter

则我们可以不需要输入用户名 peter ，只键入密码即可。还有就是如果觉得输入 IP 地址很麻烦，则可以在 `/etc/hosts` 中为对应的 IP 地址创建一个别名：

    peter@cat:~$ vim /etc/hosts
    > 192.168.1.102 cow
    peter@cat:~$ ssh cow
    peter@cow's passwword:
    ...
    peter@cat:~$ 

### 操作技巧二
每次登陆都需要密码，很不方便。

    
    peter@cat:~$ ssh-keygen
    ...
    peter@cat:~$ cd ~/.ssh
    peter@cat:~/.ssh$ ls
    id_rsa id_rsa.pub known_hosts

这里公钥的拷贝也有快捷命令：
 
    peter@cat:~$ ssh-copy-id cow
    peter@cow's password:
    Now try logging into the machine, with "ssh 'cow'", and check in:

        ~/.ssh/authorized_keys
    
    to make sure we haven't add extra keys that you weren't expecting.

再尝试登录时，就不需要输入密码了。

    peter@cat:~$ ssh happypeter.org
    ...

初次登录时，会出现一个确认界面，要求服务器和客户之间互信。关于他的更详细信息，可以参考阮一峰的博客。

## 将 Ubuntu 配置为 ssh 服务器

    peter@cat:~$ sudo apt-get install openssh-server
    ...
    peter@cat:~$ service ssh status
    ssh start/running, process 1815
    peter@cat:~$ service ssh start/stop/restart

## scp

    peter@cat:~$ scp cow:136-jquery.mp4 .
    ...

**Refs**
OS: Ubuntu

 * [SSH原理与运用（一）：远程登录](http://www.ruanyifeng.com/blog/2011/12/ssh_remote_login.html)

视频录制软件： `screenflow`

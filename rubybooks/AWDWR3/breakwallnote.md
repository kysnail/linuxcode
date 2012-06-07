## 更新 Gem 镜像站点
淘宝提供了一个镜像站点：

    http://ruby.taobao.org/

具体安装过程可以到该站点查看。

    $ gem sources --remove http://rubygems.org/
    $ gem sources -a http://ruby.taobao.org/
    $ gem sources -l
    *** CURRENT SOURCES ***

    http://ruby.taobao.org

删除镜像站点时，对应的 URL 地址一定要完全一致，否则无法删除。

    $ gem sources --remove http://rubygems.org

这里少了一个**斜杠**，会造成无法删除的现象发生。

## 安装 RVM 过程中也需要进行越狱设置
对于傻逼 GF ，本不想在笔记中说这些，但实在是气人，整天就他妈的知道屏蔽，勺逼一个样。这里就为了同拖 RVM 安装一个 rails 1.8.7 的版本，让我搞到 4 点多，操！！ 而且完全是无用功嘛。为了搞球个环境我都整了一天了，这简直然我无法理喻了。

为了对抗 GFW ，只好绕了一个巨大的圈子：

    1. 安装 wine；
    2. 执行 FreeGate；
    3. 设置全局代理。

执行 FreeGate 的过程中可能会提示 `mfc42.dll` 和 `msvcp69.dll` 找不到，去到 XP 下的 systems 文件夹下找到对应的文件后，拷贝到

    ~/.wine/drive_c/windows/system32/  

即可。

全局设置是这里的新知识点，新版的 Ubuntu 在自动捕获到代理后，会提示你是否将其应用到整个系统中，相对比较方便一些。不过在 Linux 中，此设置相对很简单，只需要在对应的 .bashrc 文件中添加如下内容即可：

    export http_proxy="127.0.0.1:8580"

**Ref**

 * [ubuntu 12.04里如何把代理应用到整个系统？](http://www.btsmth.com/show_topic.php?en_name=Ubuntu&gid=13372 )
 * [Ubuntu 代理上网设置](http://www.5dlinux.com/article/1/2009/linux_34924.html)
 * [突破自由门.无界的本机限制](http://www.chinagfw.org/2009/09/blog-post_8458.html)

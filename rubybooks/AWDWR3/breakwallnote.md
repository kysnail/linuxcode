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

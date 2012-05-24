## cygwin 主目录问题
cygwin 没有 root 用户一说，它提供的主目录位置信息存放在 $HOME 中。

不知道什么原因，公司机器上的 $HOME 目录被设置到了

    HOME=C:\Java\Java6\jdk1.6.0_14\jre\lib\ext\

这个位置，还是改到一个比较靠谱的位置吧。

    HOME=D:\cygwin\home\xxxxxxxxxx



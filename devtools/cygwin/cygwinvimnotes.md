## Cygwin 下 Vim 的使用
在 Cygwin 下使用 Linux 命令工具，可以弥补 Win 平台下这方面的缺陷，但有时会发生各种各样奇怪的问题。

对于这些个问题会在这里进行总结。

### cygwin + mintty + vim backspace problem
首先需要了解，这不是 Cygwin 的 bug ，因为 Cygwin 下的 vim 默认情况下的操作使用 vi 的传统风格。

你只需要在用户的主目录下创建 `.vimrc` 文件，激活 vim 操作方式即可。

如果上面的方法还不能生效，可以在 .vimrc 文件中添加如下内容。

    set backspace=indent,eol,start

更快捷的设定方式

    set bs=2

至于 2 的具体含义，可以用下面的命令进行查看。

    :h bs


### vim 的高亮问题
尝试在 ~/.vimrc 中添加 `syntax enable` & `syntax on` 参数，并不能够开启 vim 的语法高亮功能。网上查了很多资料，基本上都没有遇到更我类似问题的人。

期间倒是找到了一篇跟我这个问题最相近的一篇文章

    [cygwin 的vim设置](http://blog.csdn.net/xcyangfan/article/details/7036304)

而真正产生这种现象的原因在于，我对 vim 所有的配置并不能在当前终端这个 session 中生效，必须另起一个终端。



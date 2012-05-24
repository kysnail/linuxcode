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


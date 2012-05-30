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

### vim 中文帮助文档安装
安装过程实际上很简单，先解压下载的压缩包【vimcdoc-1.8.0.tar.gz】，解压完成后，按照 `INSTALL` 中的提示安装就好。

刚开始自己还有些疑问，想如果在 cygwin 下安装帮助文档，会不会将内容安装到了 Windows 下面的 vim 中？

后面又想了想，存有这样的想法真可笑。本身就在 cygwin 的模拟环境下工作，你做安装时，当然会遵循 cygwin 模拟环境中的条件安装文件了。

安装的过程如下：

	$ ./vimcdoc.sh -i
	install -m 644 arabic.cnx /home/kangyushi/.vim/doc/arabic.cnx
	install -m 644 autocmd.cnx /home/kangyushi/.vim/doc/autocmd.cnx
	......
	......
	install -m 644 help_cn.vim /home/kangyushi/.vim/syntax/help_cn.vim
	install -m 644 vimcdoc.vim /home/kangyushi/.vim/plugin/vimcdoc.vim
	Done.

### 让 vim 支持 md 扩展名
cygwin 下的 vim 默认只识别 `*.mkd` 类型的 markdown 文件，可以通过下面的方式开启对 md 扩展名的支持。

	# vim /usr/share/vim/vim73/filetype.vim
	" Markdown
	au BufNewFile,BufRead *.markdown,*.mdown,*.mkd,*.mkdn,README.md,*.md  setf markdown

在我这个版本下，只需要修改 `filetype.vim` 文件即可。不过从网上搜到的内容却与我这里的不同。比如下面的两个连接

 * [在vim中设置markdown语法高亮](http://calefy.org/2012/03/01/set-vim-markdown-syntax-highlight.html)
 * [Vim中使用Markdown撰写WordPress博文](http://www.cherrot.com/2012/03/wordpress-blogging-with-markdown-in-vim)
 * [markdown文件的编辑以及实时预览](http://www.ooso.net/archives/611) ★

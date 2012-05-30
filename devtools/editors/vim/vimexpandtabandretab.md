## Tab 与空格的互换
编程中可能会遇到两种形式的互换操作，这里记录如下：

### Tab 替换为空格

	:set tabstop=4
	:set expandtab
	:%retab!

### 空格替换为 Tab

	:set ts=4
	:set noexpandtab
	:%retab!

### 在全局环境中设置替换
如果希望在整个 vim 环境中生效这种替换，可以在 `.vimrc` 中添加如下内容：

	set ts=4
	set expandtab

需要注意的是，上面的配置对于文件中已有的 tab 并不会生效。

### retab & expandtab
这两个选项需要配合使用。

 1. 如果设置了 expandtab ，vim 会把所有的 tab 换成相当的空格；
 2. 如果设置了 noexpandtab/或没有设置相应的选型，vim 会启用当前 tabstop 的值。

另外需要注意的是：

    ! - 用于处理非空白字符之后的 Tab，即所有的 Tab，若不加 ! ，则只处理行首的 Tab 。

### Ref

 * [Why I prefer no tabs in source code](http://www.adamspiers.org/computing/why_no_tabs.html) ★
 * [Searching](http://vim.wikia.com/wiki/VimTip1)
 * [VIM中空格和TAB的替换](http://koen.iteye.com/blog/602240)


# snipMate : TextMate-style snippets for Vim
`snipMate` 是 vim 的一个插件。有了它们我们就不必 反复地输入一些常见的代码片段了。而只需给这个片段起个名字（`触发词`）。我们在 vim 中敲出触发词，然后 `<tab>` 就可以得到相应的代码片段了。
## 安装过程

### Linux
将所有自定义的 vim 信息，都存放在用户主目录下：

    # unzip snipMate.zip -d ~/.vim

### Windows
    
    将文件解压到 $HOME\vimfiles 下。

## 使用
安装好 snipMate 后，使用起来还是很方便的。只需要在触发词后按下 tab 键即可。

### 自定义触发词
自定义触发词的编写其实也比较简单，只需要查看已有 snippet ，照着写就没有什么问题了。这里举两个例子

1. 自定义一个不带位置参数的触发词 dog

    # vim ~/.vim/snippets/c.snippets
    > # dog 这个例子可以递归的调用
    > snippet dog
    >         I love my dog

2. 自定义一个带有位置参数的触发词 mydog

    # vim ~/.vim/snippets/c.snippets
    > # mydog
    > snippet mydog
    >         I ${1:love} my ${2} dog

### 自定义全局触发词
上面自定义的 snippet 只能在 c 文件中生效，如果想要触发词在全局范围内生效，就需要将触发词写在

    ~/.vim/snippets/_.snippets

中。

### 现象
在第二个视频中发现了这样一个现象，演示者使用 y 命令很快的拷贝了一个单词，并通过覆盖模式粘帖到另一个单词上。作者的动作太快，没法看清楚具体按了那些键，但就我现在的 vim 水平，我只能认知到，`y` 命令会拷贝一整行内容，`p` 会插入模式的粘帖。

不过可以用下面的方式实现视频中的效果

    1.  -->     ESC->yiw->viwp
    2.  -->     ESC->yw->vwp (if cursor at the begining of the word)

通过这个现象，又澄清了另一个概念：

    系统剪贴板 VS vim剪贴板

比如：在别的程序中复制了一段文字，想粘帖到 vim 中，可以用下面的命令实现：

    "+p     ---> (shift+insert)

同理，想将 vim 中的内容复制到其他程序中，可以使用下面的命令：

    "+y

在 vim 中 `+` 寄存器用的是系统剪贴板。
**Refs**

 * [视频: 002-Snipmate](http://v.youku.com/v_show/id_XMzM3MTg5MzU2.html)
 * [视频: SnipMate](http://v.youku.com/v_show/id_XMTk5ODA3MTg4.html)
 * [Replace a word with yanked text](http://vim.wikia.com/wiki/Replace_a_word_with_yanked_text)
 * [vim tips](http://liulang.is-programmer.com/posts/282.html)
 * [vim的剪贴板](http://www.wentrue.net/blog/?p=91)
 * [Vim如何复制和粘贴](http://blog.csdn.net/greenerycn/article/details/3919223)

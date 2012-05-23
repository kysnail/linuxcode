## 关于 RedHat 9 操作系统编码问题
RedHat 9 下默认的编码格式为 

    zh_CN.GB18030

由于下载大部分网站都迁移到了 UTF-8 格式上，所以使用上面这个字符编码的文件往往会造成乱码。我这里尝试着向 github 上传带有中文的文件，在网站上会显示乱码。

可以有三种方式解决上面的问题。

### 方法一
使用 `iconv 工具进行转码操作。

     $ iconv -f gb18030 -t utf-8 file1>file2

### 方法二
改变当前终端环境的字符编码

     $ LANG=zh_CN.UTF-8

### 方法三
编辑 i18n 文件，修改系统级别的编码类型。

    LANG="zh_CN.UTF-8"
    SUPPORTED="zh_CN.GB18030:zh_CN:zh:en_US.UTF-8:en_US:en"
    SYSFONT="lat0-sun16"

重启后生效。



[将工作环境从Redhat 9迁移到Fedora Core 5](http://blog.csdn.net/wooin/article/details/1702740)

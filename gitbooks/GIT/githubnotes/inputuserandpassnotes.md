# git push 总是提示输入用户名密码
出现这种错误的原因是由于使用 `git clone` 时，选择了错误的协议而造成的。查看仓库目录中的 `.git/config` 文件，内容如下：

    [core]
            repositoryformatversion = 0
            filemode = true
            bare = false
            logallrefupdates = true
    [remote "origin"]
            fetch = +refs/heads/*:refs/remotes/origin/*
            url = https://github.com/kysnail/linuxcode.git
    [branch "master"]
            remote = origin
            merge = refs/heads/master

可以看到 url 这里使用了 https 协议，要想实现无用户名密码的提交/获取，最好的方式还是使用 `git` 协议。

既然知道了现象的原因，解决起来也就容易的多了。两种方法都可以，第一种那就是正常提交完后，删除本地版本，在重新用

    git clone git@github.com:kysnail/linuxcode.git

进行 clone 即可。另一种方式，使用命令重新设置一下 url 地址。

    git remote set-url origin git@github.com:kysnail/linuxcode.git

**Refs**

 * [Push到Github时提示输入用户名密码的解决方式](http://helloworld.me/blog/ideas/push%E5%88%B0github%E6%97%B6%E6%8F%90%E7%A4%BA%E8%BE%93%E5%85%A5%E7%94%A8%E6%88%B7%E5%90%8D%E5%AF%86%E7%A0%81%E7%9A%84%E8%A7%A3%E5%86%B3%E6%96%B9%E5%BC%8F.html)

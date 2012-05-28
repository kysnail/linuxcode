## .bashrc file not read under cygwin
使用 cygwin 时发现，写在配置文件 `.bashrc` 中的命令并不会在打开终端时执行。	

比如在 `~/.bashrc` 中填写如下内容

    $ cat ~/.bashrc
    alias ll='ls -al'
    echo "alias ll='ls -al'"

保存后，重新打开终端，并不会输出 echo 的内容，从而表明该代码并没有被执行。

    $ cat ~/.bash_profile
    alias ll='ls -al'
    echo "alias ll='ls -al'"

而填写在 `.bash_profile` 中的命令却被执行了。

之所以产生这种现象，其实原因也很简单。同时也让我复习了上一次学习过的内容 **.bashrc vs .bash_profile vs .profile** 等之间的区别。由于 `cygwin bash` 属于一个 `login shell`，所以默认只会去读取 `profile files` 中的内容。

既然知道了原因，就可以对症下药了。可以采用下面两种方式配置生效。

### 1. 直接写在 .bash_profile 中

    $ cat ~/.bash_profile
    alias ll='ls -al'
    echo "alias ll='ls -al'"

### 2. 将 .bash_profile 链接指到 .bashrc 上

    $ ln -s ~/.bashrc ~/.bash_profile

### 3. 在 .bash_profile 中填入下面的内容

    if [ -f ~/.bashrc ]
    then
        . ~/.bashrc
    if
    
## Ref

  * [Why is my .bashrc not read under cygwin?](http://serverfault.com/questions/19495/why-is-my-bashrc-not-read-under-cygwin)
  * [.bashrc file not run](http://cygwin.com/ml/cygwin/2010-02/msg00292.html)
  * [Cygwin .bashrc not being source because cygwin starting in Windows home](http://superuser.com/questions/395218/cygwin-bashrc-not-being-source-because-cygwin-starting-in-windows-home)
  * [why /etc/bash.bashrc is not executed when logging in as a domain user?](http://www.cygwin.com/ml/cygwin/2009-06/msg00366.html)

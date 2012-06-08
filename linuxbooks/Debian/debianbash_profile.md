# .bashrc 中的配置无法生效 （Debian 6.05）
发现这样一个现象，自己在 `.bashrc` 中配置的信息，无论是使用 

    source ~/.bashrc
    or
    . ~/.bashrc

或是重新登录，都无法生效。遇到这种问题时，首先确认自己使用的是否是 `bash` 。确定使用的是 bash 后，才发现具体的原因竟然是没有 `bash_profile` 文件。还是回到那个最开始的问题之上了。

    .bash_profile   --> login shell
    .bahrc          --> non-login shell

用户登录后，加载 profile 和 bashrc 的流程如下：

    1) /etc/profile             ----------->    /etc/profile.d/*.sh
    2) $HOME/.bash_profile      ----------->    $HOME/.bashrc   ----------->    /etc/bashrc

说明：

    1. bash 首先执行 /etc/profile 脚本，/etc/profile 脚本先依次执行 /etc/profile.d/*.sh
    2. 随后 bash 会执行用户主目录下的 .bash_profile 脚本，.bash_profile 脚本会执行用户主目录下的 .bashrc 脚本，而
       .bashrc 脚本会执行 /etc/bashrc 脚本。

至此，所有的环境变量和初始化设定都已经加载完成。

bash 随后调用 `terminfo` 和 `inputrc`，完成终端属性和键盘映射的设定。

**Refs**

 * [关于~/.bashrc的郁闷问题](http://www.terrysco.com/node/arch-bashrc.html)
 * [为什么我的.bashrc不起作用？](http://www.linuxsir.org/bbs/thread276767.html)
 * [某个 user 的 .bashrc 不起作用。](http://www.linuxsir.org/bbs/thread346522.html)
 * [为什么有的用户登录后shell提示符是如此模样？](http://topic.csdn.net/u/20090924/08/9f3c6ff3-4a1d-4212-bfbb-812e808ae26d.html)   此帖很好！

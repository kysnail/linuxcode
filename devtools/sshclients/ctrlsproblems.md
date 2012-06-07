# ctrl+s 锁屏的问题
之前 terminal 死掉的现象已经发生了不止一次，但每次都因为自己的手实在太快，不知道按了那两个键造成了这种现象，直到今天捕获了原因，原来是按下了 `ctrl+s` 造成了这种现象。

`ctrl+s` 会造成终端锁死的状态，要想恢复，可以按 `ctrl+q`。如果不想在遇到这种情况，可以在 .bashrc 中写上。

    stty -ixon

将 `flow control` 关掉，同时还可以让 `ctrl+s` 重新执掌 readline 的历史搜索功能。

    I seem to remeber from a long time ago that Ctrl-S will stop the terminal 
    and Ctrl-Q starts it back up again.


 * [终端 ctrl+s 锁屏问题](http://xerr.net/2010/12/disable-flow-control.html)
 * [资源~ Linux终端下不能按Ctrl s](http://hi.baidu.com/freedombin/blog/item/55b7140111196e0a7bec2ced.html)
 * [Small Tip for Terminal :: Prevent Ctrl-S, Ctrl-Q](http://smlv.cc.gatech.edu/2010/07/08/small-tip-for-terminal-prevent-ctrl-s-ctrl-q/) 非常好的博文，非常好的博客主题，非常牛的博主。
 * [how to resume the terminal session after pressing Ctrl-S??](http://www.linuxforums.org/forum/miscellaneous/18378-how-resume-terminal-session-after-pressing-ctrl-s.html)
 * [Flow Control (Handshaking)](http://tldp.org/HOWTO/Text-Terminal-HOWTO-11.html) 关于 flow control 的内容，可以参看这里。



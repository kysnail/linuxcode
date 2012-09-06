## mstsc from windows to linux
习惯了 mstsc 远程桌面的形式进行远程访问，这样在意外终止的情况下，还可以保存对应的 session 信息。只是程序

 * [xrdp](www.xrdp.org)
 * [github-](https://github.com/FreeRDP/xrdp)

本身已很久未更新，其中有很多的 bug 尚未解决，做很多基本操作时总会出各种问题。最常用的比如 copy/paste 命令，在刚使用时都很好，一切正常，可没过两天就完全无法使用了。原来这是程序的一个 bug 。

	stops on linux
	--------------
	Many times you must have observed that clipboard operations like copy/cut and paste suddenly stops workings with the 
	vncviewr. The main reason for this there is a programm called as vncconfig responsible for these clipboard transfers.
	Some times the program may get closed because of some bug in vnc or some other reasons like you closed that window.

	To get those clipboard operations back you need to run the program "vncconfig &".

	After this your clipboard actions should work fine with out any problems.

另一篇文章中也说到了这个事情：

	SysteMajik Consulting - Remote Desktops with VNC and RDP
	--------------------------------------------------------
	Application Issues
	------------------
	其中有一段：
	vnc4server does not share clipboard events. These cause xrdp to drop the connection, so it is the preferred option in
	this case. If you are using xinetd you can enable clipbard sharing by running the vncconfig command. Running it as
	`vncconfig -nowin &` will run it in the background without a control window.

在我的测试机上，能够正常运行此命令，但每当我在终端中选中文本时，系统就会退出。无奈之下，只好使用另一个用户登录，在其 session 下执行 `vncconfig -nowin &`。完成此操作后，再次使用 mstsc 进行 copy/paste 的操作就基本没有问题了。只是需要注意，不知道什么原因 firefox 中的文本无法拷贝到外面。
	
这个项目貌似不再维护了，以后有机会看一下源代码。


**Refs**

 * [vncviewer clipboard operations failed](http://rreddy.blogspot.com/2009/07/vncviewer-clipboard-operations-like.html)
 * [Remote Desktops with VNC and RDP](http://www.systemajik.com/blog/remote-desktops-with-vnc-and-rdp/)

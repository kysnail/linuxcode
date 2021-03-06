## Linux下TTY与PTY的区别

### 终端解释
终端是一种字符型设备，它有多种类型，通常使用tty来简称各种类型的终端设备。tty是Teletype的缩写。Teletype是最早出现的一种终端设备，很象电传打字机（或者说就是），是由Teletype公司生产的。在Linux系统的设备特殊文件目录/dev/下，终端特殊设备文件一般有以下几种：

#### 1. 串行端口终端（/dev/ttySn）
串行端口终端（`Serial Port Terminal`）是使用计算机串行端口连接的终端设备。计算机把每个串行端口都看作是一个字符设备。有段时间这些串行端口设备通常被称为终端设备，因为那时它的最大用途就是用来连接终端。这些串行端口所对应的设备名称是

	/dev/tts/0（或/dev/ttyS0）
	/dev/tts/1（或/dev/ttyS1）等，

设备号分别是

	（4,0）
	（4,1）等

分别对应于DOS系统下的

	COM1
	COM2等

若要向一个端口发送数据，可以在命令行上把标准输出重定向到这些特殊文件名上即可。

例如，在命令行提示符下键入：

	echo test > /dev/ttyS1

会把单词 `test` 发送到连接在 `ttyS1（COM2）` 端口的设备上。

#### 2.伪终端（/dev/pty/）
伪终端（`Pseudo Terminal`）是成对的逻辑终端设备，例如

	/dev/ptyp3和/dev/ttyp3（或着在设备文件系统中分别是/dev/pty/m3 和 /dev/pty/s3）

它们与实际物理设备并不直接相关。

如果一个程序把 `ttyp3` 看作是一个串行端口设备，则它对该端口的读/写操作会反映在该逻辑终端设备对的另一个上面（ttyp3）。而ttyp3则是另一个程序用于读写操作的逻辑设备。这样，两个程序就可以通过这种逻辑设备进行互相交流，而其中一个使用ttyp3的程序则认为自己正在与一个串行端口进行通信。这很象是逻辑设备对之间的管道操作。

对于ttyp3（s3），任何设计成使用一个串行端口设备的程序都可以使用该逻辑设备。但对于使用ptyp3的程序，则需要专门设计来使用ptyp3（m3）逻辑设备。

	例如：
	如果某人在网上使用 telnet 程序连接到你的计算机上，则 telnet 程序就可能会开始连接到设备
	ptyp2（m2） 上（一个伪终端端口上）。此时一个 getty 程序就应该运行在对应的 ttyp2（s2） 
	端口上。当 telnet 从远端获取了一个字符时，该字符就会通过 m2、s2 传递给 getty 程序，而
	getty 程序就会通过 s2、m2 和 telnet 程序往网络上返回 ”login:” 字符串信息。这样，登录程序
	与 telnet 程序就通过“伪终端”进行通信。通过使用适当的软件，就可以把两个甚至多个伪终端设备
	连接到同一个物理串行端口上。

在使用设备文件系统（`device filesystem`）之前，为了得到大量的伪终端设备特殊文件，使用了比较复杂的文件名命名方式。因为只存在16个ttyp（ttyp0—ttypf）的设备文件，为了得到更多的逻辑设备对，就使用了象q、r、s等字符来代替p。

	例如，ttys8和ptys8就是一个伪终端设备对。

不过这种命名方式目前仍然在RedHat等Linux系统中使用着。但Linux系统上的 Unix98 并不使用上述方法，而使用了”pty master”方式，

	例如/dev/ptm3。它的对应端则会被自动地创建成/dev/pts/3。

这样就可以在需要时提供一个pty伪终端。目录 `/dev/pts` 是一个类型为 `devpts` 的文件系统，并且可以在被加载文件系统列表中看到。虽然“文件” `/dev/pts/3` 看上去是设备文件系统中的一项，但其实它完全是一种不同的文件系统。

#### 3.控制终端（/dev/tty）
如果当前进程有控制终端（`Controlling Terminal`）的话，那么/dev/tty就是当前进程的控制终端的设备特殊文件。可以使用命令”ps –ax”来查看进程与哪个控制终端相连。对于你登录的shell，`/dev/tty` 就是你使用的终端，设备号是（5,0）。使用命令”tty”可以查看它具体对应哪个实际终端设备。`/dev/tty` 有些类似于到实际所使用终端设备的一个联接。

#### 4.控制台终端（/dev/ttyn,   /dev/console）

	在Linux系统中，计算机显示器通常被称为控制台终端（Console）。它仿真了类型为 Linux 的一种
	终端（TERM=Linux），并且有一些设备特殊文件与之相关联：tty0、tty1、tty2等。

当你在控制台上登录时，使用的是tty1。使用 `Alt+[F1—F6]` 组合键时，我们就可以切换到tty2、tty3等上面去。`tty1 – tty6` 等称为虚拟终端，而 `tty0` 则是当前所使用虚拟终端的一个别名，系统所产生的信息会发送到该终端上。因此不管当前正在使用哪个虚拟终端，系统信息都会发送到控制台终端上。你可以登录到不同的虚拟终端上去，因而可以让系统同时有几个不同的会话期存在。只有系统或超级用户 root 可以向 `/dev/tty0` 进行写操作。

#### 5. 虚拟终端(/dev/pts/n)
在Xwindows模式下的伪终端.如果用telnet远程登录的话，一般会启用这个。

#### 6.其它类型
Linux系统中还针对很多不同的字符设备存在有很多其它种类的终端设备特殊文件。例如针对ISDN设备的 `/dev/ttyIn` 终端设备等。


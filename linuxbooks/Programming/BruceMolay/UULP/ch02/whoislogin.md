# Linux系统下如何查看已经登录用户

## 看用户的操作
系统管理员若想知道某一时刻用户的行为，只需要输入命令 `w` 即可，在SHELL终端中输入如下命令：

	[root@fedora16 kangyushi]# w
	 16:15:09 up 8 days,  3:56, 13 users,  load average: 5.22, 4.63, 4.43
	USER     TTY      FROM              LOGIN@   IDLE   JCPU   PCPU WHAT
	aoteman  tty7     :0               12:31    8days  1:58   0.01s gdm-session-worker [pam/gdm-password]
	aoteman  pts/1    :0               12:32    1:08m  0.07s  0.07s bash
	kangyush pts/4    :12.0            10:30   46:49   0.18s  1.28s gnome-terminal
	batman   pts/9    :1010.0          12:48    1:39  14.14s 13.93s ./bin-dir/bin/qemu-system-x86_64 -hda lenny.raw -m 1024M -machine accel=kvm
	batman   pts/3    :11.0            Thu13   27:35m  0.39s  0.39s /bin/bash
	kangyush pts/10   kangyushi-pc.xau 14:33    0.00s  0.14s  0.02s sshd: kangyushi [priv]
	batman   pts/11   :11.0            Thu13   29:25m  0.09s  0.09s bash
	batman   pts/14   :1010.0          10:10    1:21m  0.17s  0.17s bash
	batman   pts/0    192.168.1.92     09:08    3:21m  0.64s  0.64s -bash
	catman   pts/15   :10.0            10:22    2:01m  4:54   4:53  ./qemu-system-x86_64 -machine accel=kvm,kernel_irqchip=on /home/catman/debian.img -m 1G -cdrom /media/a7bea563-2e18-46c4-8701-cd2209737bf1/s
	aoteman  pts/16   :14.0            10:27    5:05m  0.06s  0.00s vncconfig -nowin
	batman   pts/2    :11.0            09:12    6:56m  0.12s  0.12s /bin/bash
	kangyush pts/13   kangyushi-pc.xau 13:29   21.00s  0.34s  0.06s vim whoislogin.md

### 命令信息含义
上述显示的信息分别表示如下：

第一行显示系统的汇总信息，字段分别表示

 * 系统当前时间
 * 系统运行时间
 * 登陆哟内用户总数
 * 系统平均负载信息

对于上述示例中的几个显示数据意义为：

	 Field			Description
	------------------------------------------------------------------
	 16:15:09		w 命令的执行时间	
	 up 8 days,  3:56	系统运行时间 8 天 3 小时 56 分
	 13 users		当前系统登录的用户总数为 13
	 load average		与后面的数字一起表示系统在过去 1,5,10 分钟内的负载程度，数值越小，系统负载越轻。

从第二行开始构成一个表格，共有8个栏目，分别显示各个用户正在做的事情及该用户所占用的系统资料。

	 Field			Description
	------------------------------------------------------------------
	 USER			显示登陆用户帐号名。用户重复登陆，该帐号也会重复出现。
	 TTY			用户登陆所用的终端。
	 FROM			显示用户在何处登陆系统。
	 LOGIN@			是LOGIN AT的意思，表示登陆进入系统的时间。
	 IDLE			用户空闲时间，从用户上一次任务结束后，开始记时。
	 JCPU			终端代号来区分，表示在一段时间内，所有与该终端相关的进程任务所耗费的CPU时间。
	 PCPU			指 what 域的任务执行后耗费的CPU时间。
	 WHAT			表示当前执行的任务。

其中关于 `JCPU` & `PCPU` 的详细解释：

	JCPU
	----
	The JCPU time is the time used by all processes attatched to the tty.
	It does not include past backgroud jobs, but does include currently running background jobs.

	PCPU
	----
	The PCPU time is the time used by the current process, named in the "what" field.

### 查看某用户
当登陆系统用户很多的时候，可以在W后面加上某个用户名，则会查看该用户执行任务的情况。

	[root@fedora16 kangyushi]# w kangyushi
	 16:33:07 up 8 days,  4:14, 13 users,  load average: 2.69, 3.26, 3.79
	USER     TTY      FROM              LOGIN@   IDLE   JCPU   PCPU WHAT
	kangyush pts/4    :12.0            10:30    1:04m  0.18s  1.28s gnome-terminal
	kangyush pts/10   kangyushi-pc.xau 14:33    0.00s  0.14s  0.02s sshd: kangyushi [priv]
	kangyush pts/13   kangyushi-pc.xau 13:29    6.00s  0.36s  0.08s vim whoislogin.md

默认情况下，系统会显示上述所有的信息，如果只关心某一方面，可以只使用相关的选项。

### 查看登陆用户
同样，系统管理员若想知道某一时刻登陆的用户，可以使用系统提供的 who 命令，该命令可以查看当前登陆到系统的用户及其他信息：

	[root@fedora16 kangyushi]# who
	aoteman n tty7         2012-09-04 12:31 (:0)
	aoteman n pts/1        2012-09-04 12:32 (:0)
	kangyushi pts/4        2012-09-04 10:30 (:12.0)
	batman   pts/9        2012-09-04 12:48 (:1010.0)
	batman   pts/3        2012-08-30 13:26 (:11.0)
	kangyushi pts/10       2012-09-04 14:33 (kangyushi-pc.xause.com)
	batman   pts/11       2012-08-30 13:25 (:11.0)
	batman   pts/14       2012-09-04 10:10 (:1010.0)
	batman   pts/0        2012-09-04 09:08 (192.168.1.92)
	catman   pts/15       2012-09-04 10:22 (:10.0)
	aoteman n pts/16       2012-09-04 10:27 (:14.0)
	batman   pts/2        2012-09-04 09:12 (:11.0)
	kangyushi pts/13       2012-09-04 13:29 (kangyushi-pc.xause.com)

可以看出上述信息与 `w` 命令非常相似。如果想让列表更详细一些，可以加上选项 `-HTu` 等，就可以得到该用户是否愿意接受其他用户信息（`-T`）还可以显示空闲时间（-I）及标题栏（-H）。如果某各用户愿意接受信息，会在MESG栏中显示一个 `+`，这是还可以使用命令 `MESG` 给用户发从信息。

	[root@fedora16 kangyushi]# who -THu
	NAME       LINE         TIME             IDLE          PID COMMENT
	aoteman n + tty7         2012-09-04 12:31  old         2296 (:0)
	aoteman n + pts/1        2012-09-04 12:32 00:15        3309 (:0)
	kangyushi + pts/4        2012-09-04 10:30 01:12       24452 (:12.0)
	batman   + pts/9        2012-09-04 12:48 00:27       25922 (:1010.0)
	batman   + pts/3        2012-08-30 13:26  old         8743 (:11.0)
	kangyushi + pts/10       2012-09-04 14:33   .         26479 (kangyushi-pc.xause.com)
	batman   + pts/11       2012-08-30 13:25  old         8743 (:11.0)
	batman   + pts/14       2012-09-04 10:10 01:47       25922 (:1010.0)
	batman   + pts/0        2012-09-04 09:08 03:47       14568 (192.168.1.92)
	catman   + pts/15       2012-09-04 10:22 02:27        9470 (:10.0)
	aoteman n + pts/16       2012-09-04 10:27 05:31       23660 (:14.0)
	batman   + pts/2        2012-09-04 09:12 07:22        8743 (:11.0)
	kangyushi + pts/13       2012-09-04 13:29 00:05       24561 (kangyushi-pc.xause.com)

还可以使用下面这种方式，打印最详细的信息。

	[root@fedora16 kangyushi]# who -a
		   system boot  2012-08-27 12:19
		   run-level 5  2012-08-27 12:19
	aoteman n + tty7         2012-09-04 12:31  old         2296 (:0)
		   pts/0        2012-08-30 17:54                 0 id=/0    term=0 exit=0
	aoteman n + pts/1        2012-09-04 12:32 00:18        3309 (:0)
		   pts/2        2012-09-03 22:02             16307 id=ts/2  term=0 exit=0
		   pts/3        2012-08-30 13:26             21851 id=ts/3  term=0 exit=0
		   pts/4        2012-08-27 20:04             24785 id=ts/4  term=0 exit=0
		   pts/5        2012-08-27 20:01              6977 id=ts/5  term=0 exit=0
		   pts/6        2012-08-27 20:06              7054 id=ts/6  term=0 exit=0
		   pts/7        2012-08-27 23:17             26255 id=ts/7  term=0 exit=0
	kangyushi + pts/4        2012-09-04 10:30 01:16       24452 (:12.0)
		   pts/1        2012-08-30 13:38             14083 id=ts/1  term=0 exit=0
		   pts/7        2012-09-04 09:41                 0 id=/7    term=0 exit=0
		   pts/8        2012-09-04 15:22             24361 id=ts/8  term=0 exit=0
		   pts/8        2012-09-04 09:39                 0 id=/8    term=0 exit=0
	batman   + pts/9        2012-09-04 12:48 00:31       25922 (:1010.0)
	batman   + pts/3        2012-08-30 13:26  old         8743 (:11.0)
		   pts/9        2012-08-30 14:00             22599 id=ts/9  term=0 exit=0
	kangyushi + pts/10       2012-09-04 14:33   .         26479 (kangyushi-pc.xause.com)
		   pts/11       2012-08-29 21:17             24086 id=s/11  term=0 exit=0
		   pts/12       2012-08-31 13:25             10723 id=s/12  term=0 exit=0
	batman   + pts/11       2012-08-30 13:25  old         8743 (:11.0)
		   pts/13       2012-09-04 12:05                 0 id=/13   term=0 exit=0
	batman   + pts/14       2012-09-04 10:10 01:51       25922 (:1010.0)
		   pts/14       2012-08-31 14:26             18780 id=s/14  term=0 exit=0
	batman   + pts/0        2012-09-04 09:08 03:51       14568 (192.168.1.92)
		   pts/10       2012-09-03 20:14                 0 id=/10   term=0 exit=0
		   pts/12       2012-09-04 09:24                 0 id=/12   term=0 exit=0
	LOGIN      tty2         2012-09-01 19:25             29082 id=tty2
	LOGIN      tty4         2012-09-01 19:26             29084 id=tty4
	LOGIN      tty6         2012-09-01 19:26             29086 id=tty6
	LOGIN      tty5         2012-09-01 19:26             29088 id=tty5
	LOGIN      tty3         2012-09-01 19:26             29091 id=tty3
	catman   + pts/15       2012-09-04 10:22 02:31        9470 (:10.0)
	aoteman n + pts/16       2012-09-04 10:27 05:34       23660 (:14.0)
		   pts/17       2012-09-03 20:14                 0 id=/17   term=0 exit=0
		   pts/18       2012-09-03 20:14                 0 id=/18   term=0 exit=0
		   pts/19       2012-09-03 20:14                 0 id=/19   term=0 exit=0
		   pts/20       2012-09-03 20:14                 0 id=/20   term=0 exit=0
		   pts/21       2012-09-03 20:14                 0 id=/21   term=0 exit=0
		   pts/22       2012-09-03 20:14                 0 id=/22   term=0 exit=0
		   pts/23       2012-09-03 20:14                 0 id=/23   term=0 exit=0
		   pts/24       2012-09-03 20:14                 0 id=/24   term=0 exit=0
		   pts/25       2012-09-03 20:14                 0 id=/25   term=0 exit=0
		   pts/26       2012-09-03 20:14                 0 id=/26   term=0 exit=0
		   pts/27       2012-09-03 20:14                 0 id=/27   term=0 exit=0
		   pts/28       2012-09-03 20:14                 0 id=/28   term=0 exit=0
	batman   + pts/2        2012-09-04 09:12 07:25        8743 (:11.0)
	kangyushi + pts/13       2012-09-04 13:29   .         24561 (kangyushi-pc.xause.com)

### 查看登陆用户历史
系统管理员若想知道系统中用户登陆的历史行为，还可以察看用户曾经登陆到系统。使用 `LAST` 命令可以查询曾经登陆用户的信息：

	[root@fedora16 kangyushi]# last
	kangyush pts/10       kangyushi-pc.xau Tue Sep  4 14:33   still logged in
	kangyush pts/13       kangyushi-pc.xau Tue Sep  4 13:29   still logged in
	batman   pts/9        :1010.0          Tue Sep  4 12:48   still logged in
	aoteman  pts/1        :0               Tue Sep  4 12:32   still logged in
	aoteman  tty7         :0               Tue Sep  4 12:31   still logged in
	(unknown tty7         :0               Tue Sep  4 12:05 - 12:31  (00:25)
	kangyush pts/4        :12.0            Tue Sep  4 10:30   still logged in
	aoteman  pts/16       :14.0            Tue Sep  4 10:27   still logged in
	catman   pts/15       :10.0            Tue Sep  4 10:22   still logged in
	aoteman  pts/15       :14.0            Tue Sep  4 10:13 - 10:15  (00:02)
	batman   pts/14       :1010.0          Tue Sep  4 10:10   still logged in
	batman   pts/9        :1009.0          Tue Sep  4 10:02 - 10:08  (00:06)
	kangyush pts/8        kangyushi-pc.xau Tue Sep  4 09:58 - 15:22  (05:23)
	kangyush pts/4        :12.0            Tue Sep  4 09:43 - 10:30  (00:47)
	kangyush pts/7        :1007.0          Tue Sep  4 09:41 - 09:41  (00:00)
	kangyush pts/4        :1007.0          Tue Sep  4 09:40 - 09:41  (00:00)
	batman   pts/12       :1003.0          Tue Sep  4 09:20 - 09:24  (00:03)
	kangyush pts/10       kangyushi-pc.xau Tue Sep  4 09:15 - 14:08  (04:53)
	.....................

通常 `last` 命令的输出内容非常多，最好通过结合 `less/more` 等命令使用。

当然也可以查看某一个用户的登录历史：

	[root@fedora16 kangyushi]# last kangyushi
	kangyush pts/10       kangyushi-pc.xau Tue Sep  4 14:33   still logged in
	kangyush pts/13       kangyushi-pc.xau Tue Sep  4 13:29   still logged in
	kangyush pts/4        :12.0            Tue Sep  4 10:30   still logged in
	kangyush pts/8        kangyushi-pc.xau Tue Sep  4 09:58 - 15:22  (05:23)
	kangyush pts/4        :12.0            Tue Sep  4 09:43 - 10:30  (00:47)
	kangyush pts/7        :1007.0          Tue Sep  4 09:41 - 09:41  (00:00)
	kangyush pts/4        :1007.0          Tue Sep  4 09:40 - 09:41  (00:00)
	kangyush pts/10       kangyushi-pc.xau Tue Sep  4 09:15 - 14:08  (04:53)
	kangyush pts/28       :12.0            Mon Sep  3 20:06 - 20:14  (00:08)
	kangyush pts/27       :12.0            Mon Sep  3 20:06 - 20:14  (00:08)
	kangyush pts/26       :12.0            Mon Sep  3 20:06 - 20:14  (00:08)
	kangyush pts/25       :12.0            Mon Sep  3 20:06 - 20:14  (00:08)
	kangyush pts/24       :12.0            Mon Sep  3 20:06 - 20:14  (00:08)
	kangyush pts/23       :12.0            Mon Sep  3 20:05 - 20:14  (00:08)

执行 `last` 命令其实是显示 `/var/log/` 目录下的 `wtmp` 文件内容。`wtmp` 文件是以二进制格式进行存储的，如果直接使用文本编辑器查看，查看的会是一堆乱码。


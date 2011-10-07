shell 的工作原理
===============
所谓的 shell 就是 **命令解释器** ，用于将用户输入的类似英语的计算机命令翻译为计算机的指令，然后交由计算机执行。

其实当一个用户以命令行的方式登录到 Linux 或 Unix 系统后，便进入到了 shell 中。shell 的功能是将用户的输入翻译为 Linux Kernel 所能理解的语言，这样 Linux Kernel 才能够真正地操作计算机的硬件。

Bourn shell (bsh)
-----------------
这是最早出现的 shell，由 AT&T 的 Steven Bourn 开发，名称就是为了纪念这位计算机界真正的泰斗。可以这么说，Bourn shell 实际上就是现在所有 shell 的鼻祖。

C shell (csh)
-------------
继 bsh 后的相当流行的 shell。伯克利大学的 Bill Joy 作为 C shell 的作者，由于其语法与 C 语言类似，所以取名为 C shell。它增加了若干 Bourn shell 所没有的特性
- 命令行历史
- 别名
- 作业控制

Korn shell (ksh)
----------------
ksh 是由 AT&T 的 David Korn 开发的。它是 Bourn shell 的超级，具有类似 C shell 的加强功能：
- 命令的行编辑
- 命令历史
- 别名
- 作业控制

**Note**
````````
::

  Solaris 默认的 shell 是 Korn shell
  HP Unix 默认的 shell 是 Korn shell

Z shell (zsh)
-------------
与 Korn shell 即为相似，但是包括了许多其他的加强功能。

TC shell (tcsh)
---------------
完全与 C shell 兼容，但是包含了一些附加的加强功能。

Bourn-Again shell (bash)
------------------------
由 GNU 开发，是 Linux 上事实的标准 shell。bash 在与 bsh 兼容的同时，加入了 csh、ksh 和 tcsh 的一些有用的功能。

查看当前系统所拥有的 shell 
-----------------------
::

  ~/mynotes$ cat /etc/shells 
  # /etc/shells: valid login shells
  /bin/csh
  /bin/sh
  /usr/bin/es
  /usr/bin/ksh
  /bin/ksh
  /usr/bin/rc
  /usr/bin/tcsh
  /bin/tcsh
  /usr/bin/esh
  /bin/dash
  /bin/bash
  /bin/rbash
  /usr/bin/screen

确认用户的默认 shell
------------------
::

  ~/mynotes$ tail -8 /etc/passwd
  pulse:x:110:115:PulseAudio daemon,,,:/var/run/pulse:/bin/false
  rtkit:x:111:117:RealtimeKit,,,:/proc:/bin/false
  saned:x:112:118::/home/saned:/bin/false
  hplip:x:113:7:HPLIP system user,,,:/var/run/hplip:/bin/false
  gdm:x:114:120:Gnome Display Manager:/var/lib/gdm:/bin/false
  kysnail:x:1000:1000:kysnail,,,:/home/kysnail:/bin/bash
  ntp:x:115:123::/home/ntp:/bin/false
  sshd:x:116:65534::/var/run/sshd:/usr/sbin/nologin

切换当前 shell
-------------
只需要输入相应的 shell 名称即可。

查看当前 shell 类型
-----------------
一个小技巧，执行不存在的命令后，系统给出的提示信息中会包含相应的 shell 信息。


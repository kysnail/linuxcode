使用 type 识别 bash 的内置命令
==============================
Linux 操作系统的命令分为两大类

- 内部命令——内置在 bash 中的命令；
- 外部命令——以可执行文件的方式存储在 Linux 的文件系统中。

可以使用 type 命令查看命令的类型。

man type
--------
::
 
  man type

可以从 type 的帮助文档中看到有很多的 内部命令。

如果还想知道更详细的信息，就需要使用 type 命令进行查看了。

type command
------------
::

  type [option] command

  -t: 显示文件的类型，其文件类型如下：
        1. file: 为外部命令
        2. alias: 为别名
	3. builtin: 为 bash 的内置命令
  -a: 列出所有包含指定命令名的命令，也包括别名
  -P: 显示完整的文件名（外部命令），或者为内部命令

example 1:
----------
::

	$ type pwd
	pwd 是一个 shell 内部命令
	$ type -a pwd
	pwd 是一个 shell 内部命令
	pwd 是 /bin/pwd
	$ type -t pwd
	builtin
	$ type -P pwd
	/bin/pwd
	$ ll /bin/pwd 
	-rwxr-xr-x 1 root root 34376 2010-09-22 02:33 /bin/pwd*
	$ file /bin/pwd 
	/bin/pwd: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.15, stripped 

example 2:
----------
::

	$ type -a ls
	ls 已被别名为“ls --color=auto”
	ls 是 /bin/ls
	$ type -P ls
	/bin/ls
	$ file /bin/ls
	/bin/ls: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.15, stripped

which
-----
除了使用 type 命令，还可以使用 which/whatis 命令来获取一个命令的类型信息。
::

	$ which pwd
	/bin/pwd
	$ whatis pwd
	pwd (1)              - print name of current/working directory

whatis 
------
::

	$ which ls
	/bin/ls
	$ whatis ls
	ls (1)               - list directory contents

example 3:
----------
::

	$ type -t whoami 
	file
	$ type whoami 
	whoami 是 /usr/bin/whoami


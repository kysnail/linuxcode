history 命令与操作曾经使用过的命令
==================================
绝大多数的 shell 都会保留最近输入的命令的历史。这一机制可以使用户能够浏览、修改或重新执行之前使用过的
命令。 ::

  871  ps -xo comm
  872  ps -xo
  873  ps -xo | grep comm
  874  ps -xo 2> | grep comm
  875  ps -xo 2> grep comm
  876  ps -xo comm | sort | uniq | grep -v sh | more
  877  grep -v sh
  878  &virtualbox 
  879  & virtualbox 
  880  cd /media/本地磁盘/
  881  dir
  882  find . -name '*dos*'
  883  cd ./Books/C/Dos/
  884  dir
  885  clear
  886  ll
  887  zip
  888  zip msdos71f.zip 
  889  zip -r msdos71f.zip 
  890  man zip

如果想执行 882 号命令，可以输入惊叹号之后紧跟 882 来从新运行命令 ``find . -name '*dos*'`` 。

``^`` 
-----
可以使用次方符号 ``^`` 修改刚刚输入的命令。这个命令在某个场合可能特别有用。比如： ::

 在调试网络时，会使用 ping 检测网络中的多台主机的连通情况，这是使用 ^ 进行替换就可以看到优势了。

example 1:
``````````
::

	$ ping 192.168.1.27
	PING 192.168.1.27 (192.168.1.27) 56(84) bytes of data.
	64 bytes from 192.168.1.27: icmp_seq=1 ttl=64 time=0.053 ms
	64 bytes from 192.168.1.27: icmp_seq=2 ttl=64 time=0.042 ms
	64 bytes from 192.168.1.27: icmp_seq=3 ttl=64 time=0.044 ms
	64 bytes from 192.168.1.27: icmp_seq=4 ttl=64 time=0.040 ms
	^C
	--- 192.168.1.27 ping statistics ---
	4 packets transmitted, 4 received, 0% packet loss, time 2997ms
	rtt min/avg/max/mdev = 0.040/0.044/0.053/0.009 ms
	$ ^27^1
	ping 192.168.1.1
	PING 192.168.1.1 (192.168.1.1) 56(84) bytes of data.
	64 bytes from 192.168.1.1: icmp_seq=1 ttl=64 time=2.09 ms
	64 bytes from 192.168.1.1: icmp_seq=2 ttl=64 time=0.996 ms
	64 bytes from 192.168.1.1: icmp_seq=3 ttl=64 time=1.83 ms
	64 bytes from 192.168.1.1: icmp_seq=4 ttl=64 time=0.983 ms
	^C
	--- 192.168.1.1 ping statistics ---
	4 packets transmitted, 4 received, 0% packet loss, time 3004ms
	rtt min/avg/max/mdev = 0.983/1.476/2.093/0.497 ms

历史功能的快捷键
================
- 使用上下键访问历史命令
- Ctrl+R 在历史命令中搜索需要的命令
 (reverse-i-search`':)
- 可以使用如下组合键提取上一个命令的最后一个参数
 Esc + . (sequence press)
 Alt + . (simultaneously press)

example 2:
----------
:: 

(reverse-i-search)`ok': cd linuxcode/linuxbooks/LPXJCCSJZXXL/ch05/




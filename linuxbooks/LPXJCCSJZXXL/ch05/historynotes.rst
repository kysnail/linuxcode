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



##debian安装编译环境
dabian最小安装，安装好时，只会占去70MB多的空间，可以说真是"小而美小而简"，因为dabian的使用哲学就是：「有用到的软体再装」，不像红帽会把你可能会用到的通通装进去，不过也就是因为如此，所以预设的debian把很多软体都省略了！

以下介绍debian编译环境，所需要安装的一些套件！

### 1.build-essential
你要编译软体时最基本要装这个，他相依libc6-dev,gcc,g++,make,dpkg-dev，安装他就帮你安装好这些。

### 2.apt-file
一般来说，若已经装好build-essential应该还是不够的，因为它只会安装一些预设的函式库，若编译软体时出现找不到函式库的错误讯息时，可以用apt-file来搜寻。

ex：apt-file安装好时必须先update ( ~# apt-file update)

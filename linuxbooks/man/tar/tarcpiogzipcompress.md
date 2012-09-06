# 在Linux下压缩文件 tar命令的使用
对许多用户来说，在DOS和Windows环境下利用工具软件WinZip、ARJ等压缩或解压文件是比较容易的事。但是，在Linux中如何对文件进行压缩与解压呢？

## 用tar建立存档
tar 是 `tape archive` (磁带存档)的简称，它出现在还没有软盘驱动器、硬盘和光盘驱动器的计算机早期阶段。那时软件的发行和备份都需要大卷的磁带，计算机上运行的头几个程序中就得有一个是磁带的阅读程序。随着时间的推移， tar命令逐渐变为一个将很多文件进行存档的工具，目前许多用于Linux操作系统的程序就是打包为tar档案文件的形式。

### tar 命令的格式是：

    tar [option] <file>;

tar 命令有很多参数，利用 `f` 选项、设备或文件的名字可以指示tar命令将档案置于特定的设备或文件中。当为tar的档案创建一个文件时,这个文件名的扩展通常是如果指定了一个目录名,那么它所有的子目录都会被包含在档案之中。

#### -cf
利用tar命令和f选项的格式如下所示：

	==$ tar -f Documents.tar Documents/
	tar: You must specify one of the `-Acdtrux' or `--test-label'  options
	Try `tar --help' or `tar --usage' for more information.

要创建一个档案应使用c选项，与f选项一起，c选项会在设备或文件中创建档案，应在f选项的左边输入这一选项。在下例中，目录 Document 和它所有的子目录都被存入文件 Document.tar中。	

	==$ tar -cf Documents.tar Documents/

	==$ tar -tf Documents.tar
	Documents/

#### -uf
如果想要改动已经存档的目录中的文件，可以使用u选项使 tar 更新档案中的文件。tar 比较每一个档案文件与相应用户目录中文件最近一次修改的时间,然后将上一次存档之后又被修改过的文件拷贝到档案文件中去。在用户目录中新创建的文件也会被添加到档案文件中。在下面的例子中,用户用 Documents 目录中最近被修改或添加的文件来对 Documents.tar 文件进行更新。

	==$ tar -uf Documents.tar

##### -tf
如果想查看在一个档案中存储着哪些文件，可以使用 tar 命令和 t 选项。下面命令列出所有存储在 Documents.tar 档案中的文件：

	==$ tar -tf Documents.tar
	Documents/

#### -cf /dev/fdo	
要将文件备份到一个特定的设备，只须把设备名作为档案。在下面的例子中，用户在 /dev/fdo 设备的软盘中创建了一个档案,并将 Documents 目录中所有的文件都拷贝到档案中。

	==$ tar -cf /dev/fdo Documents

#### -xf /dev/fdo
要恢复设备磁盘中的文件,可使用 xf 选项:

	==$ tar -xf /dev/fdo

#### -cmf /dev/fdo
如果所备份的文件大小超过设备可用的存储器,比如软盘,此时就可以创建一个使用多个标号的 tar 档案。当使用 m 选项向一个软驱进行存档时, tar 命令在一张软盘已满的时候会提醒再放入一张新的软盘。

	==$ tar -cmf /dev/fdo Documents

#### -xmf /dev/fdo
要想恢复几张盘中的档案,只要将第一张软盘放入软驱,然后输入有 `x` 和 `m` 选项的 tar 命令。必要时会被提醒放入另外一张软盘。

	==$ tar -xmf /dev/fdo

#### -czf
tar 操作不会对档案文件实行压缩操作。如果想压缩档案文件,可以指示 tar 激活 gzip 实用工具,在存档之前对文件进行压缩。利用 `z` 选项, tar 在对文件存档之前首先要使用 `gzip` 来压缩文件。当恢复文件时,同样的 `Z` 选项将激活 `gzip` 对文件解压。

	==$ tar -czf Documents.tar Documents/

值得注意的是，压缩档案中的单个文件和整体压缩档案是不同的。通常档案文件是为了便于传输而把几个文件组合成为一个 tar 文件。为了缩短传输时间,档案应当越小越好，可以将其压缩然后传送压缩后的版本。接收者可以对之解压缩，然后恢复 tar 文件。在 tar 文件上使用 gzip 将会产生有 `.tar.gz` 扩展名的文件。扩展名 `.gz` 被加到被压缩的 `gzip`文件名之后。

#### gzip myarch.tar
下面的例子创建了myarch.tar的一个压缩的版本,它具有了.gz的扩展名。

	==$ tar -cf myarch.tar myarch/

	==$ gzip myarch.tar

	==$ ll myarch.tar*
	-rw-r--r-- 1 kangyushi ie2 135 Sep  3 14:48 myarch.tar.gz

### tar subdirectory
tar 命令虽然有非常多的参数，但是使用起来并不困难，可以快速而又简单地为任何需要的子目录生成档案文件。

首先，我们来建立一个有三个文件的子目录，再建立一个有另外三个文件的子目录，如下所示：

	==$ mkdir mydir

	==$ cd mydir

	==$ touch file{1..3}

	==$ mkdir mydir2

	==$ cd mydir2/

	==$ touch file2{1..3}

	==$ cd ../../

	==$ tree mydir/
	mydir/
	├── file1
	├── file2
	├── file3
	└── mydir2
	    ├── file21
	    ├── file22
	    └── file23

	1 directory, 6 files

现在已经有了一个子目录和其中的文件，使用这个命令的c(生成)和f(文件)参数来生成一个tar档案文件：

	==$ tar -cf mydir.tar mydir/

	==$ ll mydir.tar
	-rw-r--r-- 1 kangyushi ie2 10240 Sep  3 14:55 mydir.tar

#### -cvf
请注意，原来的子目录并没有发生变化。在缺省的情况下，tar命令不会删除原来的子目录和文件。如果想看看命令执行的过程，可以使用 `v` 参数，如下所示：

	==$ tar -cvf mydir.tar mydir/
	mydir/
	mydir/mydir2/
	mydir/mydir2/file22
	mydir/mydir2/file23
	mydir/mydir2/file21
	mydir/file3
	mydir/file2
	mydir/file1

#### -cwf
tar命令在进行操作的时候，就会把正在添加到档案文件中去的子目录和文件的文件名显示出来。使用w参数，即交互参数，这样tar命令在执行的过程当中会询问是否想加入每个文件。当想有选择地备份内容不多的子目录的时候，这样就非常地方便，如下所示：

	==$ tar -cwf mydir.tar mydir/
	add `mydir'?y
	add `mydir/mydir2'?y
	add `mydir/mydir2/file22'?n
	add `mydir/mydir2/file23'?y
	add `mydir/mydir2/file21'?n
	add `mydir/file3'?y
	add `mydir/file2'?y
	add `mydir/file1'?y

在上面的例子中，没有把文件file22和文件file21归档。可以使用tar命令的t参数列出档案文件中的内容，f参数定义操作所使用的tar档案文件，如下所示：

	==$ tar -tf mydir.tar
	mydir/
	mydir/mydir2/
	mydir/mydir2/file23
	mydir/file3
	mydir/file2
	mydir/file1

需要注意的是，如果参数的顺序放错了，tar命令会显示出错信息并退出。

#### -xvf 
下面就来看看如何来释放整个的档案文件或者其中的某一个文件。如果想释放其中所有的文件，可以同时使用-x释放参数和-f。为了了解命令执行的过程，还可以加上-v参数：

	==$ tar -xvf mydir.tar
	mydir/
	mydir/mydir2/
	mydir/mydir2/file23
	mydir/file3
	mydir/file2
	mydir/file1

如果只是想从档案文件中释放几个文件的话，可以再次使用w参数：

	==$ tar -xvwf mydir.tar
	extract `mydir'?y
	mydir/
	extract `mydir/mydir2'?y
	mydir/mydir2/
	extract `mydir/mydir2/file23'?y
	mydir/mydir2/file23
	extract `mydir/file3'?y
	mydir/file3
	extract `mydir/file2'?y
	mydir/file2
	extract `mydir/file1'?y
	mydir/file1

上例表明查看了档案文件，并交互地释放了文件。如果只想从档案文件中释放某一个文件，可以在命令行中指定这个文件。作为示例，我先删除了原始的mydir子目录，然后使用一个空的子目录进行如下操作：

	==$ tar -xf mydir.tar mydir/mydir2/file23

	==$ tree mydir
	mydir
	└── mydir2
	    └── file23

	1 directory, 1 file

注意，正如所看到的只有一个文件被释放出来。虽然tar命令不会覆盖整个的子目录，但是它会覆盖掉那些有着相同文件名的文件。

值得一提的是，还可以使用其它程序，如BRU-2000或者taper脚本程序来备份系统或者选定的文件和子目录。OpenLinux操作系统也可以通过cron日程安排来自动进行文件的归档整理工作。

## 建立cpio档案文件
cpio命令可以从tar或者cpio档案文件中拷入或者拷出文件。因为cpio命令和tar命令兼容，所以我这里不再详细介绍它如何工作。但是这个命令具备一些tar命令没有的功能，如下所示：

 * 支持cpio和tar两种档案文件格式；
 * 支持许多老式磁带数据格式；
 * 能够通过一个管道读取文件的文件名。

只有很少的Linux软件包是以cpio格式发行的。如果对cpio命令的详细情况感兴趣的话，可以阅读它的使用手册。
 
## 使用gzip压缩文件
gzip命令是用来压缩文件的。它不仅可以用来压缩大的、较少使用的文件以节省磁盘空间，还可以和tar命令一起构成Linux操作系统中比较流行的压缩文件格式。据统计，gzip命令对文本文件有60%～70%的压缩率。

### gzip命令的格式是：

	gzip [option] [file]

gzip很容易使用。如果想压缩某个文件或者磁带档案文件，可输入下面的内容：

	# gzip mydir.rar

在缺省的状态下，gzip 会压缩文件、再加上一个 `.gz` 扩展名，然后删除掉原来的文件。如果想解压缩文件，可以使用 gzip 的对应程序命令 `gunzip` 或者 `gzip` 命令的 `-d` 解压缩参数。但是必须保证这个用于解压缩的文件有 `.gz`(或者 `.Z`、`-gz`、`.z`、`-z`、或者`_z`)扩展名，否则 `gzip` 命令和 `gunzip` 命令都会显示出错信息。如果想使用自己的扩展名，可以使用 `-S` 后缀参数，如下所示：

	# gzip -S .gzipped mydir.tar

gzip还可以处理用zip命令、compress命令和pack命令压缩的文件包。如果想在压缩或者解压缩的过程中看到更多的信息，可以使用-l列清单参数看到文件在被压缩或解压缩的时候的文件长度。在前一个例子中，压缩完子目录mydir之后，可以使用gzip命令按照下面的方法得到有关的数据：

	# gzip -l mydir.tar.gz
	compressed uncompr.ratio uncompressed_name
	312 21330 98.2% mydir.tar

#### -t or -tv
此外，gzip还有一个很有用的参数-t，可以用来测试压缩文件的完整性。如果文件正常，gzip不会给出任何显示。如果想看到OK这两个字母，可以在测试某个文件时使用-tv参数。

## 使用compress压缩文件
 compress命令就像它的文件名那样是用来压缩文件的。这是Unix中出现得比较早的一个压缩程序,它通过使用自适应的Lemple-Ziv编码来缩小所指文件的大小。每一个文件将被一个带有.Z扩展名的压缩文件所代替，但文件的属主关系、访问时间和修改时间将保持不变。

	如果没有指定文件，则接受标准输入的文件进行压缩并送到标准输出。

###  compress命令格式是：

	compress [option] [file]

与compress对应的有一个解压缩命令uncompress，其格式如下：

	uncompress [option] [file]

它使“.Z”的压缩文件恢复。

###  compress和uncompress命令的选项如下：

 * -c 写到标准输出，不改变文件。
 * -f 强制压缩，即使文件并不真正减小或.Z文件已经存在，也进行压缩。
 * -v 显示每一个被压缩文件的缩小的百分比。

#### 下面举例说明compress命令的用法：

	# compress file

上面代码表明将生成压缩文件file.Z代替file，要解压缩输入：

	# uncompress file.Z

注意，像使用gzip命令一样，使用uncompress命令时必须给出一个带有.Z扩展名的文件名，否则uncompress命令显示出错信息。



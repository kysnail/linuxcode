## Chapter 2 - Understanding Basic Operations
在阅读 **Learning the vi and vim** 这本书的时候，提到了 vi 实际上是 **ex** 命令的界面模式。

	vi is the visual mode of the more general, underlying line editor, which is ex.

而 sed 和 awk 都起源于 **ed** 命令，这两个命令的名称类似，功能也蛮相近。既然两者起源相同，那么最好从而这的共同点入手了：

 1. They are invoked using similar syntax.
 2. They are both stream-oriented, reading input from text files one line at a time and directing the reault to standard output.
 3. They use regular expression for pattern matching.
 4. They allow the user to specify instructions in a script.

### Awk, by Sed and Grep, out of Ed
`ed` 与 `ex` 并不是完全没有关系的命令。

    ex is a superset of the features in ed.

ex 是 ed 特征的扩展集。

练习一下 ed 的命令：

    [08/13/12-21:29:09][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ cat mylist 
    John Daggett, 341 King Road, Plymouth MA
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls PA
    Eric Adams, 20 Post Road, Sudbury MA
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston MA
    
    查看一下测试文本内容。

    [08/13/12-21:29:09][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ ed mylist 
    341
    
    使用 ed 编辑测试文本，游标默认指向文本最后一行，并向控制台输出文本所含字符数。

    p
    Sal Carpenter, 73 6th Street, Boston MA

    使用 p 命令输出当前行内容。

    1
    John Daggett, 341 King Road, Plymouth MA

    使用 [address] 命令将光标定位到对应行上。

    d

    并使用 d 命令删除当前行。

    1d

    这是上面两个操作的简写版。

    /CA/p
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA

    查找匹配 CA 的行，并将其打印到控制台上。

    g/CA/p
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    /MA/p
    Sal Carpenter, 73 6th Street, Boston MA
    g/MA/p
    Eric Adams, 20 Post Road, Sudbury MA
    Sal Carpenter, 73 6th Street, Boston MA

    加上 g 这个全局选项，可以将文本中所有符合规则的行输出到控制台上。

    p
    Sal Carpenter, 73 6th Street, Boston MA

    使用 p 命令打印当前行。

    s/Boston/Bole/
    p
    Sal Carpenter, 73 6th Street, Bole MA

    替换并打印。

    s/Boston/Bole/g
    ?

    s/Bole/Boston/g
    s/Bole/Boston/g
    ?
    这里演示了，如果同一命令使用两次，如果 ed 无法返回正确执行信息，则会向控制台输出 ？ 号。

    5  
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA

    定位到第 5 行。

    g/Mountain/s//Lake/g 

    本条语句演示了三个语法细节：
    1. 第一个 g 表示在全局范围，ed 会递归文本中的每一行。
    2. 第二个 g 表示规则要应用到该行上的所有匹配上。
    3. // 是一种简写方式，用于地址的查找规则与替换的查找规则相同的情况下。

    p
    Amy Wilde, 334 Bayshore Pkwy, Lake View CA

    输出当前行的内容。

之前就了解过，`grep` 命令源于 `ed` 命令，通过这里的练习，才有了一个直观、实际的操作体验。才理解了：

    The familiar UNIX utility grep is derived from the following global command in ed:

        g/re/p

它表示 **全局正则表达式打印 - global regular expression print**。

### Command-Line Syntax

    command [options] script filename

#### Scripting
在 sed 和 awk 中，每个指令都有两个部分所组成：

**pattern**

    The pattern is a regular expression delimited with slashes (/).

**procedure**

    A procedure specifies one or more actions to be performed.

#### Sample Mailing List

    John Daggett, 341 King Road, Plymouth MA
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls PA
    Eric Adams, 20 Post Road, Sudbury MA
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston MA

### Using sed
使用 sed 有两种方式：

 1. Specify your editing instructions on the command line;
 2. You put them in a file and supply the name of the file.

#### Specifying Simple Instructions
对于简单的替换操作，可以使用这种方式：

    sed [-e] 'instruction' file

    -e - this option is necessary only when you supply more than one instruction on the command line.

**Demo**

    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed 's/MA/Massachusetts/' list 
    John Daggett, 341 King Road, Plymouth Massachusetts
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls PA
    Eric Adams, 20 Post Road, Sudbury Massachusetts
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston Massachusetts

上面这条指令，修改了三行内容，但显示了所有的文本行。

命令用单引号引起来，这是一个好习惯，要保持。

**Demo**

上面的命令可以不使用 `单引号 分隔，但下面的这条指令必须使用单引号。

    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed 's/ MA/, Massachusetts/' list 
    John Daggett, 341 King Road, Plymouth, Massachusetts
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls PA
    Eric Adams, 20 Post Road, Sudbury, Massachusetts
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston, Massachusetts

如果我们想在命令行方式上指定多重指令，有三种方式可以选择：

**1. Seperate instructions with a semicolon.**

    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed 's/ MA/, Massachusetts/;s/ PA/, Pennsylvania/' list 
    John Daggett, 341 King Road, Plymouth, Massachusetts
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls, Pennsylvania
    Eric Adams, 20 Post Road, Sudbury, Massachusetts
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston, Massachusetts

**2. Precede each instruction by -e.**

    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed -e 's/ MA/, Massachusetts/' -e 's/ PA/, Pennsylvania/' list
    John Daggett, 341 King Road, Plymouth, Massachusetts
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls, Pennsylvania
    Eric Adams, 20 Post Road, Sudbury, Massachusetts
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View CA
    Sal Carpenter, 73 6th Street, Boston, Massachusetts
    
**3. Use the multiline entry capability of the Bourne shell.** 

Press RETURN after entering a single quote and a secondary prompt (>) will be displayed for multiline input.

    Sal Carpenter, 73 6th Street, Boston, Massachusetts
    
    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed '
    > s/ MA/, Massachusetts/
    > s/ PA/, Pennsylvania/
    > s/ CA/, California/' list
    John Daggett, 341 King Road, Plymouth, Massachusetts
    Alice Ford, 22 East Broadway, Richmond VA
    Orville Thomas, 11345 Oak Bridge Road, Tulsa OK
    Terry Kalkas, 402 Lans Road, Beaver Falls, Pennsylvania
    Eric Adams, 20 Post Road, Sudbury, Massachusetts
    Hubert Sims, 328A Brook Road, Roanoke VA
    Amy Wilde, 334 Bayshore Pkwy, Mountain View, California
    
需要注意的是，上面的这种方式在 C shell 中不能使用。并且上面的操作并不会对源文件产生影响。    
    
#### Command garbled
对于错误的命令 sed 并没有错误提示信息，而仅仅是将有问题的行原样输出。而 GNU sed 就会给出更清晰的提示：

    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed --version
    GNU sed version 4.2.1
    Copyright (C) 2009 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE,
    to the extent permitted by law.
    
    GNU sed home page: <http://www.gnu.org/software/sed/>.
    General help using GNU software: <http://www.gnu.org/gethelp/>.
    E-mail bug reports to: <bug-gnu-utils@gnu.org>.
    Be sure to include the word ``sed'' somewhere in the ``Subject:'' field.
    
    [08/14/12-20:20:38][jobs:0][kangyushi@fedora16:~/sedawk2progs/ch02]
    ==$ sed -e 's/MA/Massachusetts' list
    sed: -e expression #1, char 18: unterminated `s' command    
    

    
    


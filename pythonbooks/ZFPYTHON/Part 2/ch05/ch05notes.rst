第 5 章 正则表达式
==================
正则表达式是用某种模式去匹配一类具有共同特征的字符串，正则表达式主要用于处理文本。它能够使文本处理变得简单起来，
尤其对于复杂的查找、替换这样的工作，是用正则表达式会非常快地完成。在流行的文本编辑器里如 Emacs、Vim 等大都支持
正则表达式。

5.1 正则表达式概述
------------------
在 Python 的较早版本中使用 regex 模块来完成正则表达式的操作。在新的版本中已经删除了 regex 模块。当前的 Python 主要
使用 re 模块进行正则表达式的操作。re 模块提供了 Perl 风格的正则表达式。re 模块具有更好的可读性以及更强的功能。

5.1.1 基本元字符
````````````````
元字符是正则表达式中含有的字符。在正则表达式中可以在字符串中使用元字符用以匹配字符串的各种可能的情况。常用的元字符如下：::


	============	=============================================================================================
	   元字符		含 义
	============	=============================================================================================
	      .		 匹配处换行符以外的任何单个字符，如 "r.d" 会匹配 "red" "r d" 等，但不会匹配 "read"
	      *		 匹配位于 * 之前的任意个字符，如 "r*ed" 会匹配 "rred" "rrred" "red" 等
	      +		 匹配位于 + 之前的一个或多个字符，如 "r+ed" 会匹配 "rred" "rrred"，但不会匹配 "red"
	      |		 匹配位于 | 之前或者之后的字符，如 "red|blue" 会匹配 "red" "blue"
	      ^		 匹配行首
	      $ 	 匹配行尾
	      ?	 	 匹配位于 ? 之前的零个或一个字符，如 "r?ed" 会匹配 "rred" "red" 等，但不会匹配 "rrred"
	      \		 表示位于 \ 之后的为转义字符
	     []		 匹配位于 [] 中的任何一个字符，如 r[ae]d，会匹配 "rad" "red"
	     ()		 将位于 () 内的内容当作一个整体
	     {}		 按 {} 中的次数进行匹配
	============	=============================================================================================

元字符还可以配合起来使用。".*" 可以匹配任意个字符，如 "r.*d" 会匹配 "rd" "red" "read" 等。".+" 可以匹配任意的一个或者
多个字符，如 "r.+d" 会匹配 "red" "read" ，但不会匹配 "rd"。".?" 可以匹配任意的零个或一个字符，如 "r.?d" 会匹配 "rd" 
"red" ，但不会匹配 "read" 。

"^" 匹配行首，对于如下所示的一段文字，"^red" 只会匹配文中的第 3 个 "red" 。而对于 "red$" 则只会匹配文中的第 2 个 "red"。
  a red hat
  blue and red
  red and blue
在 "[]" 中还可以使用 "-" 来表示某一范围。例如在 "[]" 中，"a-z" 表示从 "a" 到 "z" 的所有小写字母，同样 "A-Z" 表示从 "A" 
到 "Z" 的所有大写字母，而 "0-9" 表示从 "0" 开始到 "9" 的数字。"[a-zA-Z0-9]" 表示任意的字母或者数字。

5.1.2 常用正则表达式分析
````````````````````````
使用正则表达式可以简化程序设计。例如，在文本文件中包含一些联系人的手机号码。如果需要将使用联通和移动区分开来，则可以使用
正则表达式分别匹配。对于联通的手机号，第三位是 0、1、2 或者 3。而移动的号码则是 4~9 中的某一数字，可以据此来判断。

如下正则表达式匹配联通的手机号。
::

  13[0-3][0-9]{8}

其中 13 表示匹配手机号的前两位。[0-3] 匹配手机号的第 3 为，表示 0~3 之间的任何一个数字。"[0-9]{8}" 组合起来匹配手机剩下
的 8 位。"[0-9]" 表示 0~9 之间的任何一个数字，"{8}" 表示匹配 "[0-9]" 8 次，也就是匹配任意一个 8 位数。

下面的正则表达式匹配移动的手机号。
::

  13[4-9][0-9]{8}

其与匹配联通的手机号唯一不同的地方是第 3 位是用 "[4-9]"。[4-9] 表示 4~9 之间的任何一个数字。

同样如果联系人的信息中还包括邮政编码，而又需要将其按地区来区分的话也可以使用正则表达式。对于邮政编码的匹配则相对简单一些，
例如北京的邮政编码前 3 位为 100。采用与匹配手机号同样的方式，只需在 100 之后匹配任一个 3 位数，如下所示。
::

  100[0-9]{3}

使用正则表达式匹配数字十分方便，但如果匹配字符串，则需要考虑较多的情况。例如，需要找出某一文件中所有的网址则比较复杂。以
"http://www.python.org" 为例，其可以分成 4 部分，首先是 "http://" ，然后为 "www"，再就是站名 "python" ，剩下的是后缀 "org"。
可能有的网址书写完整，具有以上 4 个部分。而有些网址则不正规，不含 "http://" 部分。

将 "http://www" 当作一部分，其可能的情况为 "http://www" 或者 "www" ，这一部分的正则表达式匹配可以写为如下所示的形式。
::

  (http://www|www)	# 使用 "()" 表示其为一个整体，使用 "|" 表示其中任何一个满足则匹配

中间的站名作为一部分，这部分可能为字母、数字或者 "-"，因此该部分的正则表达式匹配可以写成如下所示的形式。
::

  [a-z0-9-]*	# [a-z0-9-] 表示字母、数字、或者 "-" ，"*" 表示匹配 0 个或多个前边的字符

剩下的后缀，考虑到可能为两个或三个的字符，因此写成如下的形式。	
::

  [a-z]{2,3}	# {2,3} 表示匹配两次或三次，即匹配由两个或三个字母组成的字符串

由于其中还含有 "."，而在正则表达式中其具有特殊含义，需要其使用 "\" 转义。完整的正则表达式如下所示。
::

  (http://www|www)\.[a-z0-9-]*\.[a-z]{2,3}

此处没有考虑诸如 "com.cn" 这样的形式，读者可以试着自己将其完成。

5.2 re 模块函数应用
-------------------
Python 中的 re 模块提供了对正则表达式的支持。虽然 Python 中有一个 string 模块用来对字符串进行处理，但 string 模块
只能完成简单的操作。而使用 re 模块可以完成对复杂字符串的操作，它提供了以下几类对字符串进行操作的函数。

5.2.1 匹配和搜索
````````````````
- re.match() 函数用于在字符串中匹配正则表达式，如果匹配成功，则返回 MatchObject 对象实例。
- re.search() 函数用于在字符串中查找正则表达式，如果找到，则返回 MatchObject 对象实例。
- re.findall() 函数用于在字符串中查找所有符合正则表达式的字符串，并返回这些字符串的列表。如果在正则表达式中使用了组，则返回一个元组。

re.match() 函数和 re.search() 函数的作用基本一样。不同的是，re.match() 函数只是从字符串中第一个字符开始匹配。而 re.search 则搜索整个字符串。以上三个函数的原型如下所示。

- re.match( pattern, string[, flags])
- re.search( pattern, string[, flags])
- re.findall( pattern, string[, flags])

其参数含义如下。

- pattern：匹配模式。
- string：要进匹配的字符串。
- flags：可选参数，进行匹配的标志。

参数 flags 可以是以下选项。

- re.I：忽略大小写。
- re.L：根据本地设置而更改 \w \W \b \B \s \S 的匹配内容。
- re.M：多行匹配模式。
- re.S：使“.”元字符匹配换行符。
- re.U：匹配 Unicode 字符。
- re.X：忽略 pattern 中的空格，并且可以使用 “#”注释。

上述的几个编译标志可以同时使用。同时使用几个编译标志时，需要使用 "|" 对并用的编译标志进行运算。以下实例使用上述
函数进行匹配和搜索。
::

	>>> import re
	>>> s = 'Life can be good'
	>>> print re.match('can', s)
	None					# 返回 None 的原因是 match 必须从第一个字符开始匹配
	>>> print re.search('can', s)
	<_sre.SRE_Match object at 0xb76f3d78>
	>>> print re.match('l.*', s)
	None					# 未找到的原因是，这里没有以小写字母 l 开头的字符串
	>>> print re.match('l.*', s, re.I)
	<_sre.SRE_Match object at 0xb76f3d78>
	>>> re.findall('[a-z]{3}', s)		# 查找到所有 3 个字符的字符串，注意这里没有将 ood 返回。
	['ife', 'can', 'goo']
	>>> re.findall('[a-z]{1,3}', s)
	['ife', 'can', 'be', 'goo', 'd']	# 查找所有由 1 到 3 个字母组成的字符串，同样这里可以看到总是从最大值开始切起。而且同样不会产生 ood 字符串。

5.2.2 替换函数
``````````````
- re.sub() 函数用于替换字符串中符合正则表达式的内容，它返回替换后的字符串。
- re.subn() 函数与 re.sub() 函数相同，只不过 re.subn() 函数返回一个元组。

其函数原型分别如下所示。

- re.sub( pattern, repl, string[, count])
- re.subn( pattern, repl, string[, count])

其参数含义如下。

- pattern：正则表达式模式。
- repl：要替换成的内容。
- string：进行内容替换的字符串。
- count：可选参数，最大替换次数。

示例：
::

	>>> import re
	>>> s = 'Life can be bad'
	>>> re.sub('bad', 'good', s)		# 'bad' -> 'good'
	'Life can be good'
	>>> re.sub('bad|be', 'good', s)
	'Life can good good'
	>>> re.sub('bad|be', 'good', s, 1)	# 'bad' -> 'good' for one time.
	'Life can good bad'
	>>> re.subn('bad|be', 'good', s, 1)	
	('Life can good bad', 1)		# 这里的元组第二项为 1，因为上面定义值为 1.
	>>> r = re.subn('bad|be', 'good', s)
	>>> print r[0]
	Life can good good
	>>> print r[1]				# 这里的元组第二项为 2，与上面不同的地方就在于没有指定次数的限制。
	2

5.2.3 分割字符串
````````````````
- re.split() 函数用于分割字符串，它返回分割后的字符串列表。其函数原型如下。

  re.split( pattern, string[, maxsplit = 0])

其参数含义如下。

- pattern：正则表达式。
- string：要分割的字符串。
- maxsplit：可选参数，最大分割次数。

以下实例使用上述模块对字符串进行操作。
::

	>>> import re
	>>> s = 'Life can be bad'
	>>> re.split(' ', s)		# 使用空格分割字符串（注意：单引号之间有一个空格）
	['Life', 'can', 'be', 'bad']
	>>> r = re.split(' ', s, 1)	# 只分割一次
	>>> for i in r:			# 遍历分割后返回的列表
	...     print i
	... 
	Life
	can be bad
	>>> re.split('b', s)		# 使用字母“b” 分割字符
	['Life can ', 'e ', 'ad']


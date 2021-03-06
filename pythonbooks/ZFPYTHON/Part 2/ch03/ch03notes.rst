第 3 章 Python 数据类型与基本语句
=================================

    对于一般的 Python 脚本，只要使用 Python 的内置数据类型就可以完成绝大多数工作。

3.1 Python 数据类型——数字
---------------------------
    数字是最基本的数据类型，任何编程语言都提供了对数字的支持。在 Python 中可以使用任意大的数字，而不用担心溢出。

3.1.1 基本类型
``````````````
    数字在 Python 中有 4 种类型
        - 整数
        - 长整数
        - 浮点数
        - 复数

	============	==============================================================
	类    型		描述
	============	==============================================================
	整数        	一般意义上的数，包含八进制（以数字0开头）及十六进制（以0x开头）
	长整数		无限大小的书，在结尾添加小写字母 l 或者大写字母 L。
	浮点数		小数或者用 E 或 e 表示的冥。
	复数		复数的虚部以字母 j 或者 J 结尾。
	============	==============================================================

    作为动态类型的语言，在 Python 中使用数字无需事先声明其类型 ::

	>>> a = 1
	>>> b = 12.5
	>>> a + b
	13.5
	>>> c=2011000000000000000000L
	>>> c
	2011000000000000000000L
	>>> d=20110000000000000000000l
	>>> d
	20110000000000000000000L
	>>> d - c
	18099000000000000000000L
	>>> d + b
	2.0110000000000001e+22
	>>> 2.30 - 1.30
	0.99999999999999978
	>>> 2.3 - 1
	1.2999999999999998
	>>> 07 + 05
	12
	>>> 0x7 + 0xa
	17
	>>> print '%o' % ( 07 + 05 )
	14
	>>> print '%x' % ( 07 + 05 )
	c
	>>> m = 9 + 3j
	>>> n = 15 - 2j
	>>> m + n
	(24+1j)
	>>> 

3.1.2 运算符
````````````
    Python 中的运算符

	===========	==============================================
	  运算符		描		述
	===========	==============================================
	    **			乘方运算符
	     *			乘法运算符
	    /			除法运算符
	    %			取余运算符
	    +			加法运算符
	    -			减法运算符
	    |			位或运算符
	    ^			位异或运算符
	    &			位与运算符
	    <<			左移运算符
	    >>			右移运算符
	===========	==============================================

    示例::

	>>> 2 ** 5			# 乘方运算，求解 2 的 5 次方
	32
	>>> 2 ** 0			# 求解 2 的 0 次方
	1
	>>> 3 * 2			# 乘法运算
	6
	>>> 4 / 2			
	2
	>>> 7 / 2
	3
	>>> 7 % 2
	1
	>>> 5 ^ 3			# 位异或，5 的二进制形式为 101，3 的为 011，异或后为 110 即十进制的 6
	6
	>>> 5 ^ 5
	0
	>>> 11 | 5			# 位或运算，11 的二进制形式为 1011 ，5 的二进制形式为 101，位或运算后为 1111
	15
	>>> 12 & 12
	12
	>>> 2 * 5 ** 2
	50
	>>> 2 + 3 * 5
	17
	>>> 2 + 5 ^ 5
	2
	>>> 3 + 4 * 5 ** 2 - 20
	83
	>>> 4 >> 2			# 右移两位相当于除以 4
	1
	>>> 4 >> 1			# 右移一位相当于除以 2
	2
	>>> 2 + (3 ^ 5)
	8
	>>> (2 + 3) * 5
	25
	>>> 


3.2 Python 数据类型——字符串 
------------------------------
    Python 中的字符串用来表示和存储文本，通常由如下三种表示形式。
	- 单引号（'...'）
	- 双引号（"..."）
	- 三引号（'''...''', ''''''...''''''）
    其中三引号表示可以引用多行文本，通常情况下，在 Python 中大段性的描述性文字就是用三引号包围，它的功能类似于
    HTML 中的 <pre> 标签。

3.2.1 字符串概述
``````````````
    字符串中可以包含数字、字母、以及一些控制字符，如换行符、制表符等。::

	>>> str1 = 'single quote'
	>>> str2 = "double quote'
	  File "<stdin>", line 1
	    str2 = "double quote'
				^
	SyntaxError: EOL while scanning string literal
	>>> str2 = "double quote"
	>>> str3 = '123'
	>>> str4 = 'a = 1 + 2 ^ 3 * 4'
	>>> str5 = 'Can\'t'
	>>> str5
	"Can't"
	>>> str6 = "Can't"
	  File "<stdin>", line 1
	    str6 "Can't"
		       ^
	SyntaxError: invalid syntax
	>>> str6 = "Can't"
	>>> str6
	"Can't"
	>>> 

    如果要在字符串中加入控制字符，或一些特殊字符，则需要使用转义字符进行标示，常见的转义字符如下所示：

	============	==============================================
	  转义字符			含    义
	============	==============================================
	     \n			换行符
	     \r			回车符
	     \t			制表符
	     \\			表示 \
	     \'			表示一个单引号，而不是字符串的结束
	     \"			表示一个双引号，而不是字符串的结束
	============	==============================================

    在 Linux 平台上的演示效果如下：::

	>>> t = 'Hi, \tPython!'		# 在字符串中加入制表符
	>>> print t
	Hi, 	Python!			# 只有使用 print 输出字符串时才会解释字符串中的转义字符
	>>> t
	'Hi, \tPython!'
	>>> t = 'Hi, \nPython!'		# 
	>>> print t
	Hi, 
	Python!
	>>> t
	'Hi, \nPython!'
	>>> t = 'Hi, \rPython!'		# 在字符串中加入回车，相当于使用换行符
	>>> print t
	Python!				# 只是在 Linux 平台下的回车含义在是比较确切的。在 Windows 平台上则体现不出来。
	>>> t
	'Hi, \rPython!'
	>>> t = 'Hi, \\nPython'		# 在字符串中加入 "\" ，而不是用用于转义字符。
	>>> print t
	Hi, \nPython
	>>> 

    同样的**回车符**在 Windows 平台上的表现就有所不同。::

	IDLE 2.6.6      
	>>> t = 'Hi, \rPython!'		# 这里回车的作用等同于换行
	>>> print t
	Hi, 
	Python!
	>>> t = 'Hi, \nPython!'		# 这里换行的作用体现了出来
	>>> print t
	Hi, 
	Python!
	>>> t = 'Hi, \r\nPython!'	# 这里如果两个同时加上，则会出现空行的情况，不过这个空行在 Notepad 中看不出来，只能在
	>>> print t			# vim/emeditor 这类编辑器中科院观察到。这本社也是由于平台对待换行的差异而造成的。
	Hi, 

	Python!
	>>> 

3.2.2 操作字符串
````````````````
    Python 相较于自己目前所学的语言提供了超多字符串操作函数，很多还很有意思。当然也支持 "+"/"*" 的运算符。
    常用的字符串操作函数如下：::

	=====================	=====================================================
	   字符串操作			描	述
	=====================	=====================================================
	 string.capitalize()	 将字符串的第一个字母大写
	 string.count()		 获得字符串中某一子字符串的长度
	 string.find()		 获得字符串中某一子字符串的起始位置
	 *string.isalnum()	 检测字符串是否仅包含 0-9A-Za-z
	 *string.isalpha()	 检测字符串是否仅包含 0-9A-Za-z
	 *string.isdigit()	 检测字符串是否仅包含字母
	 string.islower()	 检测字符串是否均为小写字母
	 string.isspace()	 检测字符串中所有字符是否均为空白字符
	 string.istitle()	 检测字符串中的单词是否为首字母大写
	 string.isupper()	 检测字符串是否均为大写字母
	 (★)string.join()	 连接字符串
	 string.lower()		 将字符串全部转换为小写
	 string.split()		 分割字符串
	 string.swapcase()	 将字符串中的大写字母转换为小写，小写字母转换为大写
	 string.title()		 将字符串中的单词首字母大写
	 string.upper()		 将字符串中全部字母转换为大写
	 len(string)		 获取字符串长度
	=====================	=====================================================

    函数的使用示例：::

	>>> str = 'hi, python!'
	>>> str.capitalize()		# 将字符串的第一个字母大写	
	'Hi, python!'
	>>> str.count('p')		# 获得字符串中 "p" 的数目
	1
	>>> str.find('hello')		# 获得字符串中 "p" 的起始位置
	-1				# -1 表示未找到
	>>> str.find('p')		# 获得字符串中 "p" 的起始位置
	4				# 从 0 开始也就是字符串中第 5 个字符
	>>> str.isalnum()		# 检测字符串是否仅包含 0-9A-Za-z
	False
	>>> str.isalpha()		# 检测字符串是否仅包含字母
	False
	>>> str.isdigit()
	False
	>>> str.islower()
	True
	>>> str.isspace()		# 检测字符串中所有字符是否均为空白字符
	False
	>>> str.istitle()		# 检测字符串中的单词是否为首字母大写
	False
	>>> str.isupper()
	False
	>>> str.join('HI')
	'Hhi, python!I'
	>>> str.upper()
	'HI, PYTHON!'
	>>> str.split()
	['hi,', 'python!']
	>>> str.split(',')
	['hi', ' python!']
	>>> len(str)
	11
	>>> str + 'hello'
	'hi, python!hello'
	>>> str * 3			# 使用 "*" 重复字符串，此处重复 3 此
	'hi, python!hi, python!hi, python!'
	>>> str * 2
	'hi, python!hi, python!'
	>>> str				# 输出 str
	'hi, python!'			# 仍为原来的字符串
	>>> 

    以上函数并不改变字符串本身，而是返回修改后的新字符串，这点与 Java 相同。如果像修改原字符串，则可以使用下面的方式：::

	>>> str = str.title()
	>>> str
	'Hi, Python!'

    上面最复杂的函数是 string.join()/string.split() ，会随着参数的不同而产生不同的效果。对于 string.join() 
	- 如果参数字符串中只有一个字符，那么返回参数字符串
	- 如果参数字符串中拥有多个字符，那么会将原字符串插入参数字符串中的每两个字符之间
    同样，string.join() 并不改变原字符串，只是返回一个新的字符串。::

	>>> str = 'god'
	>>> str.join('-><-')
	'-god>god<god-'
	>>> str.join('a')
	'a'
	>>> str
	'god'

    string.split() 函数将字符串以指定的字符分割，如果不指定字符，则默认以空格分割字符串。其函数原型 ::

	split([sep [,maxsplit]])

    参数含义
	- sep -> 可选参数，指定分割字符
	- maxsplit -> 可选参数，分割次数
    示例：::

	>>> str = 'Python is wonderful!'
	>>> str.split()
	['Python', 'is', 'wonderful!']
	>>> str.split(None,1)
	['Python', 'is wonderful!']
	>>> str.split(None,0)
	['Python is wonderful!']
	>>> str.split('o',)
	['Pyth', 'n is w', 'nderful!']
	>>> 

3.2.3 索引和分片
````````````````
    **Python 中的字符串相当于一个不可变序列的列表（这一概念应该引于函数式语言）。**

    一旦声明一个字符串，则字符串中的每个字符都有了自己固定的位置。在 Python 可以使用 "[]" 来访问字符串中指定位置上
    的字符，这种方式类似于 C 语言中是数组。与数组类似，字符串中的字符序号从 0 计数。

    与 C 语言不同的是，Python 还允许以负数表示字符的序号，负数表示从字符串尾部开始计算，此时最后一个字符的序列号为
    -1，而不是 -0.下面演示了这种访问方式。::

	>>> str = 'abcdefg'
	>>> str[2]
	'c'
	>>> str[-2]
	'f'
	>>> str[-0]			# -0 即 0，就是去字符串中的第一个字符
	'a'
	>>> str[-1]
	'g'
	>>> str[1:4]			# Python 也选择了 "[a, b)" 的区间表示方式
	'bcd'
	>>> str[1:1]
	''
	>>> str[2:4]
	'cd'
	>>> str[1:-1]			# 引入负数标号的好处就在于，需要截取一段字符串时不再需要像 Java 那样复杂的进行计算了。
	'bcdef'
	>>> str[0:-2]	
	'abcde'
	>>> str[:-2]			# 等同于 str[0:-2]
	'abcde'
	>>> 

    Python 字符串索引和分片中，最有意思的两点::
	- 区间选择了 **[a, b)** 此种区间表示，这在 C++ 编程你也行中讲述了这种方式的优点，比如 **b-a** 就是区间的长度，无需其他工作。
	- 引入的负数标号易于 **截取字符串** 。

3.2.4 格式化字符串
``````````````````
    格式化字符串的概念最早是从 C 语言中获得的，Python 中格式化的概念相似，但更加灵活。

    由于字符串中的字符顺序是不可变的，但有时有需要根据具体情况修改字符串的内容，这是就需要使用格式化字符串的方式了。
    在 Python 中科院使用以 "%" 开头的字符，已在脚本中改变字符串的内容。常用的格式化字符有以下几个：

	- %c: 单个字符
	- %d: 十进制整数
	- %o: 八进制整数
	- %s: 字符串
	- %x: 十六进制整数，其中的字母小写。
	- %X: 十六进制整数，其中的字母大写。

    示例：::

	>>> s  = 'So %s day!'			# 定义字符串，在字符串中使用 %s
	>>> print s % 'beautiful'		# 使用 beautiful 替换 %s
	So beautiful day!
	>>> s % 'beautiful'			# 与 print s % 'beautiful' 功能相同
	'So beautiful day!'
	>>> '1 %c 1 %c %d' % ('+', '=', 2)	# 使用多个格式化字符
	'1 + 1 = 2'
	>>> 'x = %x' % 0xA			# 使用 %x 格式化十六进制数字，其中的字母小写
	'x = a'
	>>> 'x = %X' % 0xA			# 使用 %X 格式化十六进制数字，其中的字母大写
	'x = A'

3.2.5 字符串与数字相互转换
``````````````````````````
    很多情况下，都会遇到数字与数字字符串的转换问题，比如 C 语言中的 socket 编程中，就会遇到的，使用 atoi 函数进行转换，在
    Python 中也有类似的函数从事两者之间的转换工作，

    string.atoi() 将字符串转换为整数

    string.atoi( s[, base])
	- s: 进行转换的字符串
	- base: 可选参数，表示将字符转换成的进制类型

    str() 将数字转换为字符串

    示例：::

	>>> '10' + 4						# 两种不同类型对象相加引发异常
	Traceback (most recent call last):
	  File "<stdin>", line 1, in <module>
	TypeError: cannot concatenate 'str' and 'int' objects
	>>> string.atoi('10') + 4				# 没有 import string 时，会发生 string 未定义的错误
	Traceback (most recent call last):
	  File "<stdin>", line 1, in <module>
	NameError: name 'string' is not defined
	>>> import string
	>>> string.atoi('10') + 4				# 将字符串转换为数字
	14
	>>> '10' + str(4)					# 将数字转换为字符串
	'104'
	>>> string.atoi('13', 16)				# 将字符串转换为十六进制
	19

3.2.6 原始字符串
````````````````
原始字符串是 Python 中一类比较特殊的字符串，以大写字母 R 或者小写字母 r 开始。在原始字符串中，“\”不再表示转义字符的含义。
原始字符串是为正则表达式设计的，但是可以用其来方便地表示 Windows 系统下的路径。但是，如果路径以“\”结尾，那么会出错。

  这个功能同 C# 中 @ 号所引导的字符串。

示例：::

  IDLE 2.6.6      
  >>> import os
  >>> path = r'f:\books\javascript'			# 使用原始字符串
  >>> os.listdir(path)					# 列出目录中的内容
  ['Eloquent JavaScript.pdf', 'FunnyJS.txt', 'High.Performance.JavaScript.pdf', 'JavaScript DOM \xb1\xe0\xb3\xcc\xd2\xd5\xca\xf5.pdf', 'JavaScript.mm', 'Javascript\xbb\xf9\xb4\xa1\xbd\xcc\xb3\xcc.chm', 'JavaScript\xca\xb5\xd5\xbd\xca\xd6\xb2\xe1.rar', 'jQuery\xbb\xf9\xb4\xa1\xbd\xcc\xb3\xcc.pdf', 'JSON', 'Learn JavaScript and Ajax with w3Schools.pdf', 'Plug-In JavaScript 100 Power Solutions.pdf', 'Pragmatic.Guide+to+JavaScript.rar', 'Pragmatic.Guide.to.JavaScript.Nov.2010', 'SimpleJavaScript', 'SitePoint.The.Art.and.Science.of.JavaScript.Dec.2007.pdf', 'SitePoint.The.Art.and.Science.of.JavaScript.Dec.2007.rar', 'TheArt&ScienceOfJavascript', '\xc9\xee\xc8\xeb\xc7\xb3\xb3\xf6JavaScript.pdf', '\xbe\xab\xcd\xa8JavaScript (1).pdf', '\xbe\xab\xcd\xa8JavaScript.pdf', '\xc1\xe3\xbb\xf9\xb4\xa1\xd1\xa7JavaScript.rar']
  >>> os.listdir('f:\books\javascript')			# 此处会报错
  
  Traceback (most recent call last):
    File "<pyshell#3>", line 1, in <module>
      os.listdir('f:\books\javascript')
  WindowsError: [Error 123] : 'f:\x08ooks\\javascript/*.*'
  >>> os.listdir(r'f:\books\javascript')		# 这样写就不会报错
  ['Eloquent JavaScript.pdf', 'FunnyJS.txt', 'High.Performance.JavaScript.pdf', 'JavaScript DOM \xb1\xe0\xb3\xcc\xd2\xd5\xca\xf5.pdf', 'JavaScript.mm', 'Javascript\xbb\xf9\xb4\xa1\xbd\xcc\xb3\xcc.chm', 'JavaScript\xca\xb5\xd5\xbd\xca\xd6\xb2\xe1.rar', 'jQuery\xbb\xf9\xb4\xa1\xbd\xcc\xb3\xcc.pdf', 'JSON', 'Learn JavaScript and Ajax with w3Schools.pdf', 'Plug-In JavaScript 100 Power Solutions.pdf', 'Pragmatic.Guide+to+JavaScript.rar', 'Pragmatic.Guide.to.JavaScript.Nov.2010', 'SimpleJavaScript', 'SitePoint.The.Art.and.Science.of.JavaScript.Dec.2007.pdf', 'SitePoint.The.Art.and.Science.of.JavaScript.Dec.2007.rar', 'TheArt&ScienceOfJavascript', '\xc9\xee\xc8\xeb\xc7\xb3\xb3\xf6JavaScript.pdf', '\xbe\xab\xcd\xa8JavaScript (1).pdf', '\xbe\xab\xcd\xa8JavaScript.pdf', '\xc1\xe3\xbb\xf9\xb4\xa1\xd1\xa7JavaScript.rar']
  >>> path = r'f:\books\javascript\'			# 原始字符串不能以 "\" 结尾
  SyntaxError: EOL while scanning string literal
  >>> path = R'f:\books\javascript\'
  SyntaxError: EOL while scanning string literal

3.2 Python 数据类型——列表和数组
----------------------------------
列表是以方括号 "[]" 包围的数据集合，不同成员间以 "," 分隔。列表中可以包含任何数据类型，也可以包括另一个列表。
列表也可以通过序号来访问其中的成员。在脚本中可以对列表进行排序、添加、删除等操作，改变列表中的某一成员的值。
元组的特性与列表基本相同，元组是以圆括号 "()" 包围的数据集合。与列表不同的是，元组中的数据一旦确立就不能改变。
元组可以使用在不希望数据被其他操作改变的场合。

也就是说，列表中的数据是 mutable 的，而元组中的数据时 immutable 的。

下面的实例演示了在 Python 中列表和元组的使用。Python 提供了对列表操作的强大支持，常用的操作如表：::

	================	==============================================================
	    列表操作			描   			述
	================	==============================================================
	 list.append()		 追加成员
	 list.count(x)		 计算列表中的参数 x 出现的次数
	 list.extend(L)		 向列表中追加另一个列表 L
	 list.index(x)		 获得参数 x 在列表中的位置
	 list.insert()		 向列表中插入数据
	 list.pop()		 删除列表中的成员
	 list.remove()		 删除列表中的成员
	 list.reverse()		 将列表中成员的书序颠倒
	 list.sort()		 将列表中成员排序
	================	==============================================================

除此之外，在 Python 中也可以使用类似于字符串的分片和索引操作列表。而对于元组，没有上述的操作，只能对其使用分片
和索引操作。以下实例演示了 Python 中对列表和元组的基本操作。::

	>>> list = []				# 定义一个空列表
	>>> list.append(1)			# 向列表中添加成员
	>>> list.count(2)			# 计算 2 在列表中出现的次数
	0
	>>> list.extend([2, 3, 5, 4])		# 向列表中添加一个列表
	>>> list
	[1, 2, 3, 5, 4]				# 列表值被改变
	>>> list.index(5)			# 获得 5 在列表中的位置
	3					# 从 0 开始，即第 4 个
	>>> list.insert(2, 6)			# 从 0 开始，也就是在第 3 个成员处插入 6，其他成员顺次后移
	>>> list
	[1, 2, 6, 3, 5, 4]
	>>> list.pop(2)				# 删去列表中第 3 个成员
	6
	>>> list
	[1, 2, 3, 5, 4]
	>>> list.remove(5)			# 删除列表中的 5 ，注意与 pop 方法的区别
	>>> list
	[1, 2, 3, 4]
	>>> list.reverse()			# 颠倒列表的顺序
	>>> list
	[4, 3, 2, 1]
	>>> list.sort()				# 将列表中成员重新排序
	>>> list
	[1, 2, 3, 4]
	>>> tuple = ('a', 'b', 'c')		# 定义一个元组
	>>> list.insert(4, tuple)		# 向列表中插入一个元组
	>>> list
	[1, 2, 3, 4, ('a', 'b', 'c')]
	>>> list[4]				# 使用索引访问列表中第 5 个成员
	('a', 'b', 'c')
	>>> list[1:4]				# 使用分片获得列表中第 2 个至第 5 个成员，但不含第 5 个成员 -> [a, b)
	[2, 3, 4]
	>>> tuple[2]				# 获得元组中第 3 个成员
	'c'
	>>> tuple[1:-1]				# 获得元组中第 3 个程序至最后一个程序，但不包含最后一个
	('b',)

  需要注意的是，分片与索引它们两者返回值的不同。

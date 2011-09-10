第二章 Python 起步
==================

    Python 语法简单，容易学习。但是有一些容易出错的地方。比如：
        - 脚本结构
        - 基本输入/输出
        - 中文的使用
	- 把 Python 当作计算器

脚本基本结构
------------
    Python 脚本的结构非常清晰，在 Python 中不使用 C 语言中的花括号表示语句快，而是用缩进。代码缩进
    一般用在函数定义、类的定义以及一些控制语句中。一般来说，行尾的“:”表示代码缩进的开始。 ::

	if a > b:
	    print a		# 代码缩进，如果 a > b ，则执行 print a
	else:
	    print b		# 代码缩进，如果 a <= b ，则执行 print b

    下面是一个比较复杂的代码缩进 ::

	if a > b:
	    if a == 1:
		print a
	    else:
		if a == 0:
		    print a
		else:
		    pass
	elif a == b:
	    print a,b
	else:
	    print b	

    **Notes**
 
    处于同一级的代码缩进，其缩进量要保持一致，否则将导致错误。 ::

	if a > b:
	    if a == 1:
		print a
	    else:
		if a == 0:
		    print a
		else:
		    pass
	elif a == b:
	  print a
	    print b
	else:
	    print b

注释种类
--------
- # -> 单行注释
- ''' -> 多行注释
- """ -> 多行注释

demo
````
 ::

	'''
	三个单引号包围的注释
	该段代码判断 a,b 值的大小
	并根据不同的情况输出
	如果 a 大于 b 则输出 a
	如果 a 小于等于 b 则输出 b
	'''
	if a > b:	# 判断 a, b 的大小
	    print a 	# 输出 a
	else:
	    print b	# 输出 b
	"""
	三个双引号包围的注释
	代码判断结束
	print a
	上边的语句不会被执行
	"""

Semicolon 
---------
    在 Python 中，一般来说一条语句占用一行。一条语句结束一般不需要使用 C 语言中的“;”，但在 Pythonon 中也可以
    用 “;” 将两条语句写在一行。另外如果缩进语句中只有一条语句，可以以将其写在“:” ::

	if a > b:print a	# 缩进语句写在冒号之后
	else:print b		
	print a;print b		# 使用分号将两条语句写在同一行

单引号/双引号
-------------

    在 Python 中，单引号和双引号没有区别，都可用来包围字符串。另外，单引号中的字符串可以包含双引号，双引号中的
    字符串可以包含单引号，而不需要使用转义字符。 ::

	a = "What's your name?"
	b = 'I say: "What is your name?"'

使用 '''/""" 格式化字符
-----------------------
    另外使用 3 个单引号或者 3 个双引号所包围的字符不仅可以作为注释，还可以作为格式化的字符。当使用 Python 中的
    "print" 输出这些字符时，其格式保持不变。 ::

	a = '''
	这是格式化的字符
		此处的缩进将输出
	在这里也可以使用'
	或者"
	不影响
	"""
	当然还有三个双引号
	"""
	'''
	
	b = """
	这是三个双引号包围的
	格式化	    	字符
	'''
	"""

分行处理
--------
    在 Python 中如果语句较长，需要分成几行写时可以使用
- "\"
- "()"

使用 "\"
````````
    使用 "\" 将一条语句写成几行。 ::

	# 使用 "\" 续行
	# 需要注意的是 "\" 之后不能有任何字符
	# 不能在 "\" 之后使用 "#" 注释
	c = a * 2\
		+ b\
		- b\
		* 3
	# 使用圆括号

使用 "()"
`````````
    使用 "()" 将一条语句写成几行。 ::

	# 使用圆括号包围分成多行的语句
	# 在语句中可以使用 "#" 注释
	c = ( a *
	    	b - 1
		+ 3
		/
		2)

脚本基本结构
------------

    Python 中的基本输入语句是 "raw_input" 语句。该语句返回所输入的字符串，如果想要获取数字，可以使用 "int" 函数
    将字符串转为数字。::

	>>> raw_input('Input your name:')		# 使用 raw_input 提示输入
	Input your name:kysnail				# kysnail 为用户输入
	'kysnail'
	>>> name = raw_input('Input your name:')	# 将用户输入赋值给 name
	Input your name:kysnail
	>>> print name					# 输出 name
	kysnail
	>>> year = raw_input('The year:')		# 获取输入
	The year:2007
	>>> print year
	2007
	>>> year + 1					# year 加 1，这里导致错误，因为 year 为字符串型
	Traceback (most recent call last):
	  File "<stdin>", line 1, in <module>
	TypeError: cannot concatenate 'str' and 'int' objects
	>>> int(year) + 1				# 使用 int 函数将 year 转换成整型
	2008
	>>> 

    需要说明的是位于 "**>>>**" 命令提示符之后的为用户输入的语句。如果语句钱没有 ">>>" 命令提示符，则表示该语句
    为 Python 的输出。但由于使用了 "**raw_input**" 语句，因此在 "raw_input" 语句的提示之后需要用户输入。

类型转换函数
````````````
- float: 将字符串或者整数转换为浮点数
- str: 将数字转换为字符串
- chr: 将 ASCII 值转换为 ASCII 字符
- hex: 将整数转换为十六进制的字符串
- long: 将字符串转换为长整型
- oct: 将整数转化为八进制的字符串
- ord: 将 ASCII 字符转化为 ASCII 值
 
print 语句
----------

    Python 中的基本输出语句是 "print" 语句。使用 "print" 语句可以输出 Python 所有的数据类型，而不需要事先指定要
    输出的数据类型。

    如果自定义了某一新的类型或者类，可以通过重载 "_repr_" 让 "print" 语句支持。::

	>>> a = 0				# 输出整型
	>>> print a				# 输出内容
	0
	>>> b = 1				
	>>> print a + b				# 输出表达式的值
	1
	>>> print b				# 输出 b 的值
	1
	>>> s = "Hello"				# 定义字符串
	>>> print s				# 输出字符串
	Hello
	>>> t = 'World'				# 定义字符串
	>>> print t				# 输出字符串
	World
	>>> l = [1, 2, 3]			# 定义列表
	>>> print l				# 输出列表
	[1, 2, 3]
	>>> t = ('a', 'b', 'c')			# 定义元组
	>>> print t				# 输出元组
	('a', 'b', 'c')
	>>> print l, t				# 同时输出列表和元组
	[1, 2, 3] ('a', 'b', 'c')
	>>> print l, '\n', t			# 使用换行符
	[1, 2, 3] 
	('a', 'b', 'c')
	>>> for i in t:				# 循环输出
	... print i
	  File "<stdin>", line 2		# 在 Python 自带的交互式命令行下，需要键入缩进值
	    print i
		^
	IndentationError: expected an indented block
	>>> for i in t:				# 循环输出
	...     print i
	...					# 在空格缩进处按一下回车键即表示缩进结束 
	a
	b
	c
	>>> 

在 Python 中使用中文
--------------------
    在 Python 中可以使用中文，但想要对中文进行处理。在 Python 中，显示中文主要是字符编码的问题，如果处理不好将
    导致乱码。在计算机中，字符是以数字来表示的。字符通过字符编码将其转化为数字，以使计算机能够对其识别。

    为了将各种不同的语言都包含在统一的字符集中，满足国际间的信息交流，国际上制定了 UNICODE 字符集。UNICODE 字符
    集包含世界上所有语言字符，这些字符具有唯一的编号。通过使用 UNICODE 字符集可以满足跨语言的文字处理，有效地
    避免乱码的产生。
  
    在 Python 中可以在各种编码间相互转换。如果在交互式命令中使用中文，可以不做处理，一般不会出现乱码。如果在 ".py" 
    文件中使用了中文，则需要在文件的第一行使用如下语句指定字符编码集。::

	# -*- coding:utf-8 -*-

    其中 utf-8 表示使用 utf-8 编码，也就是 UNICODE 字符集。使用上述语句，仅指明脚本中包含非 ASCII 字符，而并未
    将字符编码转换为 utf-8 编码。如果要将字符编码改为 utf-8 ，则需要在保存的时候选择保存为 utf-8 的格式。

    在 Vim 中可以使用如下命令设置文件的编码。::

	:set fileencoding=utf-8

    需要注意的是，Vim 在有些情况下选择 utf-8 编码后容易导致乱码。

    除了使用 utf-8 编码以外，还可以使用 cp936、gb2312、ios-8859-1 等来指定字符编码，从而在 Python 脚本中使用中文。
    需要注意的是，如果在命令行界面中输出中文字符，则需要设定为 cp936.例如如下所示的脚本，将字符编码设定为 utf-8 ，
    并且保存为 utf-8 编码格式，运行脚本后显示乱码，这个问题主要出现在 cmd 的命令行中。诸如 Ubuntu 之类的系统对于
    默认的 locale 字符集默认为 utf-8 所以不会出现这种问题。::

	# -*- coding:utf-8 -*-
	# file: Chinese.py
	#
	chinese = '''
	在 Python 中使用中文
	需要注意字符编码的问题
	可以使用的字符编码有如下几种：
	utf-8 cp036 gb2312 iso-8850-1
	'''
	print chinese

    由于 Windows 的命令行采用的是 cp936 编码，而在上述脚本中采用的是 utf-8 编码，因此导致乱码。解决办法是，
    在脚本中使用 decode 和 encode 函数对字符重新解码、编码，或者，不将其保存为 utf-8 格式。如果仍然采用 utf-8 
    编码格式，则可以将脚本修改为如下所示。::

	# -*- coding:utf-8 -*-
	# file: Chinese936.py
	#
	chinese = '''
	在 Python 中使用中文
	需要注意字符编码的问题
	可以使用的字符编码有如下几种：
	utf-8 cp036 gb2312 iso-8850-1
	'''
	print chinese.decode('utf-8').encode('cp936')
                                                    
    可以发现 Python 对于字符集的处理真是方便。

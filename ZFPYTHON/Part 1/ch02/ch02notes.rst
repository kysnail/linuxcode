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

    下面是一个比较复杂的代码缩进::

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
 
    处于同一级的代码缩进，其缩进量要保持一致，否则将导致错误。::

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
========
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


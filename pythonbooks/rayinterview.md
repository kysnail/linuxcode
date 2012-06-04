## 1. 问答题：
现在需要为系统设计一个 CLI 接口，该接口需要满足如下功能：

    a. 提供如下命令：
        help 帮助命令，列出 CLI 提供的所有命令，或显示某一命令的帮助。
        status 命令，查看当前系统状态
        log	命令，查看系统输出日志
        trace	命令，跟踪调试系统

    b. 如何生成对应的系统帮助文档。

描述一下你的实现思路，可能需要用到的模块、工具等。

## 2. 简答题

### 2.1 Python里面如何实现tuple和list的转换？

函数tuple(seq)可以把所有可迭代的(iterable)序列转换成一个tuple, 元素不变，排序也不变。

    例如，tuple([1,2,3])返回(1,2,3), tuple(’abc’)返回(’a’.’b',’c')。如果参数已经是一个tuple的话，
    函数不做任何拷贝而直接返回原来的对象，所以在不确定对象是不是tuple的时候来调用tuple()函数也不是很耗费的。

函数list(seq)可以把所有的序列和可迭代的对象转换成一个list,元素不变，排序也不变。

    例如 list([1,2,3])返回(1,2,3), list(’abc’)返回['a', 'b', 'c']。如果参数是一个list, 她会像set[:]一样做一个拷贝。


### 2.2 请写出一段Python代码实现删除一个list里面的重复元素？
可以先把list重新排序，然后从list的最后开始扫描，代码如下：

### 方法一：

    #!/usr/bin/env python

    a = [1, 2, 2, 3, 2, 1, 5, 4]
    b = list(set(a))
    print b 

### 方法二：

    #!/usr/bin/env python

    a = [1, 2, 2, 3, 2, 1, 5, 4]

    if a:
            a.sort()

    last = a[-1]
    print last

    for i in range(len(a) - 2, -1, -1):
            if last == a[i]:
                    del a[i]
            else:
                    last=a[i]

    print a

### 方法三：

    #!/usr/bin/python

    a = [1, 2, 2, 3, 2, 1, 5, 4]
    b = {}
    b = b.fromkeys(a)
    print b
    a = list(b.keys())
    print a

### 2.3 介绍一下Python下range()函数的用法？
如果需要迭代一个数字序列的话，可以使用range()函数，range()函数可以生成等差级数。
如例：
for i in range(5)
print(i)
这段代码将输出0, 1, 2, 3, 4五个数字
range(10)会产生10个值， 也可以让range()从另外一个数字开始，或者定义一个不同的增量，甚至是负数增量
range(5, 10)从5到9的五个数字
range(0, 10, 3) 增量为三， 包括0,3,6,9四个数字
range(-10, -100, -30) 增量为-30， 包括-10, -40, -70
可以一起使用range()和len()来迭代一个索引序列
例如：
a = ['Nina', 'Jim', 'Rainman', 'Hello']
for i in range(len(a)):
    print(i, a[i])

## 3. 工具篇

### 3.1 有没有一个工具可以帮助查找python的bug和进行静态的代码分析？
有，PyChecker是一个python代码的静态分析工具，它可以帮助查找python代码的bug, 会对代码的复杂度和格式提出警告 Pylint是另外一个工具可以进行coding standard检查。

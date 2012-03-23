### 异常处理机制
异常处理机制是在有可能产生错误的程序代码区块，利用 Exception Class 来捕捉错误并处理。

在 C++ 中有三种送出异常的方式：

1. 程序在执行有错时，计算机自动送出；

2. 由设计员判断再使用 throw 指令送出例外；

3. 在一个函数（整个）使用 throw() 指令。


从整个异常处理的观点来看，以 try 方式在程序区块检测到异常时，会将异常送出程序区块，由
catch 捕捉，catch 再针对异常的 exception handler 看 catch 后的 "catches"(handlers) 有
没有办法捕捉住，若条件成立则执行 catch 后的程序块。

C++ 中异常处理使用的三个关键字为：

1. try\
2. catch\
3. throw\

使用异常处理需要在声明区加入头文件 #include <stdexceppt.h> 。


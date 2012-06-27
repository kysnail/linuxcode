## `#ifndef` & `#if !defined` 区别
基本上一样，不过后者的应用范围更大，可以支持多个预编译变量的检查： 

	#if (!defined(_DEBUG) && defined(USE_MYLIB))
	......
	#endif

这种情况用前一种方式就只能写一个嵌套的条件判断：   

	#ifndef _DEBUG
	#ifdef USE_MYLIB
	......
	#endif
	#endif

## if defined (WIN32) 和 if defined WIN32 之间有什么区别?

	#if defined (WIN32)
	#include <io.h>
	#include <sys/stat.h>
	#elif (defined (UNIX) && defined(_LARGEFILE64_SOURCE))
	#include <sys/types.h>
	#include <unistd.h>
	#include <limits.h>
	#endif

`if   defined   (WIN32)`   为什么不直接写成   `if   defined   WIN32` ?   难道两者间有什么区别?

实际上两者没有本质区别，更多在于使用习惯的不同。一般会把后面的内容加括号，而不是加载宏本身上。

	#define WIN32 (...)
	......
	#if defined WIN32



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


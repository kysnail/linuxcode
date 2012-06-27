## `ifdef` 与 `if defined`
`defined` 是预处理运算符。 `defined NAME` 是用来判断 `NAME` 是否被定义了（被用 `define` 定义了）。 

	#ifdef NAME == #if defined(NAME)
	#ifndef NAME == #if !defined(NAME)

但是在处理双重和多重判断时，defined的优势就显示出来了 

	#ifdef NAME1 
	#ifdef NAME2 
	...... 
	#endif 
	#endif 

可以写成

	#if defined (NAME1) && defined (NAME2)
	......
	#endif

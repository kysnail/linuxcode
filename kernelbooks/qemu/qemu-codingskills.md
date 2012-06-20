## ARRAY_SIZE
定义一个 `ARRAY_SIZE` 宏，便于求解数组大小，这种方式很好，比你单独写一个函数还要方便些。

具体的定义格式如下：

	#ifndef ARRAY_SIZE
	#define ARRAY_SIZE(a)	(sizeof(a) / sizeof((a)[0]))
	#endif

使用起来也很方便，例如：

	for (i = 0; i < ARRAY_SIZE(default_list); i++) {
		...
	}

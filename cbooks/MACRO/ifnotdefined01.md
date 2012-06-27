## `#if !defined` 意义和用法
先看段代码

	#if (macroname)
	{statement}
	#endif

如果 (macroname) 为真，也就是逻辑 1，则编译 {statement} 语句。如果 (macroname) 不为真，

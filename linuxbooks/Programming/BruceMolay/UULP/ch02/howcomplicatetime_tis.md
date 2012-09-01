## `time_t`
本书中，有些命令的抓图日期居然是 1993 年，可真够久远的。这么多年过去了，Unix/Linux 的发展，也使得在书中所指的位置，是无论如何也找不到 `time_t` 的定义了。我还是针对我自己的测试机，大概说一下现在我使用的这个版本是如何处理 `time_t` 这个结构体的。

### 为什么要这样做？
这样来回做类型定义，说是增加抽象，更能适应将来的变化，实际上带来的只是混乱，谁没有把 `pid_t`，`time_t` 当作整数用 `printf %d` 打印过的。当然如果换一个思维角度，则可能容易理解这样做的原因了：

	这样类型属于描述性定义，要得就是清晰易懂。

### 寻找过程

1. 定位 `time_t`

	/usr/include/time.h
	-------------------
	typedef __time_t time_t;

2. 定位 `__time_t`

	/usr/include/bits/types.h
	-------------------------
	# define __STD_TYPE	typedef
	...
	__STD_TYPE __TIME_T_TYPE __time_t;	/* Seconds since the Epoch */

3. 定位 `_TIME_T_TYPE`

	/usr/include/bits/typesizes.h
	-----------------------------
	#define __TIME_T_TYPE	__SLONGWORD_TYPE

4. 定位 `__SLONGWORD_TYPE`

	/usr/include/bits/types.h
	-------------------------
	#define __SLONGWORD_TYPE  long int

这里实际上 `types.h` 与 `typesizes.h` 是如下的关系：

	*-----------------------*
	|types.h                |
	|        *--------------*
	|        |typesizes.h   |
        *--------*--------------*

	/usr/include/types.h
	--------------------
	#include <bits/typesizes.h>	/* Defines __*_T_TYPE macros */

## c语言的宏定义 `if defined`
因为对于一个大程序而言,我们可能要定义很多常量( 不管是放在源文件还是头文件 ),那么我们有时考虑定义某个常量时,我们就必须返回检查原来此常量是否定义,但这样做很麻烦. `if defined 宏` 正是为这种情况提供了解决方案.举个例子,如下:

	#define ....
	#define ....
	........
	........
	#define a 100
	.......

此时，我们要检查a是否定义（假设我们已经记不着这点了）,或者我们要给a一个不同的值，就加入如下句子

	#if defined a
	#undef a
	#define a 200
	#endif

上述语句检验a是否被定义，如果被定义，则用#undef语句解除定义，并重新定义a为200

同样，检验a是否定义：

	#ifndef a    //如果a没有被定义
	#define a 100
	#endif

以上所用的宏中：#undef为解除定义，#ifndef是if not defined的缩写，即如果没有定义。

这就是#if defined 的唯一作用！
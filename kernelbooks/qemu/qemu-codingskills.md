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

## 使用 `fprintf` 函数调试 QEMU 源码
1. 由于在 MinGW 平台下调试 QEMU 源码，所以相应的调试环境比较难搭建；

	本想尝试搭建 eclipse + gdb + qemu 调试环境，后面还是以放弃告终。
	把这东西打起来估计比我直接看源码还费事，想想还是算了吧。

2. 正是由于上面的原因，所以只能通输出调试信息的方式进行代码阅读。
3. 明确一点，肯定不可能使用 printf 输出调试信息，那么在找合适的调试信息中间，又获得了很多其他的知识。比如下面一个 `fprintf` 的调用关系。

	fprintf -> vfprintf -> vsnprintf
	别小看这个调用关系，你先在需要做的就是实现这几个函数。
	学习 C 语言可变参数的使用。	

4. QEMU 源码中的很多输出函数居然都是用函数指针实现的。比如下面的

	main(Vl.c) -> list_cpus -> cpu_list_id(Cpus.c) -> x86_cpu_list(Cpu.c)

	cpu_list_id(Cpus.c) -> x86_cpu_list(Cpu.c) 这一个跳转最有意思，因为我在 Cpus.c 中 并不能找到
	对应的宏定义形式，而是在 Cpu.h 中找到了对应的宏定义信息

	~Cpu.h
	#define cpu_list_id x86_cpu_list

开始找了半天都没弄明白怎么回事，最后仔细查看了 `cpu_list_id` 函数所在的代码段在发现了原因：

	~Cpus.c
	void list_cpus(FILE *f, fprintf_function cpu_fprintf, const char *optarg)
	{
	/* XXX: implement xxx_cpu_list for targets that still miss it */
	#if defined(cpu_list_id)
		cpu_list_id(f, cpu_fprintf, optarg);
	#elif defined(cpu_list)
		cpu_list(f, cpu_fprintf);	/* deprecated */
	#endif
	}
	
平时只见过 `#ifdef` 命令，对于 `#if defined()` 还不是很清楚。实际上两者没有本质上的不同，只是某种类型更适合于某种场合而已。

	#if 后面可以跟一个复杂的表达式，而 #ifdef 只能跟一个简单的宏。
	参看 info cpp -> conditional syntax -> if (和 defined)部分。
	或者 man cpp

这样也就明确了，为什么 QEMU 源码中有这么多 `#if defined()` 了，因为逻辑上太复杂了。

再看一下英文的解释吧：

	4.2.3 Defined
	The special operator defined is used in #if and #elif expressions to test whether a certain name is defined
	as a macro, defined name and defined (name) are both expressions whose value is 1 if name is defined as a 
	macro at the current point in the program, and 0 otherwise. Thus, #if defined MACRO is precisely equivalent
	to #ifdef MACRO.

	defined is useful when you wish to test more than one macro for existence at once. For example,

		#if defined (__vax__) || defined (__ns16000__)
	
	would succeed if either of the names __vax__ or __ns16000__ is defined as a macro.

	Conditional written like this:

		#if defined BUFSIZE  && BUFSIZE >= 1024	

	can generally be simplified to just 

		#if BUFSIZE >= 1024

	since if BUFSIZE is not defined, it will be interpreted as having the value zero.

	If the defined operator appears as a result of a macro expansion, the C standard says the behavior is 
	undefined. GNU cpp treats it as a genuine defined operator and evaluates it normally. It will warn wherever
	your code uses this feature if you use the command-line option -pedantic, since other compilers may 
	handle it differently.

还有的人钻的更深，探究的更详细。他想了解当初这样设计的初衷是什么？ 要想深究这部分内容，估计要查看 `C 标准的 Rationale` 部分了。

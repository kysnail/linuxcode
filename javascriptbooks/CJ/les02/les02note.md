## JavaScript 基础知识

 * 定义变量的规则
 * 弱类型语言

    var n = 10;
    var s = "Hello";
    alert(n/s);   //  => NaN 并不返回错误值，而是返回此值。 Not a Number 的缩写。

 * 注释的方法
 * Undefined - 特殊类型
 * 字符串

    字符串不总是能转换成数字
    但数字总能转换成字符串

    alert(1+2+"3");		// => 33
    alert(1+2+"3"+4+5);		// => 3345
    alert(1+2+"3"+(4+5));	// => 339

 * += *= 
 * 布尔值
 * 逻辑运算符

    alert("a" < "b");	// => true
    alert("a" < "A");	// => false

 * 逻辑运算符

    &&	// and
    ||	// or
    !	// not

    alert(true && false);	==> false
    alert(false && true);	==> true
    alert(!true);		==> false

    alert(true < false);	==> false
    alert(true > false);	==> true

    alert(3 && 4);		==> 4
    alert(true && 3);		==> 3

 * 连用两个非运算符是将变量值转换成布尔值的快速方法

    alert(!!3);		// => true
    alert(!!0);		// => false

    alert(!!(3 && 4));	// ==> true

 * 快速与快速或

    true && false;	// ==> 快速与
    false && true;	// 

    false && a;		// 不会去判断 a 的值，返回 false
    true && b;		// 返回 b 的值
    var a = 123;
    var b = 0;
    alert(a && b);	// ==> b 返回最后判断的值

    true || false;	// 只要有一个为 true ，整个表达式为 true

    false || b;		// ==> 快速或

    alert(!!""Hello");	// !! -> 转换成布尔值 false
    alert(!!"");	// !! -> 转换为 true

    alert("Hello" && "");	// ==> ""
    alert("" || "Hello");	// ==> Hello

这个特性很重好，可以进行简单的逻辑判断。

    alert(true + "abc");
    alert("aaa"*1);
    alert("123"*3);
    alert(""*3);

    alert(typeof 3);
    var t = typeof 2;
    alert(t); 			// ==> number 

    var t = typeof !!"";
    alert(t);			// ==> boolean

## prompt 的使用

    var a = prompt("input a number", "");
    a *= 1;
    if (a == NaN) {
        alert("is NaN");
    }		// ==> 这种方法不被推荐！

    alert(NaN == NaN);		// ==> false
    alert(NaN === NaN);		// ==> false
    // NaN 是一个特殊的数值


    if (isNaN(a)) {
        alert("is NaN");
    }		// ==> 推荐使用此种方式！

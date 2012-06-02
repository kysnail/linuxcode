# ECMAScript语法基础

## 注释类型

    // 单行注释
    /* 多行注释 */
    <!-- 单行注释           早期的注释方法，不属于 ECMAScript 规定的。
    
    <!--
        避免不支持 JavaScript 的浏览器错误解析脚本。       
    //-->

## 注释小技巧

    if (false) {

    }

## 代码块

    {

    }

## 命名方法

    1. Camel 标记法 - 首字母是小写的，接下来的单词都以大写字母开头
    2. Pascal 标记法 - 首字母是大写的，接下来的单词都以大写字母开头
    3. 匈牙利类型标记法 - 在以 Pascal 标记法命名的变量前附加一个小写字母（或小写字母序列），说明该变量
                            的类型。例如 i 表示整型，s 表示字符串

## 变量使用前不用定义、赋值

## 全局变量 & 局部变量

    function func() {
        var a = ""; // 局部变量
        b = "";     // 全局变量
    }

## 关键字 & 保留字
注意区分 `关键字` 与 `保留字` 的区别。

## ECMA-262 
ECMA-262 定义了 ECMAScript 支持的一套关键字（keyword）。这些关键字标识了 ECMAScript 语句的开头和/或结尾。根据规定，关键字是保留的，不能用作变量名或函数名。下面是 ECMAScript 关键字的完整列表：

 * break
 * else
 * new 
 * var
 * case
 * finally
 * return
 * void
 * catch
 * for
 * switch
 * while
 * continue
 * function
 * this
 * with
 * default
 * if
 * throw
 * delete
 * in
 * try
 * do
 * instanceof
 * typeof

## ECMAScript 3 为以后保留的单词

 * abstract 
 * final
 * protect
 * boolean
 * float
 * public
 * byte
 * goto
 * short
 * char
 * impements
 * static
 * class
 * import
 * super
 * const
 * int
 * synchronized
 * debugger
 * interface
 * throws
 * double
 * long
 * transient
 * enum
 * native
 * volatile
 * export
 * package
 * extends
 * private

## ECMAScript 4 
ECMAScript 4 现在还没有什么实现，ECMAScript 4 中，下面的不再是保留字了，但也应该尽量不要使用它们。

 * boolean
 * final
 * short
 * byte
 * float
 * static
 * char
 * int 
 * double

下面的被加入了保留字

 * as
 * namespace
 * use
 * false
 * true
 * null
 * is 


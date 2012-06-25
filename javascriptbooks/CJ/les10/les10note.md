# 值,类型与类型转换

## 栈 & 堆
栈中查找速度快。

## 字符串转换为数字

    alert("123" * 1);       // 这种方式最简单，但是不保险。

## 原始值和引用值
在ECMAScript中，变量可以存放两种类型的值，即原始值和引用值。

 * 原始值（primitive value）是存储在栈（stack）中的简单数据段，也就是说，它们的值直接存储在变量访问的位置。
 * 引用值（reference value）是存储在堆（heap）中的对象，也就是说，存储在变量处的值是一个指针（point），指向存储对象的内存处。 

为变量赋值时，ECMAScript的解释程序必须判断该值是原始类型的，还是引用类型的。要实现这一点，解释程序则需尝试判断该值是否为ECMAScript的原始类型之一，即Undefined、Null、Boolean和String型。由于这些原始类型占据的空间是固定的，所以可将它们存储在较小的内存区域——栈中。这样存储便于迅速查寻变量的值。

    注意：这点是 JavaScript 与其他语言不同之处。
    在许多语言中，字符串都被看作引用类型，而非原始类型，因为字符串的长度是可变的。ECMAScript打破了这一传统。

如果一个值是引用类型的，那么它的存储空间将从堆中分配。由于引用值的大小会改变，所以不能把它放在栈中，否则会降低变量查寻的速度。相反，放在变量的栈空间中的值是该对象存储在堆中的地址。地址的大小是固定的，所以把它存储在栈中对变量性能无任何负面影响,如图:

    ![Stack Heap]()

堆栈就像我们的书一样,堆对应着书的正文内容,而栈对应的是书的目录,章节标题是简短的,所以在目录里面可以放,而文章的内容则不能放在目录里,我们只需要在目录放一个对应文章的标题和页码.这样,即可以在一本书中放大量的内容,又因为存在目录,可以快速查找内容!


## 原始类型
如前所述，ECMAScript有5种原始类型（primitive type），即

 * Undefined
 * Null
 * Boolean
 * Number
 * String

ECMA-262把术语类型（type）定义为值的一个集合，每种原始类型定义了它包含的值的范围及其字面量表示形式。ECMAScript提供了typeof运算符来判断一个值是否在某种类型的范围内。可以用这种运算符判断一个值是否表示一种原始类型；如果它是原始类型，还可以判断它表示哪种原始类型。

typeof运算符有一个参数，即要检查的变量或值。例如：

    var str = "some thing";
    alert(typeof str);//输出string
    var num =123;
    alert(typeof(num));//输出number,typeof运算符可以像函数一样使用
    //这主要运用于一些复杂的表达的以解决优先级问题
    alert(typeof num*3);//输出NaN,因为typeof优先于*
    alert(typeof(num*3));//输出number

对变量或值调用typeof运算符将返回下列值之一：

 * "undefined"，如果变量是Undefined型的 
 * "boolean"，如果变量是Boolean型的 
 * "number"，如果变量是Number型的 
 * "string"，如果变量是String型的 
 * "object"，如果变量是一种引用类型或Null类型的 

    你也许会问，为什么typeof运算符对于null值会返回"object"。这实际上是JavaScript最初实现中的一个错误，
    然后被ECMAScript沿用了。现在，null被认为是对象的占位符，从而解释了这一矛盾，但从技术上来说，它仍然是原始值。

如前所述，Undefined类型只有一个值，即undefined。当声明的变量未初始化时，该变量的默认值是undefined

    var a;
    alert(a);//输出undefined
    alert(typeof a);//输出undefined
    alert(a==undefined);//true

注意，值undefined并不同于未定义的值。但是，typeof运算符并不真正区分这两种值。考虑下面的代码：

    var tmp;
    alert(tmp);//undefined
    alert(typeof tmp);//undefined
    alert(typeof tmp2);//undefined

前面的代码对两个变量输出的都是"undefined"，即使只有变量tmp2是未定义的。如果不用typeof运算符，就对tmp2使用其他运算符，这将引起错误，因为那些运算符只能用于已定义的变量。例如，下面的代码将引发错误：

    alert(tmp3==undefined);//出错,因为变量tmp3未声明

当函数无明确返回值时，返回的也是值undefined，如下所示：
    
    function tmp() {}//空函数,没有返回值
    alert(tmp());//undefined



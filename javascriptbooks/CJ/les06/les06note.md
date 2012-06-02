## 对象创建方式

    var a = [];         // 数组字面量

    var obj = {         // 对象字面量
        name: "CJ",
        obj.name = "CJ",
        obj.age = "12",
        obj.weight = "23kg"
    };

优选上面这种字面量创建方式，而抛弃下面的方式：

    var a = new Array();

    var obj = new Object();

通常在对象字面量中的名值对中的名称中加引号，这样可以使用的范围就更广了：

    var obj = {         // 对象字面量
        "" : "CJ",
        "年龄" : 18,
    }

在 JavaScript 中对象与数组在很多情况下可以互通使用。

### 创建拥有 N 个空位的数组对象

    方法一：
    var a = [];
    a.length = N;

    方法二：
    var arr = new Array(N);

### 循环遍历
数组的循环使用序号，对象使用 `for ... in` 循环

    for (var i in obj) {
        // for in 循环 
        // foreach 循环
    }

## 一切皆对象
String 也是对象。

    var str = new String("This is a string");   // 创建一个字符串，这个方法不推荐使用。
    var str = "This is another string"

### replace
在 C 这类语言中，字符串可以原位改变，而在 JavaScript 这类语言中，字符串对象不可以被原位修改。

### setInterval 的使用

    The setInterval() method calls a function or evaluates an expression at specified intervals (in miliseconds).

上面是 `setInterval` 的解释。
    
    setInterval("alert('abc')", 1000)

上面这种方式已经不再推荐使用了。

    function func () {
        document.title = new Date();
    }

    var s = "滚动的字符串.....".split("");
    function func () {
        s.push(s[0]);
        s.shift();      // shift 方法，吧数组第一个元素去掉。
        document.title = s.join("");
    }

    setInterval(func, 10000);

## Array.push() & Array.shift()

 * push() - Adds new elements to the end of array, and returns the new length
 * shift() - Removes the first element of an array, and returns that element 

## Demo - Title Marquee


        <script type="text/javascript" charset="utf-8">
            var str = "..oOo..".split("");
            function titleMarquee() {
                str.push(str[0]);
                str.shift();
                //var s = push(str[0])
                document.title = str.join("");
            }

            setInterval(titleMarquee, 1000);
        </script>

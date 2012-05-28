## 数组和对象（1）

### 数组

### 创建数组

    var a = new Array();
	or
	var b = new Array(0,1,2,3);
	or 
	var c = new Array(2);	// 只有一个参数的时候，这个参数是数组的长度
	c[0] //	==> undefined
	c.length // ==> 2
	or 
	d = [];	// 创建一个长度为 0 的数组
	or
	d = [0, "string", 3, 8]

### 添加元素

    var d = [];		// 创建长度为 0 的数组；

	d[0] = 123;
	d[1] = 456;

	alert(d.length);	// 2

	d[d.length] = 123456;	// 向数组末尾添加了一个元素

从这里也可以看到从 0 计数的好处，可以实时引用 length 属性进行扩展。

	alert(d.length);
	alert(d[d.length - 1]);

使用 `push` 方法：

	d.push(456);		// push 方法专门用来想数组末尾添加元素
	var l = d.push(789);// push 方法的返回值，新的长度。
	d.push(12,12,12,12);// push 方法添加多个变量。

### delete 不是方法，而是一个特殊的运算符

	delete d[1];  <==>  d[1] = undefined;

** 删除特点长度不会变！ **

### join 方法
涉及到字符串的性能问题。

	// UTC 1970 1 1 0 0 0 0
	var date = new Date();
	date.setFullYear(1970);
	date.setMonth(0);
	date.setDate(1);
	date.setHours(8);		// 这里之所以设为 8 ，是因为我们在东八区。
	date.setMinutes(0);
	date.setSeconds(0);	
	date.setMilliseconds(0);	
	alert(date.getTime());	// 值为 0 

开始测试 join 方法，必须要能够显示测试时间。

	var date = new Date();
	var start = date.getTime();
	for (var i = 0; i != 10000000; i++) {
		Math.pow(i, i);
	}
	alert((new Date()).getTime() - start);
	
上面的这个测试很快，大概 5 毫秒。	

	var date = new Date();
	var start = date.getTime();
	for (var i = 0; i != 10000000; i++) {
		s += "ABC"
	}
	alert((new Date()).getTime() - start);

涉及字符串操作，所以就比较慢一些。而如果将 `s += "ABC"` 修改为：

	var date = new Date();
	var start = date.getTime();
	for (var i = 0; i != 10000000; i++) {
		a.push("ABC");
	}
	s = a.join("");
	alert((new Date()).getTime() - start);

这种方式则要比上面直接相连的方式要快一倍。好像 python 也是一样的特点。Python 中每当涉及到字符串连接时，都会重新创建一个对象，所以相对较慢。

	var s = "Start";
	var a = ["Start"];

	var date = new Date();
	var start = date.getTime();
	for (var i = 0; i != 10000000; i++) {
		s += "ABC";
	}
	alert("字符串相连：" + ((new Date()).getTime() - start));

	for (var i = 0; i != 10000000; i++) {
		a.push("ABC");
	}
	s = a.join("");
	alert("使用数组：" + ((new Date()).getTime() - start));

在连接大量字符串时，通常会选择下面的方法，性能会好很多。

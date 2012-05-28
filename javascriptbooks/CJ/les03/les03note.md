## 分支判断与循环
基本上所有的类 C 语言都不支持注释掉嵌套。所以可以使用下面的技巧。

    if (false) {
        /*alert("A");
        alert("A");
        alert("A");*/
        alert("A");
        alert("A");

    } // end if (false)

需要的时候，将 false -> true 。

### JavaScript 没有 `elseif` 语句，只有 `else if` 语句。

	if () {

	} else {

	}

为了避免逻辑上的混乱，最好多加 `{}` 解决逻辑混乱的问题。

    alert(""*1); // ==> 0

### `switch` 语句

    switch(a) {
	case 1:
		...
		break;
	case 2:
		...
		break;
	default:
		...
		break;
    }

### `for` 循环语句

    for (初始化语句; 条件判断; 更新计数器) {
		
	}

### `while` 循环语句

    var b = true, num;
    while (b) {

	}

    while (true) {
		alert("关不上的窗"); 	// 这段臭名昭著的代码在不同的浏览器上执行效果不同，
								// 而且新版的浏览器对于此种死循环代码都会有所提示。
	}

### `do ... while` 循环语句

    do {
		...
	} while ($counter);

### `for ... in` 循环语句
在讲解数组和对象时使用。

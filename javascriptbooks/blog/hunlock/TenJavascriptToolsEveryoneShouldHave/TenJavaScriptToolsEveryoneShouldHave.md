## Ten Javascript Tools Everyone Sould Have
Javascript framework have exploded on the scene over the last few years but they're no replacement for a good toolbox: those little snippets of code you seem to include in every single project. Here's my list of 10 essential Javascript tools everyone should have at their fingertips!

### #0-Trim.
Trim is one of the things that leave you scratching your head why it was never included in the language to begin with. Thanks to prototyping however it's fairly easy to make up for the original oversight.

	String.prototype.trim = function() {
		/*
		 *  grammer: /pattern/attributes
		 *  attributes:
		 * 		i - 执行对大小写不敏感的匹配 
		 *		g - 执行全局匹配（查找所有匹配而非在找到第一个匹配后停止）
		 *		m - 执行多行匹配
		 *  量词-Quantifiers	
		 *	^n - 匹配任何开头为 n 的字符串。
		 *	n$ - 匹配任何结尾为 n 的字符串。	
		 *	n+ - 匹配任何包含至少一个 n 的字符串
		 *		
		 *  元字符 - Metacharacter
		 *	\s - 查找空白字符
		 *	
		 *	
		 *       | - 这里的 | 相当于或的作用
		 */
		return this.replace(/^\s+|\s+$/g, "");
	}

	String.prototype.ltrim = function() {
		return this.replace(/^\s+/g, "");
	}

	String.prototype.rtrim = function() {
		return this.replace(/\s+$/g, "");
	}

Usage...

	var test = "   		Test	  ";
	var test1 = test.ltrim();		// return "Test      "
	var test2 = test.rtrim();		// return "      Test"
	var test3 = test.trim();		// retrn "Test"

Trim is so common that it's pretty much a freebie on any Javascript list so we'll count this as zero and give you ten more.

### #1 - Numeric Sort.
Javascript's Array object has a sort() method, and a pretty quick and fast one at that (at that - 而且). Unfortunately, by defualt, it only sorts alphabetically. Which means if you pass it an array of numbers it will sort the array alphabetically instead of numerically (1,15,100,2,25,200 instead of 1,2,15,25,100,200). This is easy enough to fix however by adding a new method called `sortNum` which will sort a numerical array very nicely.

	Array.prototype.sortNum = function() {
		return this.sort( function(a, b) { return a - b; });
	}

Usage...

	var tmp = [5,9,12,18,56,1,10,42,30,7,97,53,33,35,27];
	tmp = tmp.sortNum();	// returns 1,5,7,9,10,12,18,27,30,33,35,42,53,56,97 

`Array.sort` 方法被设计的具有很强的扩展性，这在其他语言中也有同样的思路。

如果想按照其他标准进行排序，就需要提供比较函数，该函数要比较两个值，然后返回一个用于说明这两个值的相对顺序的数字。比较函数应该具有两个参数 a 和 b，其返回值如下：

 * 若 a 小于 b，在排序后的数组中 a 应该出现在 b 之前，则返回一个小于 0 的值。
 * 若 a 等于 b，则返回 0。
 * 若 a 大于 b，则返回一个大于 0 的值。

### #2 - Formatting Numbers
Formatting a number with commas is an all-too-often needed ability which is not a part of core language. Here's short and sweet tool that will correct that deficiency and another function to revert the formatted string back into a usuable number. Simply supply a number and an optional prefix ('$' for example) and get back a formatted (or unformatted) string.

	function formatNumber(num, prefix) {
		prefix = prefix || '';
		num += '';
		// 数字以 . 号分隔
		var splitStr = num.split('.');
		var splitLeft = splitStr[0];
		var splitRight = splitStr.length > 1 ? '.' + splitStr[1] : '';
		// 正则表达式中的圆括号除了能将多个元素组合成一个可统一操作的组合项外，它所括起来的
		// 表达式部分还成为了一个子匹配（也叫子表达式），也就是说，我们可以用圆括号在一个
		// 长的正则表达式中划分出子表达式。这样，除了可以得到整个正则表达式的匹配结果外，还可以
		// 单独得到每个子表达式部分所匹配的结果。
		http://developer.51cto.com/art/201106/266703.htm
		var regx = /(\d+)(\d{3})/;
		while (regx.test(splitLeft)) {
			splitLeft = splitLeft.replace(regx, '$1' + ',' + '$2');
		}
		return prefix + splitLeft + splitRight;
	}

	function unformatNumber(num) {
		return num.replace(/([^0-9\.\-])/g, '') * 1;
	}

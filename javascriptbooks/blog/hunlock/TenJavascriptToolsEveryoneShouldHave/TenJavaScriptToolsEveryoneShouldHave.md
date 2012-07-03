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

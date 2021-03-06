利用通配符操作文件
==================
通配符的英文是 wildcard ，英文原意是扑克牌中可以替代其它任何牌的那张牌。台湾人将 wildcard 翻译为
万用字元。

**Notes**

 将一种语言十分准确的翻译为另一种语言是一件相当困难的事，甚至有专家认为语言是不能翻译的，因为语言
 是基于文化的。因此如果读者想在 IT 领域长期混下去，最好花些时间提高一下英语水平，因为最新的 IT 资
 料一定是英文的，而且多数英语教材比中文教材准确（这可能部分是由于语言本身的特性造成的，因为中文的
 二义性比较多，所以中文适合写诗，可以写出非常美的诗，因为不同的人可以有完全不同的理解）。

在有些 UNIX 书中将通配符称为元字符（metacharacter，所谓的元字符就是描述其它数据的字符），Linux 操
作系统提供了如下的通配符： 

=========		============================================================
mark			description
=========		============================================================
``*``			将匹配 0 个（即空白）或多个字符
``?``			将匹配任何一个字符而且只能是一个字符
[a-z]			将匹配字符 a~z 范围内的所有字符
[^a-z]			将匹配所有字符但是 a~z 范围内的字符除外
[xyz]			将匹配方括号中的任意一个字符
[^xyz]			将匹配不包括方括号中的字符的所有字符	
=========		============================================================

example 1:
----------
::

	$ ls
	ch05  README
	$ ls -F
	ch05/  README

	-F, --classify
		append indicator (one of */=>@|) to entries


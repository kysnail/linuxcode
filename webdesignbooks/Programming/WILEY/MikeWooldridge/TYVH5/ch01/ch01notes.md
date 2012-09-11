#Chapter 1: Getting Started with HTML5 and Web Pages

 * serve as - 充当， 担任； 为
 * starting point - 出发点； 起始点

## Internet Basics

### Type of Connections

 * topped - The sun topped the horizon
 * ISPs - Companies that help you connect to the Internet are know as Internet service providers.

### Internet Devices

### Communication Standards

 * TCP/IP - Transmission Control Protocol/Internet Protocol
 * HTTP - Hypertext Transfer Protocol
 * agreed upon - [经] 同意，商定

### The World Wide Web

 * serve up - 端上桌； 上菜； 提供； 发送

### URLs and Links

### Browsers

## Introduction HTML5

### HTML Tags

 * intersperse with - 用…点缀着 - HTML consists of text interspersed with special instruction known as tags.

这里举了一个导航条的示例，现在的导航条貌似都用列表 + CSS 的方式实现：

	<nav>
		<ul>
			<li>Home</li>
			<li>Destinations</li>
			<li>Travel Tips</li>
			<li>Contact Us</li>
		</ul>
	</nav>

### Rendering HTML

### HTML Standards

 * Consortium - 财团； 组合，共同体； [法]配偶的地位和权利； <美>大学联盟协定

The HTML5 standars was originally developed by a separated organization called the Web Hypertext Application Technology Working Group (WHATWG). In 2007, the W3C adopted WHATWG's version as the starting point for its version of HTML5.

### HTML Versions
The most recent version of HTML is HTML5. As this book is been written, the HTML5 specification is still under development, but many popular web browsers already support much of the HTML5 functionality. Version 5 includes rules for using more than 100 different HTML tags, most of which are covered in this book. HTML5 improveson previous versions by including new tags for defining common types of page content, better support for audio and video, and drawing capability with the new <canvas> tag. HTML5 succeeds HTML 4.01, which was released in 1999.

### Browser Support
The development of a new HMLT5 standard and the appearance of new features in web browsers are both gradual processes.

### XHML
XHTML, or *Extensible Hypertext Markup Language*, is an alternative version of HTML that conforms to the stricter standars of XML, or *Extensible Markup Language*. XHTML is tag based and uses many of the same tags as HTML. However, in XHTML, all tags must be closed, tag name and attributes must be coded in lowercase, and attribute values for tags must be surrounded by quotes. For a time, the W3C group was developing a new XHTML 2.0 standard to take the place of HTML 4.01. In 2009, the group switched course to focus instead on HTML5. For more about XHTML, visit the W3C site at www.w3.org.

## Explore Web Browsers

### Finding a Browser

 * come with - 伴随…发生，与…一起供给

For more information about web browsers, see 

 * http://www.wooldridge.net/html5

### Browser Discrepancies

 * discrepance - 差异，分歧，残余项
 * as always - 一如往常； 一如既往
 * it will be some time before all of the major browsers support the complete standard.

## Explore HTML Editors

 * higher-end - high-end

### Simple Text Editors

 * no-frills - 不提供不必要服务的； 不加装璜

Simple text editors, also called plain-text editors.

### HTML Editors

 * dedicated - 注的，投入的； 献身的； 专用的
 * shield ... from - 遮蔽， 挡住使不受…的伤害； 使免遭(不幸之事)

### Word Processing Programs

## Understanding HTML5 Syntax

 * not at all - 别客气； 没什么，哪儿的话； 并不； 不谢

### Writing HTML5
 
### Tag Structure

	<!DOCTYPE html>
	<html>
	<head>
		<title>M and B Adventure Travel</title>
		<link rel="stylesheet" type="text/css" href="styles.css">
	</head>
	<body>

### Text Styling 
One of the key changes in HTML5 is the removal of many style-related instructions from HTML tags. In HTML5, tags are meant to tell a browser what text on a page means rather than how it looks. For example, an `<h1>` tag defines text as an important heading but does not specify what color or font it is, or how it is aligned on a page. When using HTML5, you provide style instructions for your text by including Cascading Style Sheets, or CSS. CSS works in connect with HTML to specify colors, alignment information, and other details about how content look on the page. CSS is introduced in Chapter 4.	

### Other Tags

### Attributes and Values

	<p style="color: red">My colorful text.</p>

tags can be devided into 

 * opening tag
 * closing tag

Atributes always go inside the opening HTML5 tag, and enclosing attribute values in quotation marks is good form.

### Entities

 * entities - 实体对像； 实体，独立存在体，实际存在物（ entity的名词复数 ）实体对像； 

What's the real meaning of entities in html5?

	You can add special characters to a page, such as a copyright symbol or a fraction, by using 
	special codes called entities.
-

 * readily - 乐意地； 快捷地； 轻而易举地； 便利地

-

	Entities represent characters not readily available on the keyboard.

All entities are preceded by an ampersand (&) and followed by a semicolon (;);.

	&copy;
	&lt;

### Avoiding Syntax Errors

 * reverse order - 倒序
 * leniency - 宽大，仁慈

-

	Testing your web pages in multple web browsers can also be a good way to discover syntax
	erros because browsers can vary in their leniency to certain types of errors.

## New Features in HTML5

 * roll out - 铺开； 起床； 滚了出来； 滔滔不绝地讲出来
 * average - 平常的； 平均的； 典型的； （价值、比率等的）平均数的
 * integral - 完整的； 积分的； 必须的

### Semantic Tags

 * Semantic - <语>语义的，语义学的  

Demo: 使用列表项制作导航，是现在最流行的方式。

	<nav class="horiz">
		<ul>
			<li><a href="index.html"></a></li>
			<li><a href="adventures.html"></a></li>
			<li><a href="blog.html"></a></li>
			<li><a href="contact.html"></a></li>
		</ul>
	</nav>

	<aside class="right-side">
		<h1>Related Photos</h1>
		<img src="bungee.jpg"><br>
		<img src="bungee2.jpg">
	</aside>

-

 * boilerplate - 样板文件； 公式化，陈词滥调
 * prominently - 显著地，重要地

### Richer Multimedia

 * extreme skiing - 极速滑雪

-

	HTML5 offers a new `<video>` tag for embedding video clips into your pages and an `<audio>` tag for integrating
	sound. In the past, developers used the nonstandard `<embed>` tag and the generic <object> tag for adding
	multimedia. The <embed> and <object> tags passed the duities for playing the video or sound to third-party plugins.
	Web browsers that support the new <video> and <audio> tags include native support for certain video and audio files,
	which means the browsers play the content directly. With the tags, web developers can create custom player controls,
	style the media with CSS, and more.

-

### Drawing on Canvases

 * canvas - 帆布； 油画（布）

### Fancier Forms

 * fancier - 发烧友； 对莫事物有特别爱好的人； 空想家

### Moving Styles to CSS
In addition to adding new features, the standards groups that designd HTML5 has also taken some features away. Most of these deprecated features are tags and attributes that previously enabled you to apply formatting to content on your page.

	<p align="right">My old aligned paragraph.</p>    <--- Invalid in HTML5
	<p aligh="aligh-right">My new alighed paragraph.</p>   <--- Valid in HTML5

## View HTML5 Code in a Browser

 * tag highlighted in color

### View HTML5 Code in a Browser

#### View the Source Code

## TIPS

 * How else can I...? - How else can I apologize for her? - 我还能有别的方法可以向她道歉吗？


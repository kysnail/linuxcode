# Chapter 3: Adding and Modifying Text

 * alphanumeric - adj.文字数字的，包括文字与数字的

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<h1>What's in a Bag?</h1>
			<dl>
				<dt>Backpack</dt>
					<dd>A bag for carrying hiking supplies and launch</dd>
				<dt>Fannypack</dt>
					<dd>A bag for carrying passport, wallet, and camera</dd>
				<dt>Suitecase</dt>
					<dd>A bag for carrying clothes and toiletries</dd>
				<dt>Briefcase</dt>
					<dd>A bag for carrying business documents, files, and pens</dd>
			</dl>
		</body>
	</html>

-
 * Backpack - （指登山者、步行者使用或背小孩时使用的）背包， （有轻金属框的）箱形背包; vi.背着背包徒步旅行
 * hiking - 徒步旅行
 * Fannypack - belt pack, belly bag... more details on wikipedia
 * Suitecase - 行李箱
 * toiletries - n.化妆品； 化妆品，化妆用具（ toiletry的名词复数 ）
 * Briefcase - n.公文包； 手提包； 公事包； 手提箱
 * Briefcase computer - 1. a portable computer housed in a box that resembles a briefcase

## Create a New Paragraph

	1. Paragraphs are left-aligned by default, but you can specify a different alignment useing CSS.
	2. Paragraph text is normal-sized and unstyled by defeult. To add bold or italic styling, or to change the 
	   text to small print, see the other sections in this chapter.

-

 * print - （由底片印出的）照片； 印刷字体； 印痕； 印成的图画

### Create a New Paragraph

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			Machu Picchu
			
			<p>Located in the Peruvian Andes, the ancient Inca city of Machu Picchu was constructed in
			the 1400s at the height of the Inca Empire.</p>
			<p>It was abandoned less than 100 years later when the Inca empire collapsed under Spanish
			conquest. Today Machu Picchu is the most visited tourist attaction in Peru.
		</body>
	</html>

-
 * Peruvian Andes - 秘鲁安第斯山脉
 * Inca city - 印加城
 * Machu Picchu - 马丘比丘（Machu Picchu）被称作印加帝国的“失落之城”。
 * Inca empire - 印加王国
 * collapsed - v.折叠（ collapse的过去式和过去分词 ）； 倒塌； 崩溃； （尤指工作劳累后）坐下
 * Peru - 秘鲁
 * set off from - vt. set apart; cut off from others 使隔离，使孤立

## Add a Line Break

	You can also use the <br> tag to add blank lines between paragraphs. This is useful if you
	want to add extra space above or below a block text or a heading.
	By inserting multiple <br> tags consecutively, you can increse the amount of space.

### Add a Line Break

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			Shakeseare's Sonnet XXVII

			<p>Weary with toil, I haste me to my bed,
			<br>The dear repose for limbs with travel tired;
			<br>But then begins a journey in my head,
			<br>To work my mind, when body's work's expired...
			</p>
		</body>
	</html>

Note:

	You do not need a closing tag for the <br> tag.

whe a web browser displays the page, each instance of the tag creates a new text line.

## Add a Line Break Opportunity

	<wbr> -> word break - is a new tag in HTML5

You can use the `<wbr>` tag to specify where a browser may add a line break if needed.

	You can use this tag for long words that might present problems if they were to appear near
	the end of a line and cause awkward spacing.

The `<wbr>` tag differs from the `<br>` tag in that it results in a new line only if the flow of text requires it.

### Add a Line Break Opportunity

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p>Snorkeling in Hawaii, we saw triggerfish, surgeonfish, sole, grouper, aha, tuna, ulua,
			unicornfish, tilapia, wrasse, and humuhumu<wbr>nukunuku<wbr>apuaa
		</body>
	</html>
-
 * humuhumunukunukuapuaa -  The reef, rectangular, or wedge-tail triggerfish, also known by its Hawaiian name, humuhumunukunukuāpuaʻa
 * snorkeling - 1. skin diving with a snorkel
 * triggerfish - n.热带鱼的一种
 * surgeonfish - n.刺尾鱼科鱼（热带鱼的一种）
 * sole - n.鞋底； 有……底的 -soled； 脚底； 鳎（可食用比目鱼）
 * grouper - n.鲶科鱼
 * aha - int.啊哈（表示惊讶、胜利、嘲弄等）
 * tuna - n.<鱼>金枪鱼（科），鲔鱼； 金枪鱼罐头； <植>金枪仙人掌
 * ulua - n.竹荚鱼（Trachurus）
 * unicornfish - [医]菲氏独角鱼
 * tilapia - n.罗非鱼
 * wrasse - n.濑鱼； 隆头鱼

Tye `<wbr>` in your text where you want to specify that a line break should occur if needed.

Note:

	You do not need a closing tag for the <wbr> tag.

有疑问的一句话：

	If the <wbr> occurs at the end of a line, the web browser applies a line break.

## Add a Horizontal Rule

 * dividing line <--> horizontal rule
 * setting off - 使爆炸，出发； 断流

-

	By default, most browsers display a horizontal rule as a thine gray line. Horizontal rules must occupy a 
	line by themselves and cannot appear within a paragraph.

### Add a Horizontal Rule

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			M and B Adventure Travel

			<hr>   <--- where you want to insert a horizontal rule.
			       <--- The browser diplays the line across the page.

			For more than 10 years, M and B Adventure Travel has helped customers fulfill
			their dreams and conquer their fears. We specialize in one-of-a-kind vacation
			packages to the most exciting destinations in the world. Let us help you with
			your hotel bookings, helicopter tours, and shark-cage rentals, either onlie or 
			in person.
		</body>
	</html>

-

 * in person - 亲自，亲身

Note:

	You do not need a closing tag for the <br> tag.

## Insert a Blank Space

 * blank space - 空白（区） - a blank area
 * graphic - adj.  图解的，用图表示的； 用文字表示的； 形象的，生动的
 * `&nbsp;` - nonbreaking space

-
	Adding a nonbreaking space is an alternative to inserting a line break tag, <br>, which add
	space between lines of text. You can also add space around elements on your page with CSS styles.
-

### Insert a Blank Space

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p>M and B Adventure Travel</p>

			<--- The browser displays blank spaces in the line
			<--- In this example, the blank spaces indent a paragraph
			<p>&nbsp;&nbsp;&nbsp;&nbsp;For more than 10 years, M and B Adventure Travel has 
			helped customers fulfill their dreams and conquer their fears. We specialize in 
			one-of-a-kind vacation packages to the most exciting destinations in the world.
			Let us help you with your hotel bookings, helicopter tours, and shark-cage 
			rentals, either onlie or in person.
		</body>
	</html>

The code stands for *nonbreaking space*. Web browsers do not create a line break where you insert these characters. For more about special characters, see "Insert Special Characters."

Note:

	You can also indent a paragraph using the text-indent CSS declaration. See Chapter 5 for details.	

## Make Text Bold

 * emphasize - vt. 强调，着重； 加强语气； 使突出 
 * passage - n. （文章的）一段； 经过； 通路，通道； 旅程，行程

-

	set them off 
	------------
	1.Insurgents had put them in bins around the city and set them off by mobile phones to terrify voters.
	暴动者将这些水瓶放在城市各处的垃圾箱中，用手机将它们引爆，威吓选民。
	2.“Someone who is unhinged, someone who is mentally unstable, we don't know – the slightest thing could set them off,” she said.
	“那些没有被暗示的，是思想上不坚定的，我们并不知道是谁——见微知著即可将其排除在外，”她说道。
	3.This is the same animal, Cricetomys gambianus, that has been trained to sniff out land mines.(It is light enough not to set them off.)
	同一种老鼠还被训练用于嗅出地雷的位置，它们的体重比较轻不能触发地雷。

-

另外需要注意的是：

	In most browsers, the <strong> tag has the same effect as the <b> tag.

### Make Text Bold

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p><b>M and B Adventure Travel</b></p>
			<-- When displayed in a Web browser, the text appears as bold.

			<p>Extreme vacations are our specialty</p>
			<p>For more than 10 years, M and B Adventure Travel has 
			helped customers fulfill their dreams and conquer their fears. We specialize in 
			one-of-a-kind vacation packages to the most exciting destinations in the world.
			Let us help you with your hotel bookings, helicopter tours, and shark-cage 
			rentals, either onlie or in person.</p>
		</body>
	</html>

Note:

	To create bold text using the font-style property in CSS, see Chapter 5.

## Italicize Text

	set it off
	----------
	这个词还是比较难解释的。
	
	作为专业词汇，他悲愤译为电影名 

		set it off - 辣姊妹

	但这里解释为衬托比较好：

		For all its beauty the lotus needs its green leaves to set it off.

-

 * set apart - 分开放；  隔离开； 留出； 突出
 * italicize - vt. 用斜体字排字，在字下划横线

-

	You add italicized text to a page by surrounding the text with <i> and </i> tags.
	In most browsers, the <em> tag has the same effect as the <i> tag.

### Italicize Text

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p><b>M and B Adventure Travel</b></p>

			<p><i>Extreme vacations are our specialty</i></p>
			<-- When displayed in a Web browser, the text appears in italics.
			<p>For more than 10 years, M and B Adventure Travel has 
			helped customers fulfill their dreams and conquer their fears. We specialize in 
			one-of-a-kind vacation packages to the most exciting destinations in the world.
			Let us help you with your hotel bookings, helicopter tours, and shark-cage 
			rentals, either onlie or in person.</p>
		</body>
	</html>

Note:

	To italicize text using the font-style property in CSS, see Chapter 5.

## Insert Preformatted Text

 * `<pre>` - preformatted tag

Web browsers ignore

 * hard returns
 * line breaks
 * extra spaces between words

unless you surround the content with preformatted tags.

	hard return vs soft return
	--------------------------	
	A hard return is a paragraph break in a word processor. It differs from a soft return in that it starts a new paragraph.
	Besides affecting the document statistics, this mean that:

	   * Often, extra space and a first line indent will be inserted.
	   * The next line cannot become an orphan, nor the previous line a widow, if the word processor is set to control for this.

	In most word processors, word wrap is handled automatically, neaning that manual soft returns are rarely if never needed,
	so pressing Enter starts a new paragraph.

	widow - 寡妇； 遗孀； [牌]放在一边的几张牌； [印]未排足的行
	orphan - n. 孤儿

Preformatted text is also useful for displaying computer code on a web page because the exact spacing of such code can be important.

### Insert Performatted Text

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p>Don't Forget</p>
			<pre>
		Fannypack		Passport, wallet, shark repellant
		Suitcase		Clothes, toiletries
		Briefcase		Business documents, files, pens
		Laptop bag		Computer, power cable, mouse
		Duffel bag		Camping equipment, tent
		Backpack		Parachute
			</pre>
		<--- When displayed in a Web browser, the text retains all your original line breaks and spacing.
		</body>
	</html>

Note:

	Browsers display preformatted text in a monospace font by default. All characters in a monospace font
	have equal width. This can help align words within the text into columns.

## Insert a Heading
既然 html - 内容表示层与 css - 样式表现层两者是分离的，又为什么会出现诸如 `<h1>` - `<h6>` 这样的标签呢？

对于那些不能够借鞋 CSS 的设备，如果不设置上面的这类标签，则文档结构很难表现出来。

	You can use headings to help clarify information on a page, organize text and create virtual structure.

### Insert a Heading

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<-- The heading appears in bold text in the web browser.
			<-- This figure shows an example of each heading size in descending order.
			<h1>Hang Glider</h1>
			<h2>Bicycle</h2>
			<h3>Snow Skis</h3>
			<h4>Bungee Cord</h4>
			<h5>Underwater Camera</h5>
			<h6>Water Bottle</h6>
		</body>
	</html>

-

 * Hang Glider - ①悬挂式滑翔机②从事悬挂式滑翔机运动的人
 * Snow Skis - ski 滑雪板（ ski的名词复数 ）
 * Bungee Cord - I love bungee cord jumping.
 * Underwater Camera - 1. 水下相照机 2. 防水照相机
 * Water Bottle - A water bottle is a vessel used to hold water or other beverages for consumption. 

## Add a Bolck Quote

 * set off - 出发； （使）开始； 引起； 点燃

### Add a Block Quote

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
		<-- The web browser displays the block quote as insert text on the ducument page.
		<blockquote>It was to late to take risk now. I asked Tenzing to belay me strongly, and I 
		started cutting a curious line of steps up the ridge. Peering from side to side and
		thrusting with my ice axe, I tried to discover a possible cornice, but everything seemed
		solid and firm. I waved Tenzing up to me. A few more whacks of the ice-ax, a few very 
		weary steps, and we were on the summit of Everest.</blockquote>

		Sir Edmund Hilary
		</body>
	</html>

-

 * belay - v.把绳索拴在系绳栓上
 * thrusting - v.猛推（ thrust的现在分词 ）； 猛塞； 刺； 戳
 * cornice - n.檐口 
 * whack - n.重击； 一份儿； 尝试； 状况
 * weary - adj.疲倦的； 困乏的； 令人厌倦[生厌，发腻]的； 感到厌倦的
 * Everest - n.珠穆朗玛峰（世界最高峰）[人名] [英格兰人姓氏] 埃弗里斯特住所名称，来源于凯尔特语，含义是“紫杉树”（yew tree）
 * yew - n.紫杉； 紫杉木

Note:

	You can mark text within a passage as quoted using the <q> and </q> tags. The
	web browser adds quotation marks to the surronded text.

## Add Small Print
You can add small print to your page by surrounding text with `<small>` and `</small>` tags. Small print typically includes 

 * disclaimers - n.否认声明； 放弃； 放弃者
 * legal restrictions - legal obligation and restriction 法定义务及限制
 * copyright information
 * and other subordinate comments - adj.级别或职位较低的； 下级的； 次要的； 附属的

Not surprisingly, web browsers display this type of text in a smaller sized font.

### Add Small Print

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<p><b>M and B Adventure Travel</b></p>

			<p>For more than 10 years, M and B Adventure Travel has helped customers fulfill their 
			dreams and conquer their fears. We specialize in one-of-a-kind vacation packages to the 
			most exciting destinations in the world. Let us help you with your hotel bookings, 
			helicopter tours, and shark-cage rentals, either onlie or in person.</p>

			<-- The web browser displays the text smaller than the regular text on the page.
			<small>Copyright 2011 M and B Adventure Travel</small>
		</body>
	</html>

## Insert a Comment
Comments can also be useful for highlighting important sections of HTML code, such as where the 
 
 * header
 * footer
 * navigation 

section on a page starts and ends.

	You can also place comments around HTML code to turn that code off. The browser does not interpret 
	HTML tags inside comments.

### Insert a Comment

Demo:

	<!DOCTYPE html>
	<html>
		<head>
			<title>M and B Adventure Travel</title>
		</head>
		<body>
			<h1>Machu Picchu</h1>
			
			<p>Located in the Peruvian Andes, the ancient Inca city of Machu Picchu was constructed in
			the 1400s at the height of the Inca Empire.</p>

			<!-- Add photo of Machu Picchu here-->
			<-- The comment does not appear on the page when viewed in a web browser.

			<p>It was abandoned less than 100 years later when the Inca empire collapsed under Spanish
			conquest. Today Machu Picchu is the most visited tourist attaction in Peru.
		</body>
	</html>


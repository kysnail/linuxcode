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


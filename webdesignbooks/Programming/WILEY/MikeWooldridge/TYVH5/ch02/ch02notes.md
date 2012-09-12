# Chapter 2: Creating Your First HTML5 Web page

## Understanding HTML5 Document Structure

### DOCTYPE Declaration

### HTML Tags

### Document Head

### Document Title

## Demo Page

	<!DOCTYPE html>
	
	<html>
		<head>
			<title>M and B Adventure Travel</title>
			<meta name="description" content="A business specializing in adventure travel">
			<link rel="stylesheet" type="text/css" href="styles.css">
		</head>

		<body>
			<header>
				<img src="mbadventure.jpg" alt="M and B Adventure Travel">
				<P>Extreme vacations are our specialty!</P>
			</header>


			<nav>
				<ul>
					<li><a href="index.html">Home</a></li>
					<li><a href="dest.html">Destinations</a></li>
					<li><a href="Lips.html">Travel Tips</a></li>
					<li><a href="contact.html">Contact Us</a></li>
				</ul>
			</nav>

			<p>For more than 10 years, M and B Adventure Travel has helped customers fulfill their
			dreams and conquer their fears. We specialize in one-of-a-kind vacation packages to the 
			most exciting destinations in the world. Let us help you with your hotel bookings, 
			helicopter tours, and shark-cage rentals, either online or in person.</p>
		</body>
	</html>

### Metadata

 * metadata - 元数据

`Metadata` means "data about data".

### Body

### Semantic Tags

	<header> - defining header content.
	<nav> - defining navigation
	<footer> - defining footer content

In previous versions of HTML, `section markup` was limited to tags such as `<div>`, which defined a section of HTML but did not tell you what the meaning of the section was.

## Start an HTML5 Document

	To save time, you can create a text file that includes these tags and use the file as a template each time
	you want to create a web page.

### Start an HTML5 Document

	<!DOCTYPE html>
	<html
	<head>
	<title>M and B Adventure Travel</title>
	</head>

#### TIPS

##### Does it matter if I type my HTML5 tag and attribute names in uppercase, lowercase, or mixed case?

	No. The HTML5 standard allows for different cases in your HTML text.

## Start an HTML5 Document

 * bulleted list - 项目符号列表

### Start an HTML5 Document

	<!DOCTYPE html>
	<html>
		<head>
		<title>M and B Adventure Travel</title>
		</head>
		<body>
			For more than 10 years, M and B Adventure Travel has helped customers fulfill their
			dreams and conquer their fears. We specialize in one-of-a-kind vacation packages to the 
			most exciting destinations in the world. Let us help you with your hotel bookings, 
			helicopter tours, and shark-cage rentals, either online or in person.
		</body>
	</html>

#### TIP

##### How can I open an HTML5 document from the Notepad text editor?

## Save an HTML5 Document

	When naming a web page, it is best not to use spaces and to keep characters limited to letters,
	numbers, hyphens (-), and underscores (_). 

### Save an HTML5 Document

#### TIPS

##### What is the difference between the .html and .htm extensions?
	
	The shorter .htm extension is left over from the early, pre-Windows days, when filenames chould have
	only three-character file extensions. Some Windows-based programs still default to the .htm
	extension. Today's computers can handle longer filenames and extensions, so the three-character limit
	is no longer an issue. Although web browsers and servers can read either extension, you probably
	want to opt for .html because it is more universally used.

- 

 * pre-Windows - 这个词不好解释，大概知道意思 -

-

	What is the Pre-Windows 2000 Compatible Access?
	-----------------------------------------------
	A backward compatibility group that allows read access on all users and groups in the domain.

	This information was verified with Windows 2000.

-

 * opt for - v.选择 (计算机)
 * universally - 普遍地； 一般地； 人人； 处处

##### What makes a good filename for a web page?
`keep the name simple` 除了便于记忆之外，对于搜索引擎也是友好的，这是自己以往没有想到过的。

	Filenames that contain words relevant to a page can help search engines correctly recognize your page.
	Search engines read filenames when processing web pages and can take those names into account when 
	categorizing the pages.

## View an HTML5 Page

	Opening an HTML5 page that you are simultaneously editing in a text editor is a useful way to 
	determine if the page appears correctly as you add content and tags. When you open a page from
	your computer in a browser, the file-system path leading to the page appears in the browser
	address field.

### View an HTML5 Page

#### TIPS

##### Does it matter what browser I use to view the pages I build?

 * set up - 建立； 准备； 安排； 引起
 * offline pages - 脱机页

##### What happens if I cannot view my page?

 * double-check - v.复核
 * proofread - vt.校正； 校对； 校勘

## Add Metadata

	What you insert in metadata tags can help search engines categorize your page.

Demo:

	<meta name="author" conent="Mike Wooldridge">

Meaning:

	You define metadata in the document header using the <meta> tag. The <meta> tag includes a name 
	attribute that determines what type of metadata you are adding with the tag. 
	You add metadata to the document header of your HTML5 page, inside the <head> and </head> tags.

### Add Metadata

可以看到 `metadata` 信息符合名值对的特征。

	<meta name="author" content = "kysnail">	<-- Add an author name
	<meta name="description" content="My reading notes.">    <-- Add a page description 
	<meta name="keywords" content="travel, airline, hotels, rental cars, jungle vacations, 
	hiking vacations, sport vacations">	 <-- Specify keywords
	<meta name="copyright" content="2012">     <-- Add a copyright

- 

 * comma - n.逗号
 * semicolon - n.分号

The metadata is now a part of the HTML document.

#### TIPS

##### How do I add the name of the program I used to design my page to the metadata information?

 * authoring program - 授权程序
 * authoring - n.著作
 * authoring language - 创作语言

-
	To specify an authoring program, type
	
		<meta name="generator" conent=" Program Name">

	Subsitute the name of your program for the next Program Name.

##### Who can view my metadata?

	The only way users can see your metadata information is if they view the HTML code for the page.


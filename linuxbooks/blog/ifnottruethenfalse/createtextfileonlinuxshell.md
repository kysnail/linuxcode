# Linux: Create Text File on Linux Shell / Command Line
This is a very tipical case, the need to create a temp file on the command line quickly. Opening editor, writing content, save file and quit editor is not the fastest possible way. A faster way is to use the `cat command` with the name of the file and write contents of the file and give the end-of-file character (Ctrl+D).

This is guide, **HowTo create (or append to) text file without text editor on Linux shell / command line**.

## Create Text File Without Text Editor on Command Line

	# create file
	$ cat > /tmp/tmp.txt
	some content
	more content
	and even more content		=> 这里按下 ctrl+d 完成文件的编辑工作，提示文件结束。

	# view file content
	$ cat /tmp/tmp.txt
	some content
	more content
	and even more content

## Append to Temporary File Without Editor On Command Line

	# append to file
	[kangyushi@fedora16 Downloads]$ cat >> /tmp/tmp.txt
	append content
	append more content
	# => 这里没有按下 ctrl+d 给文件一个结束符，所以下面显示内容的操作也不会换行。
	# view file content
	append even more content[kangyushi@fedora16 Downloads]$ cat /tmp/tmp.txt
	some content
	more content
	and even more content
	append content
	append more content
	append even more content[kangyushi@fedora16 Downloads]$


**Refs**

 * [Linux: Create Text File on Linux Shell / Command Line](http://www.if-not-true-then-false.com/2010/linux-tip-create-append-temporary-file-without-editor/)

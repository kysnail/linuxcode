##Q:
 
	在form上有一个RichTextBox,多行,程序会不断在末尾添加一行数据,当出现滚动条的时候,默认滚动条一直在上方,如何使其一直在下方。
 
##A:
 
	在RichTextBox中是定位滚动条，是通过两个步骤完成的。
	首先，定位RechTextBox中需要滚动到的内容位置。(使用Select方法)
	然后，使用ScrollToCaret()方法将滚动条移到这个位置。
	范例代码如下:
	richTextBox.Select(richTextBox.Text.Length , this.richTextBox1.Text.Length );
	//选择RichTextBox内容的最后一个字节。
	this.richTextBox1.ScrollToCaret();
	//将RichTextBox的滚动条移动到上一步所设定的位置。
  
## Code 1

	richTextBox.Select(richTextBox.Text.Length, 0);
	this.richTextBox1.ScrollToCaret();

## Code 2

	this.SelectionStart = text1.Text.Length;
	text1.ScrollToCaret();

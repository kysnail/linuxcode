## `#if defined` 作用
在读s3c2440a的test程序，其中option.h文件中有段语句为：

	#define LCD_N35 
	//#define LCD_L80 
	//#define LCD_T35 
	//#define LCD_A70 
	//#define LCD_VGA1024768

	//--end of by Customer--

	#if defined(LCD_N35) + defined(LCD_L80) + defined(LCD_T35) + defined(LCD_A70) + defined(LCD_VGA1024768) != 1 
	#error Must define only one LCD type 
	#endif

其中的

	#if defined(LCD_N35) + defined(LCD_L80) + defined(LCD_T35) + defined(LCD_A70) + defined(LCD_VGA1024768) != 1 

不明白什么意思，查找后得知：

若是defined LCD_N35 、 defined LCD_L80  、defined LCD_T35 、 defined LCD_A70 、defined LCD_VGA1024768中有一个定义，则执行#endif后面的语句。

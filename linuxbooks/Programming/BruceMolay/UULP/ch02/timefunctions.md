## time functions
Linux 中关于 time 的函数非常多，原因在于，系统将日期表示为数值的形式，那么在接下来的表达样式转换过程中，必然需要提供更多种的选择，来满足开发人员的需求。在 IBM 的开发者网络上有比较好的描述。

现将常用的 time 转换函数列举一下：

 * `ctime()`
 * `ctime_r()`
 * `asctime()`
 * `asctime_r()`
 * `gmtime()`
 * `gmtime_r()`
 * `localtime()`
 * `localtime_r()`
 * `time()`
 * `mktime()`
 * `setlocale()`
 * `strftime()`
 * `strptime()`
 * `wcsptime()`

尚未列举完。要想参看更详细的，指向如下链接：

 * [time()](http://publib.boulder.ibm.com/infocenter/iadthelp/v6r0/index.jsp?topic=/com.ibm.etools.iseries.langref.doc/rzan5mst93.htm)

此文档还有一点比较好，就是每个函数必定都有相应的代码演示。

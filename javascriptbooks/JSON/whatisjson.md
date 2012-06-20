## JSON是什么？它能带来什么？

有一种叫做JSON (JavaScript Object Notation) 的轻量级数据交换格式能够替代XML的工作.

### 优点：
1. 数据格式比较简单, 易于读写, 格式都是压缩的, 占用带宽小

2. 易于解析这种语言, 客户端JavaScript可以简单的通过eval()进行JSON数据的读取

3. 支持多种语言, 包括ActionScript, C, C#, ColdFusion, Java, JavaScript, Perl, PHP, Python, Ruby等语言服务器端语言, 便于服务器端的解析

4. 在PHP世界, 已经有PHP-JSON和JSON-PHP出现了, 便于PHP序列化后的程序直接调用. PHP服务器端的对象、数组等能够直接生JSON格式, 便于客户端的访问提取.   另外PHP的PEAR类已经提出了支持 (http://pear.php.net/pepr/pepr-proposal-show.php?id=198)

5. 因为JSON格式能够直接为服务器端代码使用, 大大简化了服务器端和客户端的代码开发量, 但是完成的任务不变, 且易于维护

### 缺点：
1. 没有XML格式这么推广的深入人心和使用广泛, 没有XML那么通用性；

2. JSON格式目前在Web Service中推广还属于初级阶段。

PS: 据说Google的Ajax是使用 JSON+模板 做的啊

### JSON与XML的比较
将从多个方面进行比较

#### 可读性
JSON和XML的可读性可谓不相上下，一边是简易的语法，一边是规范的标签形式，很难分出胜负。

#### 可扩展性
XML天生有很好的扩展性，JSON当然也有，没有什么是XML能扩展，JSON不能的。不过 JSON在Javascript主场作战，可以存储Javascript复合对象，有着xml不可比拟的优势。

#### 编码难度
XML有丰富的编码工具，比如Dom4j、JDom等，JSON也有json.org提供的工具。无工具的情况下，相信熟练的开发人员一样能很快的写出想要的xml文档和JSON字符串，不过，xml文档要多很多结构上的字符。

#### 解码难度
XML的解析方式有两种：

##### 一是通过文档模型解析，也就是通过父标签索引出一组标记。
例如：xmlData.getElementsByTagName("tagName")，但是这样是要在预先知道文档结构的情况下使用，无法进行通用的封装。

##### 另外一种方法是遍历节点（document 以及 childNodes）。
这个可以通过递归来实现，不过解析出来的数据仍旧是形式各异，往往也不能满足预先的要求。凡是这样可扩展的结构数据解析起来一定都很困难。

JSON也同样如此。如果预先知道JSON结构的情况下，使用JSON进行数据传递简直是太美妙了，可以写出很实用美观可读性强的代码。如果你是纯粹的前台开发人员，一定会非常喜欢JSON。但是如果你是一个应用开发人员，就不是那么喜欢了，毕竟 xml才是真正的结构化标记语言，用于进行数据传递。

而如果不知道JSON的结构而去解析JSON的话，那简直是噩梦。费时费力不说，代码也会变得冗余拖沓，得到的结果也不尽人意。但是这样也不影响众多前台开发人员选择JSON。因为json.js中的toJSONString()就可以看到 JSON的字符串结构。当然不是使用这个字符串，这样仍旧是噩梦。常用JSON的人看到这个字符串之后，就对JSON的结构很明了了，就更容易的操作 JSON。

以上是在Javascript中仅对于数据传递的xml与JSON的解析。在 Javascript地盘内，JSON毕竟是主场作战，其优势当然要远远优越于xml。如果JSON中存储Javascript复合对象，而且不知道其结构的话，我相信很多程序员也一样是哭着解析JSON的。

----

### 实例比较
XML和JSON都使用结构化方法来标记数据，下面来做一个简单的比较。

#### 用XML表示中国部分省市数据如下：

	<?xml version="1.0" encoding="utf-8"?>
	<country>
		<name>中国</name>
		<province>
			<name>黑龙江</name>
			<citys>
				<city>哈尔滨</city>
				<city>大庆</city>
			</citys>
		</province>
		<province>
			<name>广东</name>
			<citys>
				<city>广州</city>
				<city>深圳</city>
				<city>珠海</city>
			</citys>
		</province>
		<province>
			<name>台湾</name>
			<citys>
				<city>台北</city>
				<city>高雄</city>
			</citys>
		</province>
		<province>
			<name>新疆</name>
			<citys>
				<city>乌鲁木齐</city>
			</citys>
		</province>
	</country>

#### 用 JSON 表示如下：

	{
		name:"中国",
		province:[
			{
				name:"黑龙江",
				citys:{
					city:["哈尔滨", "大庆"]
				}
			},
			{
				name:"广东",
				citys:{
					city:["广州", "深圳", "珠海"]
				}
			},
			{
				name:"台湾",
				citys:{
					city:["台北", "高雄"]
				}
			},
			{
				name:"新疆",
				citys:{
					city:["乌鲁木齐"]
				}
			}
		]
	}

编码的可读性，xml有明显的优势，毕竟人类的语言更贴近这样的说明结构。json读起来更像一个数据块，读起来就比较费解了。不过，我们读起来费解的语言，恰恰是适合机器阅读，所以通过json的索引.province[0].name就能够读取“黑龙江”这个值。

编码的手写难度来说，xml还是舒服一些，好读当然就好写。不过写出来的字符JSON就明显少很多。去掉空白制表以及换行的话，JSON就是密密麻麻的有用数据，而xml却包含很多重复的标记字符。


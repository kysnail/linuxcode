# Chapter 1 - Ruby on Rails 简介
Ruby on Rails 究竟是什么？

    简短而专业的答案为 Ruby on Rails 是用 Ruby 编写的全栈 Web 应用框架。

先了解一些术语

**Web 应用程序**

    Web 应用程序是在网路上使用 Web 浏览器进行访问的软件应用程序。

**框架**

    框架被视为 Web 应用程序的基础。它考虑到了许多底层的细节，这些细节会变成重复的、枯燥的代码，这样就允许开发人员
    专注于构建应用程序的功能。

    框架为开发者提供在每个 Web 应用程序中都会用到的实现通用功能所需的类，包括：
    ● 数据库提取（不管是 MySQL、Oracle、DB2 还是其他的数据库，都能确保数据库的查询工作）；
    ● 模板（在整个应用程序中重用现有的代码）；
    ● 管理用户会话；
    ● 产生“清洁”的 URL。

    框架也定义了应用的体系结构，这对我们当中常对文件究竟该存在哪里好有疑问的那些人来讲是非常有用的。

    在某种意义上，框架好似一个在开始就已经设计好了的应用。这种结构的枯燥代码部分已经写好，现在是完成的时候了。

**全栈**

    全栈指 Rails 框架提供的功能范围。框架的类型很多，一些在服务器端提供丰富的功能，但在客户端却使你手足无措。
    而另一些框架过于注重在客户机上提高用户体验，却不扩展服务器端的商务逻辑和数据库交互。

**Ruby**

    Ruby 使得编程更灵活并且直观，运用它，我们可以编写人机都可读的代码。Matsumoto 预测 Ruby 将会成为需要少量
    智力投入的编程语言，这就是 Ruby 程序员往往是快乐程序员的原因。


## 1.1 历史
**David Heinemeier Hansson**

 * [Basecamp](http://www.basecamphq.com/)
 * [Backpack](http://www.backpackit.com/)
 * [Ta-da List](http://www.tadalist.com/)
 * [Campfile](http://www.campfirenow.com/)
 * [Writeboard](http://www.writeboard.com/)

上面的这些都是 37Signals 公司使用 Rails 编写的主机应用程序。

 * [37Signals](http://www.37signals.com/)

37Signals 公司的链接。

 * [Rails 开发库](http://dev.rubyonrails.org/)

## 1.2 开发原则
Rails 支持的几个软件原则使得它能够由于其他的 Web 开发框架。这些原则包括：

 * 惯例优先；
 * 不重复自我；
 * 灵活的开发。

有了这些原则，Ruby on Rails 成为一个切实节省开发者时间和工作量的框架。

### 1.2.1 惯例优先‘

    惯例优先是指 Rails 为构建典型 Web 应用设定了大量的默认配置。

### 1.2.2 不重复自我

    Rails 支持 DRY （不重复自我）编程原则。在改变基于 DRY 原则应用程序的行为时，没有必要在多个权威位置
    修改应用程序的代码。

### 1.2.3 灵活的开发

    通常更多的传统软件开发（如迭代开发和瀑布模型），为了达到应用的目标和需求而使用已有的方法，拟定一个长期
    且相对静态的计划。这些开发模型常常自底向上处理应用程序（即首先处理数据）。

    对比看来，灵活的开发方法使用一种自适应的方法。小的团队（较典型的由不到 10 个开发人员组成）重复地完成项目
    的小单元。在开始重复之前，团队重新评估将要构建应用程序的优先权（这些优先权可能在以前的重复过程中已经发生
    变化，所以可能需要调整）。灵活开发也需要自顶向下构建应用程序，从设计开始（这样和在纸上拟定其接口一样简单）。



 *
 *

 * []()
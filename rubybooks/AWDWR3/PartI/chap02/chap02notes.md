# Chapter - The Architechture of Rails Applications

## 2.2 Active Record: Rails Model Support
关系模型与 OO 模型协调的两种方式：

    以数据库为中心组织应用程序；
    以应用程序为中心组织数据库；

### Object-Relational Mapping
ORM 层将

 * 数据库表映射到类
 * 记录映射到对象
 * 字段映射到对象的属性
 * 类方法用于执行表级别的操作
 * 实例方法则用于执行针对单条记录的操作

在一个典型的 ORM 库中，你可以提供配置数据来指定数据库端与应用程序端之间的映射关系。使用这些 ORM 工具的程序员常常会发现：他们不得不忙于创建和维护一大堆的 XML 配置文件。

### Active Record
**Active Record** 是 Rails 所采用的 ORM 层。它完全遵循标准的 ORM 模型：

    表映射到对象
    记录映射到对象
    字段映射到对象属性

与其他大部分 ORM 库的不同之处在于它的配置方式：

    它根据人们常用的命名管理提供了很有意义的默认配置，因此，将需要开发者编写的配置量降到了最低。

## Action Pack: The View and Controller
在 MVC 架构中，视图与控制器是密不可分的：

    控制器为视图提供数据，然后又接收来自页面的时间——这页面正是由视图生成的。

正因为有如此密切的交互，在 Rails 中对视图和控制器的支持被捆绑在同一个组件中，那就是 Action Pack 。

### View Support
在 Rails 中，视图负责创建将要在浏览器上显示的页面——可能是整个页面，也可能是其中的一部分。在最简单的情况下，视图就是一堆 HTML 代码，用于显示固定的文本。不过，一般说来，你都需要再视图中加入一些动态内容——这些动态内容通常是控制器中的 action 方法制造的。

在 Rails 中，动态内容是由模板生成的。模板的形式有三种：

 * ERb (Embedded Ruby) 
 * xml.builder 模板
 * RJS 视图


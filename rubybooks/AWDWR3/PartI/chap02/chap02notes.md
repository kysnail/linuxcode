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

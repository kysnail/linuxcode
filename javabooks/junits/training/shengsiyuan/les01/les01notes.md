## Unit Test Lesson 1

    单元测试由开发人员来写！！

## [JUnit](http://www.junit.org/)

 * JUnit 3.8.X 基于反射

    3.8 版本的学习重点是如何利用其命名约定去设计我们的单元测试方法。

 * JUnit 4.X  基于 Annotation

    4.0 还要学习如何使用 Annotation 标识我们的测试用例。

### 本课程 使 用的版本

 * JUnit 3.8.1
 * JUnit 4.4

### JUnit 简介
JUnit 本身是一个非常小巧的框架，类和方法都比较少，但是功能很强大。
几乎所有的 Java IDE 都默认支持。所以可以直接使用下述方法引入 JUnit 包：

    项目上右键 -> Build Path -> Configure Build Path -> Libraries -> Add Library


项目文件管理上，需要将测试源码与程序源码分开存放。也就是再单独创建一个 src 文件夹：

    New -> Source Folder -> test

命名约定中规定，你需要创建于 程序源码相同的 包结构，这样方便程序识别。

### 最佳实践

#### 使用 JUnit 的最佳实践：

##### 1. 新建一个名为 test 的 source folder，用于存放测试类源代码。

##### 2. 目标类与测试类应该位于同一个包下面。
这样测试类中就不必导入源代码所在的包，因为他们位于同一个包下面。

    这样我不用导入任何包，因为 Package 相同，另外查看 
    Project -> Properties -> Properties for junit -> Default output folder
    可以发现
    junit/src
    junit/test
    两者的输出目录相同，从而使得，两者可以不需要引入包所在地。

##### 3. 测试类的命名规则：
假如目标类是 Calculator，那么测试类应该命名为 TestCalculator 或者是 CalculatorTest 。

#### JUnit 的口号：

    Keep the bar green to keep the code clean.

#### JUnit：单元测试不是为了证明您是对的，而是为了证明您没有错误。

#### 测试用例（TestCase）是单元测试的一个很重要的方面。

#### 单元测试主要是用来判断程序的执行结果与自己期望的结果是否一致。



## Unit Test Lesson 2

### 在 JUnit 3.8 中，测试方法需要满足如下原则：
 
 * 1. 修饰符 public
 * 2. 返回值 void
 * 3. 无方法参数
 * 4. 方法名称必须以 test 开头
 * 5. 各个测试之间必须完全独立，没有任何依赖关系


### TestCase 之间一定要保持完全的独立性，不允许出现任何的依赖关系。

### 我们不能依赖于测试方法的执行顺序。 

### DRY - Don't Repeat Yourself

### 关于 setUp & tearDown 方法的执行顺序
在每个测试用例执行之前，执行 `setUp` ，在每个测试用例执行之后，执行 `tearDown` 。

    setUp
    testAdd
    tearDown

## src

 * 1. 演示了上述测试原则；
 * 2. 重构 1 中的演示代码，使用 setUp/tearDown 方法解决代码重复问题，这里需要注意，重写方法时，可以将 protected -> public 升级。

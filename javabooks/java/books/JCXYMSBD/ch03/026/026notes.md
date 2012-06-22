## 简述接口和抽象类的区别
`接口` 和 `抽象类` 指的都是不能具体描述一个对象的类型，包含了一些不完整的信息，需要实现类进行具体的实现。

### 抽象类
在面向对象的概念中，所有的对象都是通过类来描绘的，但是并不是所有的类都是用来描绘对象的，如果一个类中没有包含足够的信息来描绘一个具体的对象，这样的类就是 `抽象类`。

   具体地说，也就是包含抽象（abstract）方法的类，就是抽象类。

抽象类往往用来表示在对问题领域进行分析、设计中得出的抽象概念，一些问题是可以清楚描述的，而某些是未知的。

   例如：
   要描述 "水果" ，它就是一个抽象概念，它有质量、体积等一些共性，但又缺乏特性（水果都可以吃，但是它们的口感
   却不同），拿不出唯一一种能代表水果的东西（因为苹果、橘子都不能代表水果），此时就可以用抽象类来描述它，但是
   抽象类是不能够实例化的。

### 接口
接口则比抽象类更进了一步，它所有的东西都是抽象的，也就是所有的方法都是抽象方法，没有任何的实现。它也可以包含静态的变量，只不过这些变量的值是不能修改的。

   接口成员变量必须是 public static final

接口和抽象类都可以用于进行类型的强制转换。接口一般用来表示实现类具有某种特性，

   例如：
   可以比较大小、可迭代等。

### 示例代码
关于水果的抽象类和接口的示例代码：

   /**
    * 水果类定义了所有水果的共性，比如这里的重量、体积味道等。而水果间的差异，
    * 比如香蕉可以剥皮，橘子需要分瓣等则需要通过接口定义。剥皮、分瓣的特性可以
    * 认为是水果子集的共性。
    */
   abstract class Fruit {           // 水果类
      double weight;                // 重量
      double volume;                // 体积
      abstract String getTaste();   // 味道
   }

   /**
    * 可包装接口
    * 从感性上可以知道，所有的水果都可以进行包装处理，但"包装"这个动作并不是水
    * 果的特性，所以这里定义成接口。也就相当于使用了多重继承，又单独继承了一个
    * 可以包装的类。
    */
   interface Packable {
      void pack();                  
   }

   /**
    * 可分瓣接口
    * 水果"可分瓣"这个特性可以划分出一个水果的子集，比如橘子，柚子等都属于这个
    * "可分瓣"的子集中。
    *
    * 与上面可包装接口的区别在于，可分瓣也属于水果的一个特性吧。
    */
   interface Dividable {
      void dividable(); 
   }

   /**
    * 苹果继承自水果类，实现了可包装接口。
    */
   class Apple extends Fruit implements Packable {
      String getTaste() {                 // 实现 getTaste() 方法
         return "甜";
      }

      public void pack() {                // 实现包装方法
         System.out.println("包装苹果！");
      }
   }

   /**
    * 橘子继承自水果类，实现了可包装接口、可分瓣接口。
    */
   class Orange extends Fruit implements Packable, Dividable {

      String getTaste() {                       // 实现 getTaste() 方法
         return "酸";
      }

      public void pack() {                      // 实现包装方法
         System.out.println("包装橙子！");
      }

      public void dividable() {                 // 实现分瓣方法
         System.out.println("把橙子分瓣！");
      }
   }

   public class InterfaceAndAbstract {

      public static void main(String args[]) {
         Apple apple = new Apple();
         Orange orange = new Orange();

         System.out.println("Apple taste " + apple.getTaste());
         System.out.println("Orange taste " + orange.getTaste());

         apple.pack();
         orange.pack();
         orange.dividable();
      }
   }

   /*
    * Output:
    *
    * Apple taste 甜
    * Orange taste 酸
    * 包装苹果！
    * 包装橙子！
    * 把橙子分瓣！
    *
    */

`抽象类`，通过 `abstract class` 进行定义，它也是一种类，只不过它不可以实例化，例如上例中的 Fruit 类。接口通过 `interface` 进行定义，它不能被直接实例化，实现类通过 `implements` 关键字来声明实现接口，例如，以上代码中的 `Packable` 和 `Dividable` 接口，分别代表水果可包装和可分辨的性质。



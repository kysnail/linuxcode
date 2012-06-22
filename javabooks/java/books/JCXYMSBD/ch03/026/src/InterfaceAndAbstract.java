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

   public static void main() {
      Apple apple = new Apple();
      Orange orange = new Orange();

      System.out.println("Apple taste " + apple.getTaste());
      System.out.println("Orange taste " + orange.getTaste());

      apple.pack();
      orange.pack();
      orange.dividable();
   }
}

/**
 * 尝试错误的写法。
 */
public class P01Outer03 {
    
    class Inner {
        private String text = "In the Inner class.";

        public String echo() { return text; }
    }

    public Inner getInnerClass() {
        return new Inner();
    }

    public void test() {
        // 这种写法没有问题。
        Inner min = new Inner();
        System.out.println(min.echo());
    }

    public static void main(String[] args) {
        P01Outer03 p = new P01Outer03();
        P01Outer03.Inner in = p.getInnerClass();
        System.out.println(in.echo());
        // 改为用实例变量调用的方式，应该不会出错了。
        p.test();
    }
}

/*---------------------------------------------------------------
$ javac P01Outer03.java
P01Outer03.java:2: warning: unmappable character for encoding Cp1252
 * ▒?试错误的写法。
     ^
P01Outer03.java:17: warning: unmappable character for encoding Cp1252
        // 这▒?写法没有问题。
                ^
P01Outer03.java:26: warning: unmappable character for encoding Cp1252
        // 改为用实例▒?▒▒?调用的方▒?，应该▒?会出错了。
                           ^
P01Outer03.java:26: warning: unmappable character for encoding Cp1252
        // 改为用实例▒?▒▒?调用的方▒?，应该▒?会出错了。
                               ^
P01Outer03.java:26: warning: unmappable character for encoding Cp1252
        // 改为用实例▒?▒▒?调用的方▒?，应该▒?会出错了。
                                              ^
P01Outer03.java:26: warning: unmappable character for encoding Cp1252
        // 改为用实例▒?▒▒?调用的方▒?，应该▒?会出错了。
                                                          ^
6 warnings
 
---------------------------------------------------------------*/

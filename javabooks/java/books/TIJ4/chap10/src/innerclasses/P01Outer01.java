/**
 * 尝试错误的写法。
 */
public class P01Outer01 {
    
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
        // 但这里的调用方法有问题，因为 test() 并不是静态方法。
        test();
        P01Outer01 p = new P01Outer01();
        P01Outer01.Inner in = p.getInnerClass();
        System.out.println(in.echo());
    }
}

/*---------------------------------------------------------------
$ javac P01Outer01.java
P01Outer01.java:2: warning: unmappable character for encoding Cp1252
 * ▒?试错误的写法。
     ^
P01Outer01.java:17: warning: unmappable character for encoding Cp1252
        // 这▒?写法没有问题。
                ^
P01Outer01.java:23: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                  ^
P01Outer01.java:23: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                       ^
P01Outer01.java:23: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                           ^
P01Outer01.java:24: non-static method test() cannot be referenced from a static context
        test();
        ^
1 error
5 warnings
 
---------------------------------------------------------------*/

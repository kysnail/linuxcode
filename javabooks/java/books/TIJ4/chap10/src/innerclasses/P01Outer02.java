/**
 * 尝试错误的写法。
 */
public class P01Outer02 {
    
    class Inner {
        private String text = "In the Inner class.";

        public String echo() { return text; }
    }

    public Inner getInnerClass() {
        return new Inner();
    }

    // 尝试将 test() 方法设为静态型，仍然会出错。
    public static void test() {
        // 这种写法没有问题。
        Inner min = new Inner();
        System.out.println(min.echo());
    }

    public static void main(String[] args) {
        // 但这里的调用方法有问题，因为 test() 并不是静态方法。
        test();
        P01Outer02 p = new P01Outer02();
        P01Outer02.Inner in = p.getInnerClass();
        System.out.println(in.echo());
    }
}

/*---------------------------------------------------------------
$ javac P01Outer02.java
P01Outer02.java:2: warning: unmappable character for encoding Cp1252
 * ▒?试错误的写法。
     ^
P01Outer02.java:16: warning: unmappable character for encoding Cp1252
    // ▒?试将 test() 方法设为▒?▒▒?型，▒?然会出错。
         ^
P01Outer02.java:16: warning: unmappable character for encoding Cp1252
    // ▒?试将 test() 方法设为▒?▒▒?型，▒?然会出错。
                                     ^
P01Outer02.java:16: warning: unmappable character for encoding Cp1252
    // ▒?试将 test() 方法设为▒?▒▒?型，▒?然会出错。
                                         ^
P01Outer02.java:16: warning: unmappable character for encoding Cp1252
    // ▒?试将 test() 方法设为▒?▒▒?型，▒?然会出错。
                                                  ^
P01Outer02.java:18: warning: unmappable character for encoding Cp1252
        // 这▒?写法没有问题。
                ^
P01Outer02.java:24: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                  ^
P01Outer02.java:24: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                       ^
P01Outer02.java:24: warning: unmappable character for encoding Cp1252
        // 但这里的调用方法有问题，因为 test() 并▒?是▒?▒▒?方法。
                                                                           ^
P01Outer02.java:19: non-static variable this cannot be referenced from a static context
        Inner min = new Inner();
                    ^
1 error
9 warnings

---------------------------------------------------------------*/

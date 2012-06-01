/**
 * 尝试错误的写法。
 */
public class P01Outer {
    
    class Inner {
        private String text = "In the Inner class.";

        public String echo() { return text; }
    }

    public Inner getInnerClass() {
        return new Inner();
    }

    public static void main(String[] args) {
        // 这种写法会出错，所以引入 getInnerClass() 方法。
        Inner min = new Inner();
        System.out.println(min.echo());
        P01Outer p = new P01Outer();
        P01Outer.Inner in = p.getInnerClass();
        System.out.println(in.echo());
    }
}

/*---------------------------------------------------------------
$ javac P01Outer.java
P01Outer.java:14: non-static variable this cannot be referenced from a static context
        Inner min = new Inner();
                            ^
                            1 error
---------------------------------------------------------------*/

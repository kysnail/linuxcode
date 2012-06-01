//: innerclasses/Parcel2.java
// Returning a reference to an inner class.

public class Parcel2 {
    
    class Contents {
        private int i = 11;
        public int value() { return i; }
    }

    class Destination {
        private String label;
        Destination(String whereTo) {
            label = whereTo;
        }
        String readLabel() { return label; }
    }

    // 这里是内部类更典型的用法
    // 外部类的 to 方法返回一个内部类的引用。
    public Destination to(String s) {
        return new Destination(s);
    }

    public Contents contents () {
        return new Contents();
    }

    public void ship(Stirng dest) {
        // 这里不再需要像 Parcel1.java 中那样使用 new Contents() 创建了。
        Contents c = contents();
        Destination d = to(dest);
        System.out.println(d.readLabel());
    }

    public static void main(String[] args) {
        Parcel2 p = new Parcel2();
        p.ship("Tasmania");

        Parcel2 q = new Parcel2();
        // Defining references to inner classes:
        Parcel2.Contents c = q.contents();
        Parcel2.Destination d = q.to("Borneo");
    }
}

/*----------------------------------
output:
Tasmania
----------------------------------*///:~


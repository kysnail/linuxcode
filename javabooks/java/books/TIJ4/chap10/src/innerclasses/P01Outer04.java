// innerclasses/P01Outer04.java
// TIJ4 Chapter Innerclasses, Exercise 1, page 347
/*
 * Write a class named P01Outer04 that contains an inner class named Inner.
 * Add a method to P01Outer04 that returns an object of type Inner. In main(),
 * create and initialize a reference to an Inner.
 */
public class P01Outer04 {
    
    P01Outer04() {
        System.out.println("P01Outer04()");
    }
    
    class Inner {
        Inner() { 
            System.out.println("Inner()");
        }   
    }

    Inner makeInner() {
        return new Inner();
    }

    public static void main(String[] args) {
        P01Outer04 p = new P01Outer04();
        Inner in = p.makeInner();
    }
}

/*---------------------------------------------------------------
$ java P01Outer04
P01Outer04()
Inner()
---------------------------------------------------------------*/

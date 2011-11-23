import java.util.Collection;
import java.util.ArrayList;


public class ContainsAllMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";

        Collection<String>List1 = new ArrayList<String>();
        List1.add(java);
        List1.add(csharp);
        List1.add(lisp);
        System.out.println("List1 中的元素为 -> Java C# Lisp");

        Collection<String>List2 = new ArrayList<String>();
        List2.add(java);
        List2.add(lisp);
        List2.add(cpp);
        System.out.println("List1 中的元素为 -> Java Lisp C++");

        boolean isContain = List1.containsAll(List2);
        System.out.println("集合对象 List1 中是否存在集合对象 List2 中的所有对象？ Answer = " + isContain);
    }
}

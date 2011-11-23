import java.util.Collection;
import java.util.ArrayList;
import java.util.Iterator;

public class RetainAllMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";

        Collection<String> List1 = new ArrayList<String>();
        List1.add(java);
        List1.add(csharp);
        List1.add(lisp);
        System.out.println("List1 中的元素为 -> Java C# Lisp");
        Collection<String> List2 = new ArrayList<String>();
        List2.add(lisp);
        List2.add(cpp);
        System.out.println("List2 中的元素为 -> Lisp C++");

        // 保留 List1 中同时存在于 List2 中的数据
        boolean isContain = List1.retainAll(List2);
        System.out.println("集合 List1 和集合 List2 是否有交集？ Answer = " + isContain);

        Iterator<String> it = List1.iterator();
        System.out.print("执行 retainAll 方法后，List1 中的元素为 ");
        while (it.hasNext()) {
            String str = it.next();
            System.out.println(str);
        }
    }
}

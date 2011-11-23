import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class IndexOfAndLastIndexOfMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";
        String haskell = "Haskell";

        List<String> list = new ArrayList<String>();
        list.add(java);
        list.add(lisp);
        list.add(csharp);
        list.add(lisp);
        list.add(cpp);
        list.add(lisp);
        list.add(haskell);
        list.add(lisp);

        Iterator<String> it = list.iterator();
        System.out.println("List 集合中的元素为： ");
        while (it.hasNext()) {
            System.out.print(" " + it.next());
        }

        System.out.println("\n");
        System.out.println("第一次出现 Lisp 的索引位置： " + list.indexOf(lisp));
        System.out.println("最后一次出现 Lisp 的索引位置： " + list.lastIndexOf(lisp));
    }
}

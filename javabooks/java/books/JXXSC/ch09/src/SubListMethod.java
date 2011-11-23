import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class SubListMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";
        String haskell = "Haskell";

        List<String> list = new ArrayList<String>();
        list.add(java);
        list.add(csharp);
        list.add(lisp);
        list.add(cpp);
        list.add(haskell);

        Iterator<String> it = list.iterator();
        System.out.println("list 集合中的元素为： ");
        while (it.hasNext()) {
            System.out.println(" " + it.next() + " ");
        }

        list = list.subList(2, 4);
        System.out.println("截取后的 list 集合中元素为： ");
        // 这里不使用迭代器完成遍历，而使用 List 的列表性质，直接寻址查找。
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }
    }
}

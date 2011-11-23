import java.util.Collection;
import java.util.ArrayList;
import java.util.Iterator;

public class RemoveAllMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";

        Collection<String> List1 = new ArrayList<String>();
        List1.add(java);
        List1.add(lisp);
        List1.add(csharp);
        List1.add(cpp);

        Collection<String> List2 = new ArrayList<String>();
        List2.add(java);
        List2.add(csharp);
        List2.add(cpp);

        // 从 List1 中移除 List2 中包含的元素
        boolean isContain = List1.removeAll(List2);
        System.out.println("List1 中是否包含有 List2 中的元素？ Answer = " + isContain); 

        Iterator<String> it = List1.iterator();
        System.out.print("删除 List2 中重复的元素后，List1 中含有的元素 ");
        while (it.hasNext()) {
            String str = it.next();
            System.out.println(str);
        }

        System.out.println("removeAll 方法类似于集合运算的 【集合A - 集合B】");
    }
}

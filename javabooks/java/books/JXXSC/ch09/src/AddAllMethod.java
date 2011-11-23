import java.util.Collection;
import java.util.ArrayList;
import java.util.Iterator;

public class AddAllMethod {

    public static void main(String[] args) {
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";

        // 由于 Collection 是接口，不能对其实例化，而 ArrayList 类是 Collection 接口的间接实现类，所以通过 ArrayList 类实例化。
        Collection<String> List1 = new ArrayList<String>();
        List1.add(java);
        List1.add(lisp);
        List1.add(csharp);

        Collection<String> List2 = new ArrayList<String>();
        // 通过使用 addAll() 方法添加指定集合中的所有对象到该集合中
        List2.addAll(List1);
        List2.add(cpp);

        // 通过 iterator() 方法序列化集合中的所有对象
        Iterator<String> it = List2.iterator();
        while (it.hasNext()) {
            String str = it.next().toString();
            System.out.println(str);
        }
    }
}

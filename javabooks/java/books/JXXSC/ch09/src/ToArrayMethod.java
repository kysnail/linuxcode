import java.util.Collection;
import java.util.ArrayList;

public class ToArrayMethod {

    public static void main(String[] args) {
        // 定义 字符串对象
        String java = "Java";
        String csharp = "C#";
        String lisp = "Lisp";
        String cpp = "C++";

        Collection<String> List1 = new ArrayList<String>();
        List1.add(java);
        List1.add(csharp);
        List1.add(lisp);
        List1.add(cpp);

        // 这里需要使用 Object 数组，以防止类型错误。
        Object[] obj = List1.toArray();
        System.out.println("List1 集合中的元素有 ");
        for (int i = 0; i != obj.length; i++) {
            System.out.println(obj[i]);
        }
    }
}

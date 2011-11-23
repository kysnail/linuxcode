    import java.util.List;
    import java.util.LinkedList;
    import java.util.Iterator;
    
    public class AddAndSetMethod {
    
    	public static void main(String[] args) {
    		// 定义 字符串对象
    		String java = "Java";
    		String csharp = "C#";
    		String lisp = "Lisp";
    		String cpp = "C++";
    		String haskell = "Haskell";
    		String erlang = "Erlang";
    		
    		List<String> List1 = new LinkedList<String>();
    		List1.add(java);
    		List1.add(lisp);
    		List1.add(cpp);
    		Iterator<String> it = List1.iterator();
    		System.out.println("集合 List1 中的对象为： ");
    		while (it.hasNext()) {
    			System.out.print(" " + it.next() + " ");
    		}
    		
    		System.out.println("修改集合 List1 中的对象： ");
    		List1.set(1, haskell);
    		List1.add(2, erlang);
    		
    		it = List1.iterator();
    		while (it.hasNext()) {
    			System.out.print(" " + it.next() + " ");
    		}
        }   

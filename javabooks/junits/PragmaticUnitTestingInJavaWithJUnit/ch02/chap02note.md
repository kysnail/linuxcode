## Chapter 2 - Your First Unit Tests
一个单元测试是程序员编写的一段代码，用于执行另一段代码并确定那段代码的行为是否和程序员的期望一致。

为了验证代码的行为是否和你的期望一致，你需要使用一些 **assertion**(断言)，它是一个简单的方法调用，用户判断某个语句是否为真。

### 2.1 Planning Tests
下面是一个简单的例子，它是一个独立静态方法，用于查找 list 中的最大值：

    int Largest.largest(int[] list);

首份实现代码：

    public class Largest {
        /**
         * Return the largest element in the list.
         *
         * @param list A list of integers
         * @return The largest number in the given list
         *
         */
        public static int largest(int[] list) {
            int index, max = Integer.MAX_VALUE;
            for (index = 0; index < list.length - 1; index++) {
                if (list[index] > max) {
                    max = list[index];
                }
            }
            return max;
        }
    }

### 2.2 Testing a Simple Method
通常而言，你需要让你的首个测试非常简单，因为除了代码本身以外，还有其他的许多因素需要被测试：

 * 凌乱的类名
 * 程序库的位置
 * 还要确认代码能够通过编译

在你的首个测试中，你就需要确保这些因素都是正确的。而在这之后，你就无须在担心这些因素了；因此在你调试一个复杂测试的同时，就不在须要调试这些复杂的集成问题。

    --------------------------------------------------------------------
    import junit.framework.*;

    public class TestLargest extends TestCase {
        
        public TestLargest(String name) {
            super(name);
        }
        
        public void testSimple() {
            assertEquals(9, Largest.largest(new int[]{7,8,9}));
        }
    }

**Java note**

    上面这种创建匿名数组的语法看起来有些奇怪，这完全是作者个人的习惯，在这里这样写只是为了使代码更加简短。如果你不喜欢上面这种写法，那么完全可以用下面的代码来代替它（尽管前面的语法也是一种常用的语法）：

    public void testSimple2() {
        int[] arr = new int[3];
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        assertEquals(9, Largest.largest(arr));
    }

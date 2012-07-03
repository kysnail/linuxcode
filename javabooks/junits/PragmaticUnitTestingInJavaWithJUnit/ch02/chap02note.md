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

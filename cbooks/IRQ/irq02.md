## 尝试用简短的语言描述 IRQ
我想问一下什么是中断号.他的作用是什么,怎么更改中断号?,如果一个硬件没有中断号会怎样?

    机器语言如汇编语言中才会用到的让程序执行到一定的地方就产生中断，然后用跳转指令跳转到其他步骤继续执行。
    中断号是固定的。
    有软中断，也有硬中断（如键盘上的break键）

下面的这个描述更好理解。

    中断号是主板的总线控制控制器用来给各个硬件分配资源的分级表。打个比方，公司里老板的中断级别最高，老板一来大家都要给他让路，他说话时大家都要停止工作听着。而保安中断级别就低，没事你就可以不搭理他。

    硬件的中断号不是固定的，但有一个分配习惯的问题。没有分配中断号，硬件就不能工作。 


## 什么是中断？
我们经常听到中断这个词，到底什么是中断？在这之前我先讲给大家一个故事。

    从前有两位班主任A和B，A老师带一班，B老师带二班。这两位老师平时都很忙，平时除了为学生们备课改作业，当某个同学提出问题时，还要为他们解答疑问。A老师生怕遗漏每一位同学提出的问题，每隔一段时间就放下手头的工作，不断轮流寻问每一位同学：“你有问题吗”。也许被寻问的这位同学恰好有问题要咨询老师，可这毕竟是少数；而当A老师继续批改作业的时候又出现了一些同学提出问题，可是这个时候还没到A老师轮流寻问同学的时间。就这样，A老师的宝贵时间经常被浪费。

    B老师和A老师有所不同，他认为完全没有必要这样死板的寻问每一位同学是否有问题。他对全班同学说：“谁有问题就主动来找我“。即便他可能正在改作业，但是完全可以暂时放下手头那些重要的工作，先为这位迷惑的同学解决问题。因此，B老师既可以改作业，又可以在学生主动提出问题的时候为那个学生解决问题。显然B老师的工作效率比A老师提高了很多。

故事看懂了，那么恭喜你，你也懂了什么是中断。

上面的两位老师分别代表系统中对设备进行管理的两种典型的方式。A老师的那种工作方式属于早期的程序查询控制方式（或称为轮询），内核定期对设备的状态进行查询；而B老师则属于中断控制方式，I/O设备需要服务时，可主动向内核发出中断请求并打断CPU当前正在执行的任务。前者内核为主动；而后者变内核主动为被动，由设备主动向内核发出中断请求。

从物理角度来看，中断请求是由外部硬件设备产生的一种电信号，外部设备首先将这种电信号发给中断控制器，接着中断控制器将此电信号发送给CPU。CPU检查到该中断信号后再通知内核，然后由内核完成后续的一些列处理工作。显然，内核不需要定期去检查设备，从而提高了CPU利用率。

通过以上的描述，你应该对中断有了一个大致的了解，不过想要更具体的了解中断必须搞清楚以下的知识点。

### 1.中断的分类

早期以及一般情况下，我们所说的中断即指由外设所产生的中断。随着计算机的迅速发展，中断不再仅仅局限于外部设备，CPU本身也会产生中断，不过我们将这种中断称为异常。

对于x86体系结构而言，中断可以分为两大类：同步中断和异步中断。同步中断即我们上面所说的异常，它是由 CPU 在执行非法命令时所产生的。之所以称为同步，是因为这种中断请求信号与代码指令同步执行，也就是说只有在一条指令执行完毕后 CPU 才会发出中断，而不是发生在代码指令执行期间。而异步中断即由外部设备产生的中断，这种中断可以随时发生，习惯上，我们将异步中断仍然称为中断。

    同步中断不是太好理解

中断可分为

 * 可屏蔽中断（Maskable interrupt）
 * 不可屏蔽中断（Nomaskable interrupt）

异常可分为
 
 * 故障（fault）
 * 陷阱（trap）
 * 终止（abort）

三类。

可屏蔽中断主要是针对外部设备所产生的中断信号，不可屏蔽中断一般是指计算机内部硬件产生的中断。由于异常是CPU发出的中断信号，与中断控制器（下文有解释）无关，因此异常不能被屏蔽。那么，异常和不可屏蔽中断有些相似点：它们均与外部设备无关，并且均不能被屏蔽。

### 2.中断控制器

中断控制器可分为可编程中断控制器（Programmable Interrupt Controller,PIC）和高级可编程中断控制器（Advanced Programmable Interrupt Controller,APIC）。前者仅可用于单处理器（Uni-processor）平台，后者则可用于多处理器（Mutiliple Processor）平台。

**传统**的PIC都是通过两片级联的8259A来管理和控制15个由外部设备所产生的中断源。由下图可看到，每片8259A芯片最多可管理8个中断源。但由于两片8259A芯片的级联，即从片的INT输出端与主片的2号（第三条线）中断线相连接，所以总共可以管理15个中断源。

![Linux_kernel_interrupt_01.png](./Linux_kernel_interrupt_01.png "Kernel Interrupt")
![Linux_kernel_interrupt_01.png](https://github.com/kysnail/linuxcode/blob/master/kernelbooks/blog/edsionte/irq/Linux_kernel_interrupt_01.png)
![Linux_kernel_interrupt_01.png](https://github.com/kysnail/linuxcode/raw/6e3c63139065f336656d301844b2eaafdec3b41c/kernelbooks/blog/edsionte/irq/Linux_kernel_interrupt_01.png)

    看到说使用 raw 形式的图片，就可以显示了，但是效果还不是很好。
    因为 URL 地址总带有 SHA 对象名，显得很不爽。

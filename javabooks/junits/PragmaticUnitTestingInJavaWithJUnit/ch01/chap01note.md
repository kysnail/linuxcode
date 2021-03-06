## 第 1 章 序言 —— Introduction
`单元测试`：它是项目成功、个人成功的一个不可或缺的部分，但对它，人们却又存在各种各样的误解。单元测试其实是相对廉价而简单的技术，但它能让你更高效地写出质量更好的代码。

许多程序员觉得测试只是一件麻烦事：一种自找的烦恼，唯一的”效果“就是让他们设法专注于手上的正经事——`cutting code` （堆砌代码）。

单元测试的设计目的并不是为了获得一些更好的整体质量。也就是说，它并不是一个针对最终用户、项目经理和开发组长的工具；`而是由程序员自己来完成`，并且最终受益的也是程序员自己。我们是为了自身的利益去使用单元测试，从而让我们的工作变得更加轻松。

### 1.1 Coding With Confidence
对于每个新写的函数，在其他代码使用这个函数并对它形成依赖之前，都要先做单元测试。

### 1.2 What is Unit Testing?
`单元测试` 是开发者编写的一小段代码，用于检验被测代码的一个很小的、很明确的功能是否正确。通常而言，一个单元测试是用于判断某个特定条件（或者场景）下某个特定函数的行为。

    执行单元测试，是为了证明某段代码的行为确实和开发者所期望的一致。

对于客户或最终使用者而言，这种测试必要吗，它与验收测试有关吗？这个问题仍然很难回答。事实上，我们在此并不关心整个产品的确认、验证和正确性等等；甚至此时，我们都不去关心性能方面的问题。我们所要做的一切就是要证明代码的行为和我们的期望一致。因此，我们所要测试的是规模很小的、非常独立的功能片段。通过对所有单独部分的行为建立起信息，确信它们都和我们的期望一致；然后，我们才能开始组装和测试整个系统。

毕竟，要是我们对手上正在写的代码的行为是否和我们的期望一致都没有把握，那么其他形式的测试也都只能是浪费时间而已。在单元测试之后，你还需要其他形式的测试，有可能是更正规的测试，那一切就都要看环境的需要来决定了。总之，做测试如同做善事，总是要从家开始。

### 1.3 Why Should I Bother with Unit Testing?
单元测试不但会使你的工作完成得更轻松，而且会令你的设计变得更好，甚至大大减少你花在调试上面的时间。

为了获得对代码的信心，你需要”询问“代码究竟做了什么，并检查所产生的结果是否确实和你所期望的一直。

这个简单的想法描述了单元测试的核心内涵：

    这个简单有效的技术就是为了令代码变得更加完美。

### 1.4 What Do I Want to Accomplish?
引入单元测试是很简单的，因为它本身就充满了乐趣。然而在项目交付的时候，我们给客户和最终用户的仍然是产品代码，而不包含单元测试的代码；因此，我们必须对单元测试的目的有充分的认识。首先也是最重要的，使用单元测试是为了是你的工作——以及你队友的工作——完成得更加轻松。

**■ Does It Do What I Want?**
最根本的，你想要回答下面这个问题：

    这段代码达到我的目的了吗？

也许就需求而言，代码所做的是错误的事情，但那是另外一个问题了。你要是代码向你证明它所做的就是你所期望的。

**■ Does It Do What I Want All of the Time?**
许多开发者说他们只编写一个测试。也就是让所有代码从头到尾跑一次，只测试代码的一条正确执行路径，只要这样走一遍下来没有问题，测试也就算是完成了。

但是，现实生活当然不会这么事事顺心，事情也不总是那么美好。类似地，在测试某段代码的行为是否和你期望的一致时，你需要确认：

    在任何情况下，这段代码是否都和你的期望一致；譬如在风很大、参数很可疑、硬盘没有剩余空间、网络掉线的时候。

**■ Can I Depend On It?**

    不能依赖的代码是没有多大用处的。

我们希望能够依赖于所编写的代码，并且清楚地知道这些代码的功能和约束。

**■ Does it Document my Intent?**
对于单元测试而言，一个最让人高兴的意外收获就是它能够帮助你充分理解代码的用法。从效果上而言，单元测试就像是能执行的文档，说明了你用各种条件调用代码时，你所能期望这段代码完成的功能。

项目成员能够通过查看单元测试来找到如何使用你所写代码的例子。如果他偶然发现了一个你没有考虑到的测试用例，那么他也可以很快地知道这个事实：

    你的代码可能并不支持这个用例。

显然，在正确性方面，可执行的文档有它的优势。与普通的文档不同的是，单元测试不会出现与代码不一致的情况（当然，除非你选择不运行这些测试）。

### 1.5 How Do I Do Unit Testing?
单元测试本来就是一项简单易学的技术；但是如果能够遵循一些指导性原则（`guideline`）和基本步骤，那么学习将会变得更加容易和有效。

首先要考虑的是在编写这些测试方法之前，如何测试那些可疑的方法。有了这样一个大概的想法之后，你将可以在编写实现代码的时候，或者之前，编写测试代码本身。

下一步，你需要运行测试本身，或者同时运行系统模块的所有其他测试，甚至运行整个系统的测试，前提是这些测试运行起来相对比较快。在此，我们要确保所有的测试都能够通过，而不只是新写的测试能够通过；这一点是非常重要的。也就是说，在保证不引入直接 bug 的同时，你也要保证不会给其他的测试带来破坏。

在这个测试的过程中，我们需要确认每个测试究竟是通过了还是失败了——但这并不意味着你或者其他倒霉的人需要查看每个输出，然后才决定这个代码是否正确的，还是错误的。在此，你慢慢的就会养成一个习惯：

    只要用眼睛瞄一下测试结果，就可以马上知道所有代码是否都是正确的，或者那些代码是有问题的。

关于这个问题，我们将留在讨论如何使用单元测试框架时来具体讨论。

### 1.6 Excuses For Not Testing

    Joe Asks
    What's collateral damage? (间接损害)
    ------------------------------------
    间接损害是：在整个系统中，当某一部分加入了新特性，或者修复了一个 bug 之后，给系统的其他（与
    前面可能是互不相关的）部分引入了一个新的 bug（或者损害）。如果无视这种损害并且继续开发的话，
    那么将可能带来一个很危险的问题，最后可能会导致整个系统崩溃，而且没人能够修复。

    我们有时候把这种损害称为 "Whac-a-Mole" 效应。在狂欢节中有一种游戏叫做 "Whac-a-Mole" ，在此
    游戏中，当小孔中的机械鼠探出头来的时候，参与者的任务就是敲这个机械鼠的头部，然而正在这个时候，
    机械鼠的头马上又缩了回去，不让你打个正着；而位于另一个孔的另一个机械鼠此时又探出头来。就这样，
    机械鼠的头以非常快的速度探出又缩回，使你总是打不到他，从而也就得不到分。最后，参与者通常只能
    无助地乱敲；然而机械鼠的动作却总是出乎你的意料。

    实际上，对于代码而言，大范围的间接损害就具有这样类似的效果。

#### It takes to much time to write the tests

    You see, the trade-off is not "test now" versus "test later". It's linear work now versus
    exponential work and complexity trying to fix and rework at the end. All that extra work
    kills your productivity.

#### It takes to long to run the tests
合适的测试是不会让这种情况发生的。如果遇到了非常耗时的测试，则需要把这些耗时的测试和其他测试分开。通常可以每天运行这种测试一次，或者几天一次；而对于运行很快的测试，则可以经常运行。

#### It's not my job to test my code
实际上，期望别人来清理我们的代码是很不好的做法；甚至在某种情况下，如果别人指出了一大摞有错误的代码，那么也意味着你的职位也就到此为止了。

#### I don't really know how the code is supposed to behave so I can't test it.
如果你是在不清楚代码的行为，那么估计现在并不是编码的时候。或许你应该先建立一个原型，这样才有助于你认清需求。

如果你并不知道代码行为，那么你又如何知道你编写的代码是正确的呢？

#### But it compiles!
编译器的默许只是对代码一种非常粗略的肯定。实际上，任何编译器和解释器都只能验证你的语法是否正确，并不能保证代码的行为也正确。

#### I'm being paid to write code, not to write tests
单元测试大体上是一个工具，是一个和编辑器、开发环境、编译器等处于同一位置的工具。


#### I feel guilty about putting testers and QA(Quality Assurance) staff out of work
你并不需要担心这些。请记住，我们在此只是谈论 **单元测试**，而它只是一种针对源码的、低层次的，为程序员而设计的测试。在整个项目中，还有其他的很多测试需要这些人来完成，如：

 * 功能测试
 * 验收测试
 * 性能测试
 * 环境测试
 * 有效性测试
 * 正确性测试
 * 正规分析

等等。

#### My company won't let me run unit tests on the live system
Whoa! 我们所讨论的只是针对开发者的单元测试。也就是说，如果你可以在其他的环境下（例如在正式的产品系统中）运行这些测试的话，那么

    它们就不再是单元测试，而是其他类型的测试了。

实际上，你可以在你的本机运行单元测试，使用你自己的数据库，或者使用 `mock` 对象（见第 6 章）。

如果 QA 部门或者其他测试人员希望在产品或者其他阶段运行这些测试的话，你可以调整一些技术细节，从而使他们也可以运行一些测试；但是同时要让他们清楚，这些调整后的测试已经不再是单元测试了。
 
### 1.7 Roadmap





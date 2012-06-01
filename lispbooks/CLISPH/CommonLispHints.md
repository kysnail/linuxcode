## Common LISP Hints

### 关于 Common LISP Hints
作者：Geoffrey J. Gordon <ggordon@cs.cmu.edu>

修订：Bruno Haible <haible@ma2s2.mathematik.uni-karlsruhe.de> 与 Peter Van Eynde <s950045@uia.ua.ac.be>

Friday, February 5, 1993

注：本 Common Lisp 教学文件是针对 CMU 版本的 Lisp ，所以使用者之间可能会因为采用的 Lisp 版本不同，在执行细节上有些微差异。

### 更多信息
据我所知到最好的 Lisp 教科书是 Guy L. Steele Jr. 所写的 [Common LISP: the Language ](http://www.amazon.com/Common-LISP-Language-Second-Edition/dp/1555580416/ref=sr_1_3?s=books&ie=UTF8&qid=1338551935&sr=1-3)，该书是在 1984. 由 Digital Press 出版社所出版，它的第一版很容易读，第二版则描述了更多最新的标准。（对于一般的程序设计师而言，第一、二版关于最新标准的些微差异并不会有任何影响。）

另外还有一本由 Dave Touretsky 所写的书也有很多人跟我推荐，不过由于我并没有去读过，所以我也无法评论。

### 符号
符号（Symbols）就是一串字符。你可以在符号中包含字母、数字、连接符等等，唯一的限制就是要以字母开头。（如果你只输入数字，最多再以一个连接符开头的话，LISP 会认为你输入了一个整数而不是符号。）下面是符号的一些范例：

    a
    b
    c1
    foo
    bar
    baaz-quux-garply

你可以像下面的例子一样使用符号。（在 `>` 提示符号后面的就是你输入给 Lisp 解释器的内容，而其它的就是 Lisp 解释器所回显的结果。而 `;` 分号则是 Lisp 的注释符号，在分号之后到该行结束的数据都会被解释器忽略。）

    [1]> (setq a 5)             ; 把数值 5 存入 a 这个符号里。
    5
    [2]> a                      ; 取得 a 这个符号所存的值。
    5
    [3]> (let ((a 6)) a)        ; 暂时性地把 a 这个符号的值给设定成 6 。
    6
    [4]> a                      ; 当脱离 let 区块之后，a 的值又变回到 5
    5
    [5]> (+ a 6)                ; 把 a 这个符号的值当作是加法函数的参数
    11
    [6]> b                      ; 尝试着取得并没有值的 b 这个符号的值看会发生什么事情？

    *** - SYSTEM::READ-EVAL-PRINT: variable B has no value
    The following restarts are available:
    USE-VALUE      :R1      Input a value to be used instead of B.
    STORE-VALUE    :R2      Input a new value for B.
    ABORT          :R3      Abort main loop

    *** - UNIX error 11 (EWOULDBLOCK): Operation would block
    The following restarts are available:
    ABORT          :R1      Abort main loop
    Break 1 [7]>

有两个比较特殊的符号就是 `t` 和 `nil`。`t` 这个符号所定义的值就是 `t`，而 `nil` 这个符号所定义的值就是 `nil`。Lisp 分别把 t 跟 nil 这两个值拿来表示 **真与假**。一个最典型的，会用到 t 跟 nil 的例子就是 `if` 函数，后面将会更详细的介绍 if 函数。

    [1]> (if t 5 6)
    5
    [2]> (if nil 5 6)
    6
    [3]> (if 4 5 6)
    5

最后一个例子或许会让你感到很奇怪，不过它并没有错误。原因是 nil 表示“假”，而任何其它值都表示“真”。（除非你有理由这样写程序，不然通常我们还是习惯用 t 来表示 “真”，这样读程序的时候也比较清楚。）

像 t 和 nil 这样的符号被称为 `自解析符号`，因为他们解析为自身。实际上，还有一大类的自解析符号称为关键字；任意以冒号开头的符号都是关键字。（下面是一些关键字的应用）如下所示：

    [1]> :this-is-a-keyword
    :THIS-IS-A-KEYWORD
    [2]> :so-is-this
    :SO-IS-THIS
    [3]> :me-too
    :ME-TOO
    [4]>

同样地，我们在 `clisp.exe` 环境中运行帮助时会看到， `:` 开头的字符确实都可以被解释为命令。

    $ clisp.exe
      i i i i i i i       ooooo    o        ooooooo   ooooo   ooooo
      I I I I I I I      8     8   8           8     8     o  8    8
      I  \ `+' /  I      8         8           8     8        8    8
       \  `-+-'  /       8         8           8      ooooo   8oooo
        `-__|__-'        8         8           8           8  8
            |            8     o   8           8     o     8  8
      ------+------       ooooo    8oooooo  ooo8ooo   ooooo   8

    Welcome to GNU CLISP 2.48 (2009-07-28) <http://clisp.cons.org/>

    Copyright (c) Bruno Haible, Michael Stoll 1992, 1993
    Copyright (c) Bruno Haible, Marcus Daniels 1994-1997
    Copyright (c) Bruno Haible, Pierpaolo Bernardi, Sam Steingold 1998
    Copyright (c) Bruno Haible, Sam Steingold 1999-2000
    Copyright (c) Sam Steingold, Bruno Haible 2001-2009

    Type :h and hit Enter for context help.

    [1]> :h
    You are in the top-level Read-Eval-Print loop.
    Help (abbreviated :h) = this list
    Use the usual editing capabilities.
    (quit) or (exit) leaves CLISP.
    [2]> ^C
    *** - Ctrl-C: User break
    The following restarts are available:
    ABORT          :R1      Abort main loop

    *** - UNIX error 11 (EWOULDBLOCK): Operation would block
    The following restarts are available:
    ABORT          :R1      Abort main loop
    Break 1 [3]> :h

    Commands may be abbreviated as shown in the second column.
    COMMAND        ABBR     DESCRIPTION
    Help           :h, ?    print this command list
    Error          :e       print the last error message
    Inspect        :i       inspect the last error
    Abort          :a       abort to the next recent input loop
    Unwind         :uw      abort to the next recent input loop
    Reset          :re      toggle *PACKAGE* and *READTABLE* between the
                              local bindings and the sane values
    Quit           :q       quit to the top-level input loop
    Where          :w       inspect this frame
    Up             :u       go up one frame, inspect it
    Top            :t       go to top frame, inspect it
    Down           :d       go down one frame, inspect it
    Bottom         :b       go to bottom (most recent) frame, inspect it
    Mode mode      :m       set stack mode for Backtrace: 1=all the stack elements
                 2=all the frames                         3=only lexical frames
                 4=only EVAL and APPLY frames (default)   5=only APPLY frames
    Frame-limit n  :fl      set the frame-limit for Backtrace. This many frames
                              will be printed in a backtrace at most.
    Backtrace [mode [limit]] :bt  inspect the stack
    Break+         :br+     set breakpoint in EVAL frame
    Break-         :br-     disable breakpoint in EVAL frame
    Redo           :rd      re-evaluate form in EVAL frame
    Return value   :rt      leave EVAL frame, prescribing the return values
    The following restarts are available:
    ABORT          :R1      Abort main loop
    Break 1 [3]>

### 数值
整数的定义就是一连串的数字，并且最前面可以选择性的加上 + 或 - 。而实数看起来很像整数，除了带有小数点并且可以写为科学计数法进行表示。有理数则由两个整数相除而得，也就是在两个整数中间加上 / 。Lisp 还支持复数类型，利用像是 `#c(r i)` 这样表示复数，其中 r 表示复数的实部，i 表示复数的虚部。上例的任何一种都称作是数值（Number）类型。

下面是一些数值类型的例子：

    5
    17
    -34
    +6
    3.1415
    1.722e-15
    #c(1.722e-15 0.75)

对于数值可以进行运算，一些常见的数值函数如 +，=，`*`，/，floor，ceiling，mod，sin，cos，tan，sqrt，exp，expt 都有内建，而且这些内建的函数可以接收任何数值类型的参数。+，-，`*`，/ 这四个函数的返回值类型会随输入参数的类型而自动延伸为较广的类型范围，比如说整数加上有理数的返回值，就会是范围较广的有理数；而有理数加上实数的返回值，是实数；实数加上复数的返回值，则是复数。下面是一些例子：

    [1]> (+ 3 3/4)
    15/4
    [2]> (exp 1)
    2.7182817
    [3]> (exp 3)
    20.085537
    [4]> (expt 3 4.2)
    100.90418
    [5]> (+ 5 6 7 (* 8 9 10))
    738

对于整数绝对值并没有任何参数大小的限制，完全取决于执行时使用的计算机内存够不够。但是要注意，对于大数的计算，越大的数值计算机执行效率一定越慢。（有理数的计算也是会比较慢，尤其是拿来跟不是很大的证书，还有小数的计算速度相对比较，更明显。）

### 点对
点对（cons，复数形式 conses）就是一个有两个字段的数据记录。由于一些历史上的因素，这两个字段分别称作 `"car"` 跟 `"cdr"`。（在第一台实作 Lisp 语言的机器上，CAR 与 CDR 指令分别表示 **"Contents of Address Register"** 及 **"Contents of Decrement Register"**。而 cons 就是透过这两个缓存器而实作的。）Cons 很容易使用：

    [1]> (cons 4 5)                 ; 设置一个 cons ，其中 car 设为数字 4，而 cdr 设为数字 5.
    (4 . 5)
    [2]> (cons (cons 4 5) 6)        ; 设置一个 cons ，其中 car 设为一个点对 (4 . 5)，而 cdr 设为数字 6 。
    ((4 . 5) . 6)
    [3]> (car (cons 4 5))           ; 取出 (4 . 5) 的 car 设定值
    4
    [4]> (cdr (cons 4 5))           ; 取出 (4 . 5) 的 cdr 设定值
    5
    [5]> (car (cons (cons 4 5) 6))
    (4 . 5)
    [6]>

### 链表
利用点对（Cons）我们可以创造出很多结构，而当中最简单的，或许就是链表（`linked list`）。链表其实就是把 Cons 的 CAR 指定成某些元素，而把 CDR 指定到另一个 Cons 或是 NIL。如下，我们可以经由 list 函数来创造链表。

    [1]> (list 4 5 6)
    (4 5 6)

应该注意到，Lisp 采用了一种特殊的方式打印 `linked list`：它输出的时候会省略掉一些 `.` 连接点对的点，以及 `()` 括号。而省略的原则如下，如果这个点对的 CDR 是 NIL 的话，那这个 NIL 跟它前面的连结点将不会被打印出来；如果这个点对 A 的 CDR 是另外一个点对 B 的话，那在点对 B 前面的连结点以及点对 B 本身的小括号都不会被打印出来。如下例子：

    [1]> (cons 4 nil)
    (4)
    [2]> (cons 4 (cons 5 6))
    (4 5 . 6)
    [3]> (cons 4 (cons 5 (cons 6 nil)))
    (4 5 6)
    [4]> (cons nil nil)
    (NIL)
    [5]> (cons nil 6)
    (NIL . 6)
    [6]>

最后的这个例子，其实跟直接调用函数 `(list 4 5 6)` 是等价的。注意 NIL 在这儿的含义就是没有包含任何元素的链表。比如说，包含两个元素的链表 (a b) 中，cdr 是 (b),一个含有单个元素的链表；包含一个元素的链表(b)，cdr 是 nil，故此这里必然是一个没有元素的链表。

    这里实际上包含了一个逻辑演变的过程：
    英文原文说了这么一句：
        Note that nil now means the list with no elements.
    实际上是说 (NIL) 可以演化成一个链表，那么就有了下面将其用作堆栈模拟器的使用方式。

NIL 的 CAR 跟 CDR 都定义成 NIL。

如果我们把链表指给任何变量，那就可以将其当成堆栈（stack）来使用：

    [1]> (setq a nil)
    NIL
    [2]> (push 4 a)
    (4)
    [3]> (push 5 a)
    (5 4)
    [4]> (pop a)
    5
    [5]> a
    (4)
    [6]> (pop a)
    4
    [7]> (pop a)
    NIL
    [8]> a
    NIL
    [9]>



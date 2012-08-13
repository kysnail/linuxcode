## Power Tools for Editing
sed & awk 对于进行文本处理工作的人，可谓一把利器啊。

### May You Solving Interesting Problem
这两年，轻标记语言 Markdown、RestructuredText 等风生水起，全仗于其既可以标记文本，又有良好的可读性。与之配套的后端工具，也如雨后春笋般涌现。配上合适的工具，可以轻松的提取出这些请标记文本中的 **语义** 部分内容，并在其上应用相应的格式标记，从而生成各种想要的格式。这种使用思路，其实与 awk 的设计理念很想。

总结一下，解决上面的这类问题，可能就有了三种方式：

    1. 使用文本编辑器查找所有的引用并用适当的文字串替代它们。
    2. 使用 sed 进行编辑工作。这类似于手工编辑文件，只是比较快。
    3. 使用 awk 编写一个程序：
        (a) 用来读取语义内容，并生成引用名及其定义的列表；
        (b) 读取文档查找引用调用序列；
        (c) 查找列表中的名字并用其定义代替它。

当然，实际中到底使用 sed 还是 awk ，还要依据具体情况而定。

### A Stream Editor
sed 的功能很强大，本小节讲述了 sed 在很多方面的强大功能，但由于对这些功能还未有相应的实际操作体验，所以这里就不技术可以应用的地方，否则就成了抄书了。

稍微总结一下 sed 的功能：

    1. To automate editing actions to be performed on one or more files.
    2. To Simply the task of performing the same edits on multiple files.
    3. To write conversion programs.

### A Pattern-Matching Programming Language
awk 实际上就是 **模式匹配的程序设计语言** 。它相对于 sed 来说，提供了一种更加通用的计算模型，怎么理解呢？sed 所做的操作与在编辑器中引用编辑命令是类似的，但 sed 将你限制在了文本编辑器所能应用的命令这个范文内。而 awk 则没有这种要求。

简单写一些 awk 能够完成的功能：

 * View a text file as a textual databse made of records and fileds.
 * Use variables to manipulate the database.
 * Use arithmetic and string operators.
 * Use common programming constructs such as loops and conditionals.
 * Generate formated reports.
 * Define functions.
 * Execute UNIX commands from a script.
 * Process the result of UNIX commands.
 * Process command-line arguments more gracefully.
 * Work more easily with multiple input streams.

### Four Hurdles to Mastering sed and awk
掌握 sed 和 awk 需要注意下面的 4 点内容：

 1. How to use sed and awk.
 2. To apply UNIX regular expression syntax.
 3. How to interact with the shell.
 4. The knack of script writing.



## The Objects
git 系统中的所有对象，都具有三种属性，分别为：

 * 类型
 * 大小
 * 内容

而 git 中总共有四种类型的对象：

### `blob`
A **blob** is used to store file data - it is generally a file.

### `tree`
A **tree** is basically like a directory - it references a bunch of other trees and/or blobs (i.e. files and sub-directories)

### `commit`
A **commit** prints to a single tree, marking it as what the project looked like at a certain point in time. It contains meta-information about that point in time, such as timestamp, the author of the changes since the last commit, a pointer to the previous commit(s), etc.

### `tag`
A **tag** is a way to mark a specific commit as special in some way. It is normally used to tag certain commits as specific releases or something along those lines.

## 对象概念的核心
基本上所有的 git 操作都是围绕着这 4 个对象进行的。你可以把这 4 个对象所组成的系统当成一个构建在 OS 文件系统上的文件系统。如果明白了这句话，对于后面 git 新概念、新操作的理解就比较容易了。

	Almost all of Git is built around manipulating this simple structure of four different object types.
	It is sort of its own little filesystem that sits on top of your machine's filesystem.


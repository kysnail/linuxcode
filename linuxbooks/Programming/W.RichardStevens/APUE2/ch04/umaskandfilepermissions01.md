## umask and file permissions
本文想强调的最主要的问题：

	为了程序的可以移植性和可读性，最好在程序中使用文件访问模式的宏。

对于文件和目录创建之后的 `file mode` 权限，按照如下方法计算：

### 文件创建权限：

	PERM_MAX_FILE & (mode)

### 目录创建权限：

	PERM_MAX_DIR & (mode)

其中这个 `mode` 就是，在使用 `open()` 或者 `create()` 函数创建文件的时候所提供的第三个参数。

### PERM_MAX_DIR & PERM_MAX_FILE

	PERM_MAX_FILE = 0666 & ~(umask)
	PERM_MAX_DIR = 0777 & ~(umask)

例如：

	umask 0022
	PERM_MAX_FILE = 0644
	PERM_MAX_DIR = 0755

所以在创建文件的时候，你指定的权限不能超过MAX。为了程序的可移植性和可读性，最好在程序中使用文件访问模式的宏。

**Refs**
 
 * [umask和文件权限](http://blog.chinaunix.net/uid-23767307-id-3161655.html)

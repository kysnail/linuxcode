## rsync error
执行下面的命令时：

	# rsync -rvl /root/minisys/ ./my-mnt/

总会提示如下的错误：

	skipping non-regular file 

查看了一下 rsync 的帮助文档，其中提到了下面的内容：

	SYMBOLIC LINKS
	--------------
	By default, symbolic links are not transferred at all.
	A message "skipping non-regular" file is emitted for any symlinks that exists.

我这里是通过添加了 `-a` 选项解决了上面的这个错误的。

	# rsync -rvl /root/minisys/ ./my-mnt/


**Refs**
 
 * [rsync](http://ss64.com/bash/rsync.html)
	

# 项目 php notes 
完成这个项目的过程中遇到了很多 PHP 的问题，先记录如下：

## Call to undefined function exif_imagetype()
这个问题多半是由于未开启扩展而造成的，这里只需要修改 `php.ini` 文件，将下面的注释去掉即可：

    extension=php_mbstring.dll
    extension=php_exif.dll      ; Must be after mbstring as it depends on it

这里提示，`php_exif.dll` 必须放置在 `php_mbstring.dll` 的后面，这点需要注意。

 * [exif_imagetype函数遇到Call to undefined function exif_imagetype问题](http://hi.baidu.com/bjg_sky/item/16882e2830544798b6326357)

## 如何定位错误的问题
项目中的 PHP 实际充当了 CGI 的角色，没有页面可以观察结果。使得我们想要调试就比较困难了，显然你无法使用 `echo` 想页面上输出信息了。这时比较好的方法就是将调试信息写入到服务器的日志文件中。再次过程中可能会用到下面的函数：

 * file_put_contents <=> 
 * fopen
 * fwrite
 * fclose

关于各个函数的具体用法，参看另一篇文档。这里仅以 `file_put_contents` 为例说明：

    file_put_contents("test.log", $_FILES['Filedata']['tmp_name'].$_FILES['Filedata']['name'] );







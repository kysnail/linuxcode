## RedHat 9 下安装 git
尝试了多种方法，最终选定 1.7.1 版本，坚守不折腾原则。

安装过程中可能会出现一些问题，相对比较好解决。

### 问题一

    提示 kerb5.h 找不到的问题。

可以用下面的方式解决：

    # ln -s /usr/kerberos/include/profile.h /usr/include/profile.h
    # ln -s /usr/kerberos/include/krb5.h /usr/include/krb5.h
    # ln -s /usr/kerberos/include/com_err.h /usr/include/com_err.h

### 问题二
关于 curl 库的问题

    remote-curl.c: In function `post_rpc':
    remote-curl.c:393: `CURLOPT_ENCODING' undeclared (first use in this function)
    remote-curl.c:393: (Each undeclared identifier is reported only once
    remote-curl.c:393: for each function it appears in.)
    make: *** [remote-curl.o] Error 1

直接注释掉 393 行当代码。

### 安装过程

    make 
    make install



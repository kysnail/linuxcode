# OpenSSL Installation
OpenSSL 安装过程还是比较简单的，这里以源码方式安装为例：

1. 安装 OpenSSL

    # tar zxvf openssl-0.9.7m.tar.gz 
    # cd openssl-0.9.7m
    # perl ./util/perlpath.pl /usr/bin/perl
    # ./config --prefix=/opt/openssl --openssldir=/opt/openssl shared
    ....
    # make depend; make; make install


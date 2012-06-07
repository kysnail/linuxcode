# 启动 apache 时，报下面的错误。
 
    [root@vim-ap conf]# /opt/apache2/bin/./apachectl start
    Syntax error on line 56 of /opt/apache2/conf/extra/httpd-ssl.conf:
    Invalid command 'SSLPassPhraseDialog', perhaps misspelled or defined by a module not included in the server configuration

通常这个问题是由于没有编译 `mod_ssl.so` 或者 `mod_ssl.c` 模块造成的，默认情况下 apache 是不会安装的，即使配置时使用

    --enable-module=most

也不会安装。

可以查看一下当前的 apache 是否安装了对应的 `mod_ssl` 模块。

    [root@vim-ap conf]# /opt/apache2/bin/./apachectl -l
    Compiled in modules:
      core.c
      mod_authn_file.c
      mod_authn_default.c
      mod_authz_host.c
      mod_authz_groupfile.c
      mod_authz_user.c
      mod_authz_default.c
      mod_auth_basic.c
      mod_include.c
      mod_filter.c
      mod_log_config.c
      mod_env.c
      mod_setenvif.c
      mod_version.c
      prefork.c
      http_core.c
      mod_mime.c
      mod_status.c
      mod_autoindex.c
      mod_asis.c
      mod_cgi.c
      mod_negotiation.c
      mod_dir.c
      mod_actions.c
      mod_userdir.c
      mod_alias.c
      mod_so.c

可以看到，此版本的 apache 并没有安装 `mod_ssl` 模块。

重新安装 Apache 时，还需要考虑到 OpenSSL 的问题。有可能在源码安装 OpenSSL 的过程中，没有正确的进行 `./config` 的配置，异或是没有在 `.bashrc` 中配置，当前的 terminal 无法找到 OpenSSL 的路径。所以最好先安装好 OpenSSL ，并正确配置，然后在安装 Apache 。

1. 安装 OpenSSL

    # ./config --prefix=/opt/openssl --openssldir=/opt/openssl shared

并配置 `~/.bashrc`

    # vim ~/.bashrc
    ...
    ## OpenSSL
    PATH=/opt/openssl/bin:${PATH}; export PATH
    LD_LIBRARY_PATH=/opt/openssl/lib:${LD_LIBRARY_PATH}; export LD_LIBRARY_PATH
    ...
    # source ~/.bashrc

2. 安装 Apache

    # ./configure --prefix=/opt/apache2 --enable-so --enable-ssl --with-ssl=/opt/openssl  

配置完成后，执行下面的命令：

    # make
    # make install

依次安装完成后，即可以正常启动 Apache 服务器了。

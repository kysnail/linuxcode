## 创建 CA 认证中心
所用命令为 `./CA.sh -newca`

    # cd /opt/openssl/misc/
    [root@vsso misc]# tree
    .
    |-- CA.pl
    |-- CA.sh
    |-- c_hash
    |-- c_info
    |-- c_issuer
    `-- c_name

    0 directories, 6 files
    # ./CA.sh  -newca
    [root@vim-ap misc]# ll
    合計 32
    -rwxr-xr-x 1 root root 5502  5月 30 01:34 CA.pl
    -rwxr-xr-x 1 root root 3583  5月 30 01:34 CA.sh
    -rwxr-xr-x 1 root root  119  5月 30 01:34 c_hash
    -rwxr-xr-x 1 root root  152  5月 30 01:34 c_info
    -rwxr-xr-x 1 root root  112  5月 30 01:34 c_issuer
    -rwxr-xr-x 1 root root  110  5月 30 01:34 c_name
    drwxr-xr-x 6 root root 4096  6月  7 01:36 demoCA
    [root@vim-ap misc]# tree
    .
    |-- CA.pl
    |-- CA.sh
    |-- c_hash
    |-- c_info
    |-- c_issuer
    |-- c_name
    `-- demoCA
        |-- cacert.pem
        |-- certs
        |-- crl
        |-- index.txt
        |-- newcerts
        |-- private
        |   `-- cakey.pem
        `-- serial

    5 directories, 10 files
    [root@vim-ap misc]# 

### Error opening CA private key ../../CA/private/cakey.pem
在为客户的公钥进行认证的过程中，报出了下面的错误：

    [root@vim-ap misc]# openssl ca -out apservercrt.pem -infiles apserverreq.pem 
    Using configuration from /etc/pki/tls/openssl.cnf
    Error opening CA private key ../../CA/private/cakey.pem
    699:error:02001002:system library:fopen:No such file or directory:bss_file.c:352:fopen('../../CA/private/cakey.pem','r')
    699:error:20074002:BIO routines:FILE_CTRL:system lib:bss_file.c:354:
    unable to load CA private key

根据系统的配置文件，它确实应该到 `../../CA/private/cakey.pem` 此查找，但实际上，执行完上面的创建命令 `./CA.sh  -newca` 后并没有生成对应的文件夹。

尝试一下这个方法：

    [root@vim-ap misc]# openssl ca -keyfile demoCA/private/cakey.pem -out apservercrt.pem -infiles apserverreq.pem 
    Using configuration from /etc/pki/tls/openssl.cnf
    Enter pass phrase for demoCA/private/cakey.pem:
    Error opening CA certificate ../../CA/cacert.pem
    779:error:02001002:system library:fopen:No such file or directory:bss_file.c:352:fopen('../../CA/cacert.pem','r')
    779:error:20074002:BIO routines:FILE_CTRL:system lib:bss_file.c:354:
    unable to load certificate
    [root@vim-ap misc]# 

结果仍然显示同样的错误，我就纳闷了？翻看了上一次配置成功的服务器发现，原来是使用的配置文件不同：

    上次配置成功的服务器：
    Using configuration from /etc/pki/tls/openssl.cnf
    本次配置失败的服务器：
    Using configuration from /opt/openssl/openssl.cnf

唯独不明白的是，为什么这里会突然跑到 `/etc/pki/tls/openssl.cnf` 这里去查找配置信息？

再试一下 `-config` 这个参数，用来指定所使用的配置文件吧：

    [root@vim-ap misc]# openssl ca -config /opt/openssl/openssl.cnf -out apservercrt.pem -infiles apserverreq.pem 
    Using configuration from /opt/openssl/openssl.cnf
    Enter pass phrase for ./demoCA/private/cakey.pem:
    Check that the request matches the signature
    Signature ok
    Certificate Details:
            Serial Number: 1 (0x1)
            Validity
                Not Before: Jun  6 22:51:00 2012 GMT
                Not After : Jun  6 22:51:00 2013 GMT
            Subject:
                countryName               = CN
                stateOrProvinceName       = ShanXi
                organizationName          = Rayootech
                organizationalUnitName    = VANADIS
                commonName                = nttdata
                emailAddress              = apserver@use.com.cn
            X509v3 extensions:
                X509v3 Basic Constraints: 
                    CA:FALSE
                Netscape Comment: 
                    OpenSSL Generated Certificate
                X509v3 Subject Key Identifier: 
                    1A:0C:34:18:B0:C0:DD:38:F7:CB:05:01:82:7A:AC:58:75:0B:3B:DE
                X509v3 Authority Key Identifier: 
                    keyid:CA:AE:0E:FE:E2:5F:F2:5C:8E:C2:B3:72:C2:3E:74:6C:5D:A4:66:B9
                    DirName:/C=CN/ST=ShanXi/L=XiAn/O=Rayootech/OU=VANADIS/CN=vim-ap.nttdata.co.jp/emailAddress=dairugang@use.com.cn
                    serial:9F:B4:16:BE:2E:20:24:69

    Certificate is to be certified until Jun  6 22:51:00 2013 GMT (365 days)
    Sign the certificate? [y/n]:y


    1 out of 1 certificate requests certified, commit? [y/n]y
    Write out database with 1 new entries
    Data Base Updated

这次总算认证成功了。

**Ref**

 * [OpenSSL的配置文件](http://zl198751.iteye.com/blog/762322)    
 * [解决方法 Error opening CA private key ../../CA/private/cakey.pem](http://blog.csdn.net/php_boy/article/details/6660697)    
 * [Openssl建立根CA及证书的自签和颁发](http://fengzhilinux.blog.51cto.com/1343279/291727)    
 * [(实例) ca 命令（使用默认的配置文件）](http://secyaher.blog.163.com/blog/static/3895577200910294641708/)    
 * [常见证书格式和转换](http://www.cnblogs.com/kungfupanda/archive/2012/01/06.html)    
 * [Error opening CA private key ./demoCA/private/cakey.pem](http://hi.baidu.com/lijunyi0198/item/abafd9f40ce9b62e753c4c05)    

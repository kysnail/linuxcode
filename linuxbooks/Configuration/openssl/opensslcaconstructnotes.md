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



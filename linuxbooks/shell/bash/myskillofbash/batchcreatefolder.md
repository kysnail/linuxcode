## 批量创建文件夹
经常会用到批量创建文件夹的工作，可以尝试下面的方法进行自动化操作。

### 方法一

    # mkdir chap0{1...n}

上面这种方式对于批量创建规则的文件夹很有效。

    $ ll
    total 0
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:14 .
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:14 ..
    
    $ mkdir chapter0{1..4}
    
    $ ll
    total 0
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:16 .
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:14 ..
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:16 chapter01
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:16 chapter02
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:16 chapter03
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:16 chapter04

### 方法二

    $ ll
    total 0
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 .
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:14 ..
    
    $ for i in {5..9}; do mkdir "chapter0$i"; done
    
    $ ll
    total 0
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 .
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 11:14 ..
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 chapter05
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 chapter06
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 chapter07
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 chapter08
    drwxr-xr-x+ 1 kangyushi Domain Users 0 May 28 13:03 chapter09
    
执行 for 循环的方式批量创建。

### 方法三
创建 shell 脚本，

    #!/bin/bash
    
    # 批量创建文件夹
    for ((i = 10; i != 13; i++))
    do
            mkdir chapter0$i
    done

的方式批量创建文件夹。

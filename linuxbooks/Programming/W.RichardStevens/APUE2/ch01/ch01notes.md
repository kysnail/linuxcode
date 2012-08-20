# Chapter 1 - UNIX System Overview

## 1.8. User Identification

### User ID

### Group ID
之所以都使用数值表示用户 ID 和组 ID 是由于历史原因造成的。

数值比对相对比较容易，也不耗系统资源。

**Execution**

    src/fig1.9.c
    ==$ ./a.out 
    uid = 1003, gid = 1000

### Supplementary Group IDs
附加组，其值存放在 

    vim /etc/group
    --------------
    supplementarygroup:x:1000:zhangsan,xiaoli,wangzhizhi

需要注意，一个用户至多属于 16 个另外的组。

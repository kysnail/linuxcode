## Maximum number of connections
公司同事遇到了这样一个问题，在修改寄存项目时，很容易就超过了系统用户的上线。客户现场也是同样的现象，基本上每周需要重启一次数据库。对于要求严格一些的甲方绝对不会容忍这样的产品。

这里就涉及到了 Oracle 最大连接数的问题。

### 什么是最大连接数？
网上直接搜好像没有什么固定的解释。最终还得求助 Tom 大叔。

看了一下 Tom 大叔的解释，真得很清楚！：

    A connection is a physical circuit between you and the database. A connection may be one of many
    types -- most popular begin DEDICATED server and SHARED server. Zero, one or more sessions may
    be established over a given connection to the database as show above with sqlplus. A process will
    be used by a session execute statements. Some there is one to one relationship between 
    CONNECTION->SESSION->PROCESS (eg: a normal dedicated server connection). Sometimes there is one
    to more from connection to sessions (eg: like autotrace, one connection, two sessions, one process).
    A process does not have to be dedicated to specific connection or session however, for example when
    using shared server (MTS), your SESSION will grab a process from the pool of processes in order to
    execute a statement. When the call is over, the process is released back to the pool of process.

### 常用的操作
1. 查看 processes 参数和 sessiones 参数

    SQL> show parameter processes
    OR
    SQL> show parameter sessions

2. 修改 processes 和 sessiones 的值

    SQL> alter system set processes  = 300 scope = spfile;
    OR
    SQL> alter system set sessions = 350 scope = spfile;

3. 修改 processes 和 sessions 值必须重启 oracle 服务器才能生效
ORACLE 的连接数 (sessions) 与其参数文件中的进程数 (process) 有关，它们的关系如下：

    sessions = (1.1 * process + 5)

4. 查看数据库当前进程的连接数：

    SQL> select count(*) from v$process;

5. 查看数据库当前会话的连接数：

    SQL> select count(*) from v$session;

6. 查看数据库的并发连接数：

    SQL> select count(*) from v$session where status='ACTIVE';

7. 查看当前数据库建立的会话情况：

    SQL> select sid, serial#, username, program, machine, status from v$session;

8. 查询数据库允许的最大连接数：

    SQL> select value from v$parameter where name = 'processes';
    OR
    SQL> show parameter processes;

9. 查看当前有哪些用户正在使用数据：

    SQL> select osuser, a.username, cpu_time/executions/1000000 || 's', sql_fulltext, machine from 
         v$session a, v$sqlarea b
         where a.sql_address = b.address
         order by cpu_time/executions desc;
    备注：UNIX 1 个用户 session 对应一个操作系统 process ，而 Windows 体现在线程。

    SQL> 
    SQL> 
    SQL> 
    SQL> 
    SQL> 
    SQL> 




### 修改 Oracle 最大连接数的步骤
1. 以 sysdba 身份登录 pl/sql 或者 worksheet

    sqlplus /nolog
    conn / as sysdba

2. 更改系统连接数

    alter system set processes = 1000 scope = spfile;

3. 创建 pfile

    create pfile from spfile;

4. 重启 Oracle 服务或重启 Oracle 服务器





### Ref
[DIFFERENCES BETWEEN PROCESSES, SESSIONS AND CONNECTIONS](http://asktom.oracle.com/pls/asktom/f?p=100:11:0::::P11_QUESTION_ID:5671284058977)
[修改Oracle最大连接数的步骤有哪些](http://database.51cto.com/art/201004/195505.htm)
[oracle字符集与最大连接数](http://chenxy.blog.51cto.com/729966/652322)
[How to check the maximum number of allowed connections to an Oracle database?](http://stackoverflow.com/questions/162255/how-to-check-the-maximum-number-of-allowed-connections-to-an-oracle-database) 还未验证，下次有机会验证一下。
[oracle的最大连接数问题](http://topic.csdn.net/u/20090105/13/222fb096-5d96-4a9e-8dcb-eeaf9f4b8e51.html)
[[基本管理] 如何查看oracle当前连接数，连接是否执行了sql语句，执行的sql语句是什么](http://www.itpub.net/thread-1547219-1-1.html)
[]()

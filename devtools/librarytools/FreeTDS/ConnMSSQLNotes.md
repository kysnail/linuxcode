## 尝试连接 Microsoft SQL 2008，报如下错误：

	[root@bogon apps]# ./tsql 
	./tsql: error: Missing argument -S or -H
	[root@bogon apps]# !1035
	./tsql -H 192.168.1.75 -p 1433 -U sa -P wan2008
	locale is "ja_JP.UTF-8"
	locale charset is "UTF-8"
	using default charset "UTF-8"
	Error 20017 (severity 9):
		Unexpected EOF from the server
		OS error 115, "現在処理中の操作です"
	Error 20002 (severity 9):
		Adaptive Server connection failed
	There was a problem connecting to the server

1. 首先使用下面的命令查看对应的版本：

	# /usr/local/freetds/bin/tsql -C

2. 修改 `/usr/local/freetds/freetds.conf` 配置文件：

	～
	TDS Version = 8.0
	~
	[W2008]
	host = 192.168.1.18
	port = 1433
	tds version = 5.0

**Refs**

 * [The freetds.conf file](http://www.freetds.org/userguide/freetdsconf.htm)
 * [Choosing a TDS protocol version](http://www.freetds.org/userguide/choosingtdsprotocol.htm)
 * [Confirm the installation](http://www.freetds.org/userguide/confirminstall.htm)
 * [FreeTDS problem connecting to SQL Server on Mac (Unexpected EOF from the server)](http://stackoverflow.com/questions/6973371/freetds-problem-connecting-to-sql-server-on-mac-unexpected-eof-from-the-server)


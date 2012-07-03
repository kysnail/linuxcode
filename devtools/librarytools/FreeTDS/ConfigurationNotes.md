## Configuration Process
Linux 下连接 MSSQL 的配置过程可以分为两大步：

 * 1. 安装和配置 freetds
 * 2. 安装和配置 unixODBC

### 1. 安装和配置 freetds
安装过程很简单，基本上按照文档中的指定流程进行即可。只是需要注意版本间的关系，这也是配置这类数据库应用常见的问题。

`freetds` 就好比 MSSQL 在 Linux 下的驱动。然后安装 unixODBC 这个工具，帮助在系统层面上实现数据库的链接。

### 2. 安装 unixODBC
安装过程也很简单，而且允许开启图形界面的配置。

	--enable-gui
	The defualt is "yes" if QT is found. If you want to build the GUI ODBC Administrator, odbc test and DataManager set 
	this to "yes" (e.g. --enable-gui=yes). You will need QT libraries and header files to build the GUI components (see
	later). You should probably also set --with-x.

下面的这个链接对于 unixODBC 的讲解非常好。

 * [Linux/UNIX ODBC](http://www.easysoft.com/developer/interfaces/odbc/linux.html)

### 3. 涉及到的配置文件
在整个配置过程中，一共涉及了 4 个配置文件，分别为：

	freetds.conf
	------------
	text size = 64512

	[SQLEXPRESS]
	host = 192.168.163.1
	port = 1433
	tds version = 7.0		<==== 这里最好改为 8.0 以上的版本 (Choosing a TDS protocol version)

	---------------------------------------------------------------------------------------------------

	odbcinst.ini
	------------
	[FreeTDS]
	Description     = TDS driver (Sybase/MS SQL)
	Driver          = /usr/lib/odbc/libtdsodbc.so
	Setup           = /usr/lib/odbc/libtdsS.so	<==== 新版本的配置中，对于 Setup 选项并不在需要了 (Where is libtds.so?)
	CPTimeout       =
	CPReuse         =
	FileUsage       = 1

	---------------------------------------------------------------------------------------------------

	odbc.ini
	--------
	[SQLEXPRESS]
	Driver          = FreeTDS
	Description     = ODBC connection via FreeTDS
	Trace           = No
	Servername  	= 192.168.163.1
	Database        = SCOPE_Peel
	Port        	= 1433
	UID         	= sa
	PWD         	= test1234
	ReadOnly    	= No
	TDS_Version	= 8.0		<==== 如果没有这个选项，则会报 Unable to connect to data source 的错误。

#### 4. 测试连接

	tsql
	----
	tsql -S SQLEXPRESS -U sa
	#success
	---------------------------------------------------------------------------------------------------
	isql
	----
	isql SQLEXPRESS sa test1234 -v
	[S1000][unixODBC][FreeTDS][SQL Server]Unable to connect to data source
	[ISQL]ERROR: Could not SQLConnect	<==== 这个错误就有可能是没有添加 TDS_Version 而产生的。
	

**Refs**

 * [Choosing a TDS protocol version](http://www.freetds.org/userguide/choosingtdsprotocol.htm)
 * [Where is libtds.so?](http://www.freetds.org/faq.html#where.is.libtds.so)
 * [freetds odbc Datas (S1000)(unixODBC)(FreeTDS)(SQL Server)Unable to connect to data source](http://get-the-solution.net/index-1-14-118-freetds%2Bodbc%2BDatas%2B%25.html)
 * [freetds odbc Datas (S1000)(unixODBC)(FreeTDS)(SQL Server)Unable to connect to data source](http://mailman.unixodbc.org/pipermail/unixodbc-support/2008-November/001842.html)
 * [FreeTDS - tsql connects, isql fails](http://stackoverflow.com/questions/8010361/freetds-tsql-connects-isql-fails/11306575#11306575)

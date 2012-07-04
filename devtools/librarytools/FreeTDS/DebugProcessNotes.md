## 调试总结
在调试下面代码的过程中，

	/*HC **************************************************************************/
	/* All Rights Reserved, Copyright(C) 2012 wanzheng123@126.com						  */
	/*HC **************************************************************************/
	/**
	 * @file			testgtk.c
	 * @brief			GTK+?形窗口的?定
	 * @version 		0.0.1
	 * @author          wanyanbing
	 * @date			2012/07/01
	 * @note
	 */
	//--------------------------------------

	#include <gtk/gtk.h>
	#include <stdio.h>
	#include <string.h>
	//SQL server
	#include <stdlib.h>
	#include "/usr/include/sql.h"
	#include "/usr/include/sqlext.h"
	#include "/usr/include/sqltypes.h"


	//#include <sql.h>
	//#include <sqlext.h>
	//#include <sqltypes.h>


	//ODBC data type
	SQLHENV   V_OD_Env; //Handle ODBC environmen ?境句柄
	long      V_OD_erg; //result of functions
	SQLHDBC   V_OD_hdbc; //Handle Database Connection 数据??接
	SQLHSTMT  V_OD_hstmt;//分配SQL?句的句柄
	char      V_OD_stat[10]; //Status SQL
	SQLINTEGER   V_OD_err,V_OD_rowanz,V_OD_id; //long int
	SQLSMALLINT  V_OD_mlen,V_OD_colanz; //short int
	char         V_OD_msg[200],V_OD_buffer[200]; 



	const     char * password     = "ssssss";

	void closeApp(GtkWidget * window,gpointer     data)
	{
	    gtk_main_quit();
	}

	//主窗口中按?的回?函数
	void button_clicked(GtkWidget * button, gpointer data )
	{
	    char* password_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *) data));    	
	    //if(strcmp (password_text,password)==0)
	    //      printf("Access granted !\n");
	    // else 
	    //  printf("Access denied !\n");
		
	}

	//主函数
	int main( int argc, char *argv[] )
	{
	   //GTK+?形控件?象声明
	    GtkWidget     *window;
		//label定?
		GtkWidget     *username_label,*password_label;
		//edit定?
		GtkWidget     *username_entry,*password_entry;
		//button定?
		GtkWidget     *button;
		//容器?建定?
		GtkWidget     *hbox1,*hbox2;	
		GtkWidget     *vbox;
		
		//create ODBC handle
	    //step1:allocate Environment handle and register version 

	    ---------------------------------------------------------------------------------------	
		<==== 	程序总是报 SQLAllocHandle 引用错误。这是由于这里只引用了 sql.h 头文件
			编译过程中可以正确的找到对应的 SQLAllocHandle 函数声明，但是对于真正
			的 SQLAllocHandle 函数体则需要在编译时通过链接对应的库完成。
	    ---------------------------------------------------------------------------------------	
	    V_OD_erg = SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&V_OD_Env);
		if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
		{
		    printf("Error AllocHandle\n");
			exit(0);
		}
		//get ODBC version
		V_OD_erg=SQLSetEnvAttr(V_OD_Env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
		if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
		{
		    printf("Error SetEnv\n");
			SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);
			exit(0);
		}
		
		//step2: allocate connection handle, set timeout
		V_OD_erg = SQLAllocHandle(SQL_HANDLE_DBC, V_OD_Env, &V_OD_hdbc);
		if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
		{
		    printf("Error AllocHDB %d\n",V_OD_erg);
			SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);
			exit(0);
		}
		//?定?接超?参数
		SQLSetConnectAttr(V_OD_hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER *)5, 0);
		// 3. Connect to the datasource "DBCard" 

		------------------------------------------------------------------------------------------------------
		<===== 	这里的第二个参数实际上命名规则稍有些歧义，sql.h 中标明应该使用 服务器 名称，但实际上使用
			DSN 。细想一下也对，因为基本上所有的这类型的配置都是使用相同的方式。在配置文件中需要写明
				1. ip 地址	|
				2. 端口号	|--> 实际上 1&2 即组成了一个套接字。
			对于数据库着这样的程序，往往还需要标明需要访问的数据库。
				3. 指定数据库
		------------------------------------------------------------------------------------------------------
		V_OD_erg = SQLConnect(V_OD_hdbc, (SQLCHAR*) "DSNDB", SQL_NTS,
					     (SQLCHAR*) "sa", SQL_NTS,
					     (SQLCHAR*) "wan2008", SQL_NTS);
	    if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
		{
		    printf("Error SQLConnect %d\n",V_OD_erg);
			SQLGetDiagRec(SQL_HANDLE_DBC, V_OD_hdbc,1,V_OD_stat, &V_OD_err,V_OD_msg,100,&V_OD_mlen);
			printf("%s (%d)\n",V_OD_msg,V_OD_err);
			SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);
			exit(0);
		}
		
		printf("Connected !\n");
		V_OD_erg=SQLAllocHandle(SQL_HANDLE_STMT, V_OD_hdbc, &V_OD_hstmt);
		if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
		{
		    printf("Fehler im AllocStatement %d\n",V_OD_erg);
			SQLGetDiagRec(SQL_HANDLE_DBC, V_OD_hdbc,1, V_OD_stat,&V_OD_err,V_OD_msg,100,&V_OD_mlen);
			printf("%s (%d)\n",V_OD_msg,V_OD_err);
			SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);
			exit(0);
		}
		//使用SQLBindCol函数把???果和我?定?的?量?行?定：
	    SQLBindCol(V_OD_hstmt,1,SQL_C_CHAR, &V_OD_buffer,150,&V_OD_err);
	    SQLBindCol(V_OD_hstmt,2,SQL_C_ULONG,&V_OD_id,150,&V_OD_err);
		
		//?用SQLExecDirect来?行??
		V_OD_erg=SQLExecDirect(V_OD_hstmt,"SELECT CardID,CardUser FROM tblICCard order by CardNum",SQL_NTS);   
	    if ((V_OD_erg != SQL_SUCCESS) && (V_OD_erg != SQL_SUCCESS_WITH_INFO))
	    {
		    printf("Error in Select %d\n",V_OD_erg);
		SQLGetDiagRec(SQL_HANDLE_DBC, V_OD_hdbc,1, V_OD_stat,&V_OD_err,V_OD_msg,100,&V_OD_mlen);
		printf("%s (%d)\n",V_OD_msg,V_OD_err);
		SQLFreeHandle(SQL_HANDLE_STMT,V_OD_hstmt);
		SQLFreeHandle(SQL_HANDLE_DBC,V_OD_hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);
		exit(0);
	    }	
		
		//
		V_OD_erg=SQLFetch(V_OD_hstmt);  
	    while(V_OD_erg != SQL_NO_DATA)
	    {
	     printf("Result: %d %s\n",V_OD_id,V_OD_buffer);
	     V_OD_erg=SQLFetch(V_OD_hstmt);  
	    }  ;
		//?于???接和?放句柄
	    SQLFreeHandle(SQL_HANDLE_STMT,V_OD_hstmt);
	    SQLDisconnect(V_OD_hdbc);
	    SQLFreeHandle(SQL_HANDLE_DBC,V_OD_hdbc);
	    SQLFreeHandle(SQL_HANDLE_ENV, V_OD_Env);	
		
		
		//
	      
	    //step2: 初始化GTK+程序
	    gtk_init(&argc, &argv);
	    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		 
	    gtk_window_set_title(GTK_WINDOW(window),"?迎使用?禁身???");
	    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
		//?置窗口size
	    gtk_window_set_default_size(GTK_WINDOW(window),400,400);
		//resizable :FALSE
	    //gtk_window_set_resizable(GTK_WINDOW(window), FALSE);	
	    g_signal_connect(GTK_OBJECT (window),"destroy",GTK_SIGNAL_FUNC(closeApp),NULL);

	    username_label = gtk_label_new ("用?名:");
	    password_label = gtk_label_new ("密 ?:");

	    username_entry =     gtk_entry_new();
	    password_entry =     gtk_entry_new();

	    gtk_entry_set_visibility(GTK_ENTRY (password_entry),FALSE);

	    button = gtk_button_new_with_label("?定");
	    //g_signal_connect(GTK_OBJECT (button),"clicked",GTK_SIGNAL_FUNC(button_clicked),password_entry);
	    g_signal_connect(GTK_OBJECT (button),"clicked",GTK_SIGNAL_FUNC(button_clicked),password_entry);
	    //
	    hbox1 = gtk_hbox_new(TRUE,3);
	    hbox2 = gtk_hbox_new(TRUE,3); 

	    vbox = gtk_vbox_new(FALSE,5); 

	    gtk_box_pack_start(GTK_BOX(hbox1),username_label,TRUE,FALSE,5);
	    gtk_box_pack_start(GTK_BOX(hbox1),username_entry,TRUE,FALSE,5);

	    gtk_box_pack_start(GTK_BOX(hbox2),password_label,TRUE,FALSE,5);
	    gtk_box_pack_start(GTK_BOX(hbox2),password_entry,TRUE,FALSE,5);


	    gtk_box_pack_start(GTK_BOX(vbox),hbox1,FALSE,FALSE,5);
	    gtk_box_pack_start(GTK_BOX(vbox),hbox2,FALSE,FALSE,5);    
	//	
	    gtk_box_pack_start(GTK_BOX(vbox),button,FALSE,FALSE,10);

	    gtk_container_add(GTK_CONTAINER(window),vbox);

	    gtk_widget_show_all(window);

	    gtk_main();
	    return 0;
	}

收获了以下经验:

#### 1. 编译时可以更加灵活的添加编译选项

	gcc testgtk.c `pkg-config --cflags --libs gtk+-2.0 gmodule-2.0 gtkmm-2.4`

`pkg-config --cflags --libs gtk+-2.0 gmodule-2.0 gtkmm-2.4` 选项可以根据系统的状态，动态的指定链接库的位置，优选这种方式进行编译工作。

#### 2. 更加明确了 Linux C 程序的开发流程
头文件中引用的 `*.h` 文件，基本上只包含了函数的声明部分，而函数的主体一般不会提供。需要在链接阶段通过链接完成。

比如上面的程序，虽然 `sql.h` 中声明了对应 `SQLAllocHandle` 方法，但由于编译选项中未指定 `SQLAllocHandle` 所在的库，则在运行时必然会报错。正确的编译指令需要修改为如下内容：

	gcc testgtk.c `pkg-config --cflags --libs gtk+-2.0 gmodule-2.0 gtkmm-2.4` -l odbc

#### 3. sql.h 中函数的声明并不很规范，容易产生歧义
比如 `sql.h` 中 `SQLConnect` 的第二个参数声明为服务器名，而实际上使用的是配置好的 DSN 。

		------------------------------------------------------------------------------------------------------
		<===== 	这里的第二个参数实际上命名规则稍有些歧义，sql.h 中标明应该使用 服务器 名称，但实际上使用
			DSN 。细想一下也对，因为基本上所有的这类型的配置都是使用相同的方式。在配置文件中需要写明
				1. ip 地址	|
				2. 端口号	|--> 实际上 1&2 即组成了一个套接字。
			对于数据库着这样的程序，往往还需要标明需要访问的数据库。
				3. 指定数据库
		------------------------------------------------------------------------------------------------------


### 下面是调试过程中的错误日志信息

	[root@bogon bin]# ./isql -v DSNDB sa wan2008
	[S1000][3w][FreeTDS][SQL Server]Unable to connect to data source
	[01000][unixODBC][FreeTDS][SQL Server]Adaptive Server connection failed
	[01000][unixODBC][FreeTDS][SQL Server]Unexpected EOF from the server
	[ISQL]ERROR: Could not SQLConnect

	-------------------------------------------------------------------------------------------------------------
	log info
	--------
	[ODBC][22493][1341209787.575498][__handles.c][459]
			Exit:[SQL_SUCCESS]
				Environment = 0x8c4ef48
	[ODBC][22493][1341209787.575518][SQLAllocHandle.c][375]
			Entry:
				Handle Type = 2
				Input Handle = 0x8c4ef48
	[ODBC][22493][1341209787.575536][SQLAllocHandle.c][493]
			Exit:[SQL_SUCCESS]
				Output Handle = 0x8c4f6c8
	[ODBC][22493][1341209787.575555][SQLConnect.c][3654]
			Entry:
				Connection = 0x8c4f6c8
				Server Name = [DSNDB][length = 5 (SQL_NTS)]
				User Name = [sa][length = 2 (SQL_NTS)]
				Authentication = [*******][length = 7 (SQL_NTS)]
			UNICODE Using encoding ASCII 'ISO8859-1' and UNICODE 'UCS-2LE'

			DIAG [01000] [FreeTDS][SQL Server]Unexpected EOF from the server

			DIAG [01000] [FreeTDS][SQL Server]Adaptive Server connection failed

			DIAG [S1000] [FreeTDS][SQL Server]Unable to connect to data source

	[ODBC][22493][1341209787.578827][SQLConnect.c][4021]
			Exit:[SQL_ERROR]
	[ODBC][22493][1341209787.578845][SQLError.c][434]
			Entry:
				Connection = 0x8c4f6c8
				SQLState = 0xbf857b5a
				Native = 0xbf857b64
				Message Text = 0xbf857965
				Buffer Length = 500
				Text Len Ptr = 0xbf857b6a
	[ODBC][22493][1341209787.578867][SQLError.c][471]
			Exit:[SQL_SUCCESS]
				SQLState = S1000
				Native = 0xbf857b64 -> 0
				Message Text = [[unixODBC][FreeTDS][SQL Server]Unable to connect to data source]
	[ODBC][22493][1341209787.578989][SQLError.c][434]
			Entry:
				Connection = 0x8c4f6c8
				SQLState = 0xbf857b5a
				Native = 0xbf857b64
				Message Text = 0xbf857965
				Buffer Length = 500
				Text Len Ptr = 0xbf857b6a
	[ODBC][22493][1341209787.579047][SQLError.c][471]
			Exit:[SQL_SUCCESS]
				SQLState = 01000
				Native = 0xbf857b64 -> 20002
				Message Text = [[unixODBC][FreeTDS][SQL Server]Adaptive Server connection failed]
	[ODBC][22493][1341209787.579126][SQLError.c][434]
			Entry:
				Connection = 0x8c4f6c8
				SQLState = 0xbf857b5a
				Native = 0xbf857b64
				Message Text = 0xbf857965
				Buffer Length = 500
				Text Len Ptr = 0xbf857b6a
	[ODBC][22493][1341209787.579144][SQLError.c][471]
			Exit:[SQL_SUCCESS]
				SQLState = 01000
				Native = 0xbf857b64 -> 20017
				Message Text = [[unixODBC][FreeTDS][SQL Server]Unexpected EOF from the server]
	[ODBC][22493][1341209787.579237][SQLError.c][434]
			Entry:
				Connection = 0x8c4f6c8
				SQLState = 0xbf857b5a
				Native = 0xbf857b64
				Message Text = 0xbf857965
				Buffer Length = 500
				Text Len Ptr = 0xbf857b6a
	[ODBC][22493][1341209787.579251][SQLError.c][471]
			Exit:[SQL_NO_DATA]
	[ODBC][22493][1341209787.579263][SQLError.c][514]
			Entry:
				Environment = 0x8c4ef48
				SQLState = 0xbf857b5a
				Native = 0xbf857b64
				Message Text = 0xbf857965
				Buffer Length = 500
				Text Len Ptr = 0xbf857b6a
	[ODBC][22493][1341209787.579274][SQLError.c][551]
			Exit:[SQL_NO_DATA]
	[ODBC][22493][1341209787.579348][SQLFreeHandle.c][286]
			Entry:
				Handle Type = 2
				Input Handle = 0x8c4f6c8
	[ODBC][22493][1341209787.579362][SQLFreeHandle.c][337]
			Exit:[SQL_SUCCESS]
	[ODBC][22493][1341209787.579377][SQLFreeHandle.c][219]
			Entry:
				Handle Type = 1
				Input Handle = 0x8c4ef48

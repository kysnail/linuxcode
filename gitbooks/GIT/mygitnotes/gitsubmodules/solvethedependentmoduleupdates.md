## git submodule - 解决依赖模块更新

### git submodule add 添加项目依赖的模块
在项目的根目录添加子模块

	$ cd demo_project
	$ git submodule add git://github.com/felixge/node-mysql.git deps/mysql
	$ git submodule init
	$ git submodule update
	# 提交更改

### git submodule init and update 就可以直接获取依赖模块了

	$ git submodule init
	...
	
	$ git submodule update
	...
	
	

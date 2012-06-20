## git commit --amend --reset-author

	[kangyushi@fedora16 ch04]$ git commit -v
	[master 991c9db] 第 4 章主要内容 * 向程序传递参数 * 环境变量 * 查看时间 * 临时文件 * 获得有关用户和主机的信 * 生成和配置日志信息 * 了解系统各项资源的限制
	 Committer: Kang Yushi <kangyushi@fedora16.ie2>
	Your name and email address were configured automatically based
	on your username and hostname. Please check that they are accurate.
	You can suppress this message by setting them explicitly:

	    git config --global user.name "Your Name"
	    git config --global user.email you@example.com

	After doing this, you may fix the identity used for this commit with:

	    git commit --amend --reset-author

	 1 files changed, 12 insertions(+), 0 deletions(-)
	 create mode 100644 BPL/ch04/README
	[kangyushi@fedora16 ch04]$ git commit -v

如果你在安装完 git 后，没有进行

    git config --global user.name "Your Name"
    git config --global user.email you@example.com
	
的配置。git 会使用你的用户名和主机名进行 name 和 email 的配置。

如果你完成了一次提交后，才想起应该修改签名，就可以使用 `git commit --amend --reset-author` 命令进行设置。

参照如下：

	[kangyushi@fedora16 mygitnotes]$ git config --global user.name "kysnail"
	[kangyushi@fedora16 mygitnotes]$ git config --global user.email "LifeOfProgrammer@gmail.com"
	[kangyushi@fedora16 mygitnotes]$ git commit --amend --reset-author
	[master 3c80112] 第 4 章主要内容 * 向程序传递参数 * 环境变量 * 查看时间 * 临时文件 * 获得有关用户和主机的信 * 生成和配置日志信息 * 了解系统各项资源的限制
	 1 files changed, 12 insertions(+), 0 deletions(-)
	 create mode 100644 BPL/ch04/README

执行 `git commit --amend --reset-author` 命令的过程中，会让你重新输入 commit 消息，这一点需要注意。

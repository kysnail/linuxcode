## Manual sections
The Unix man command gives you access to documentation in the form of manual ("man") pages at the shell prompt. Enter man followed by the name of the command.

The Unix manual consists of eight sections, and each man page has its command name followed by the section number in parenthesis. Note that if you are a user, you will be using the commands in section 1.

	Section #				Topic
	1			Commands available to users
	2			Unix and C system calls
	3			C library routines for C programs
	4			Special file names
	5			File formats and conventions for files used by Unix
	6			Games
	7			Word processing packages
	8			System administration commands and procedures

## Section of Man Page 

	Section #				Description
	1			用户命令，例如 ls(1)
	2			系统调用，例如 _exit(2)
	3			库函数，例如 printf(3)
	4			特殊文件，例如 null(4) 描述了设备文件 /dev/null、/dev/zero 的作用
	5			系统配置文件的格式，例如 passwd(5) 描述了系统配置文件 /etc/passwd 的格式
	6			游戏
	7			其它杂项，例如 bash-builtins(7) 描述了 bash 的各种内建命令
	8			系统管理命令，例如 ifconfig(8)

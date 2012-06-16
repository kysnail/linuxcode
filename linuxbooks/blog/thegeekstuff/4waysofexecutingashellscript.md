## 4 Ways of Executing a Shell Script in UNIX/Linux
There are four ways to execute a shell script. Each way has it's own meaning as explained in this article.

### 1. Execute Shell Script Using File Name
Using the shell script file name to execute it either by using it's relative path or absolute path as shown below.

	$ cd /home/sathiya
	$ ./scriptfile

	(or)

	$ /home/sathiya/scriptfile

If you have the shebang, then it will be executed using the command interpreter specified in the shebang. If you are beginer in shell scripting, refer our earlier article [Shell Script Execution Guidelines for Newbies](http://www.thegeekstuff.com/2010/01/shell-script-execution-guidelines-for-newbies/) 

### 2. Execute Shell Script by Specifying the Interpreter
You can also execute a unix shell script by specifying the interpreter in the command line as shown below.

**Execute using sh interperter**
	
	$ sh scriptfile

**Execute using bash interpreter**

	$ bash scriptfile

Irrespective of what is being used as shebang, the interpreter which you have specified will be used for execution. You can use any interprepter (sh, ksh, bash, csh etc.,).

### 3. Execute Shell Script Using `.` `./` (dot space not dot slash)
While executing the shell script using "dot space dot slash", as shown below, it will execute the script in the current shell without forking a sub shell.

	$ . ./scriptfile

In other words, this execute the commands specified in the scriptfile in the current shell, and prepare the environment for you.

**dot space dot slash** Usage Example:

Typically we use this method, anytime we change something in the .bashrc or .bash_profile. i.e. After changing the .bashrc or .bash_profile we can either logout and login for the changes to take place (or) use "dot space dot salsh" to execute .bashrc and .bash_profile for the changes to take effect without logout and login.

	$ cd ~
	$ . ./.bashrc
	$ . ./.bash_profile

### 4. Execute Shell Script Using Source Command
The builtin source command is synonym for the . (dot) explained above. If you are not comfortable with the "dot space dot salsh" method, then you can use source command as shown below, as both are same.

	$ source ~/.bashrc


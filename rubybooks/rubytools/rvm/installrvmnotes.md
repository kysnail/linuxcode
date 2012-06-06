## Install RVM

### 安装 RVM
首先执行 `curl -L get.rvm.io | bash -s stable` 命令：

    kysnail@mydbian:~$ curl -L get.rvm.io | bash -s stable
      % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                     Dload  Upload   Total   Spent    Left  Speed
    100  9249  100  9249    0     0   3193      0  0:00:02  0:00:02 --:--:--  5986
    Downloading RVM from wayneeseguin branch stable
      % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                     Dload  Upload   Total   Spent    Left  Speed
    100 1045k  100 1045k    0     0  64933      0  0:00:16  0:00:16 --:--:-- 68129

    Upgrading the RVM installation in /home/kysnail/.rvm/
        RVM PATH line found in /home/kysnail/.bashrc /home/kysnail/.zshrc.
        RVM sourcing line found in /home/kysnail/.bash_login /home/kysnail/.zlogin.

    Upgrade Notes:

      * No new notes to display.

    # RVM:  Shell scripts enabling management of multiple ruby environments.
    # RTFM: https://rvm.io/
    # HELP: http://webchat.freenode.net/?channels=rvm (#rvm on irc.freenode.net)
    # Cheatsheet: http://cheat.errtheblog.com/s/rvm/
    # Screencast: http://screencasts.org/episodes/how-to-use-rvm

    # In case of any issues read output of 'rvm requirements' and/or 'rvm notes'

    Upgrade of RVM in /home/kysnail/.rvm/ is complete.

    # kysnail,
    #
    #   Thank you for using RVM!
    #   I sincerely hope that RVM helps to make your life easier and more enjoyable!!!
    #
    # ~Wayne


    rvm 1.14.1 (stable) by Wayne E. Seguin <wayneeseguin@gmail.com>, Michal Papis <mpapis@gmail.com> [https://rvm.io/]

然后生效

    $ source ~/.bashrc

测试是否安装正确：

    kysnail@mydbian:~$ rvm -v

    rvm 1.14.1 (stable) by Wayne E. Seguin <wayneeseguin@gmail.com>, Michal Papis <mpapis@gmail.com> [https://rvm.io/]

### 用 RVM 安装 Ruby 环境

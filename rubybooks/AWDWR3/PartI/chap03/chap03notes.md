# Chapter 3 - Installing Rails

## Your Shopping List
为了让 Rails 跑起来，你需要下列东西：

 * 一个 Ruby 解释器。
 * Ruby On Rails。
 * 一些必要的库。
 * 数据库

如果要部署应用程序，就（至少）还需要安装一个生产 web 服务器，以及一些能够提升 Rails 运行效率的支持代码。

## Installing on Linux
不同的 Linux 发行版会使用不同的包管理系统，但总的来说安装起来都很方便。

 * aptitude 
 * dpkg
 * portage
 * rpm
 * rug
 * synaptic
 * up2date
 * yum

我这里 Debian 进行的测试，过程还是比较简单，只需要在过程中更换一个国内的 ruby 源即可。

    $ apt-get install build-essential libopenssl-ruby
    $ apt-get install ruby rubygems
  
接下来就可以使用 Rails 的 gem 管理系统安装 rails 以及 sqlite 驱动。

    $ gem install rails
    $ gem install sqlite3-ruby

最后将 `/var/lib/gems/1.8/bin` 加入到 PATH 环境变量中。

    vim ~/.bashrc
    export PATH=/var/lib/gems/1.8/bin:$PATH

## Development Environments

### The Command Line
这里提到了一 Windows 操作系统中的小工具

    TwakUI

值得尝试一下。

### Version Control
我们把所有工作都放在版本控制系统傻瓜——现在用的是 Git。创建一个新的 Rails 项目，我们就会立即把它签入 Git；
每当所有的测试通过时，我们就会把修改过的文件全部签入。一般而言，我们会每小时多次签入代码。

如果项目有多人一起开发，可以考虑搭建一个持续集成（continuous integration, CI）系统：每当有人签入任何修改过的文件时，CI 系统就会签出整个应用程序，然后运行所有测试，这是一种简单的保证意外的破坏能够马上被注意到的方法。此外，CI 系统让客户也可以随时使用应用程序的最新版本。CI 可以大大增加项目的透明度，以确保项目没有偏离正轨。

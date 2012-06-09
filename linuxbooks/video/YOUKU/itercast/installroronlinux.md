# Linux下搭建Ruby On Rails开发环境
OS:RedHat Enterprise Linux 6

## 安装 ruby 基本环境
    # yum list | grpe ruby
    # yum install -y compat-readline5.i686
    # yum groupinstall "Development Tools"          安装开发环境，这点很重要。

    # rpm -ivh ruby-devel*
    # rpm -ivy ruby-rdoc* ruby-irb*

Ruby 所需要的 5 个软件包：

    ruby-1.8.7-*.rpm
    ruby-libs-1.8.7*.rpm
    ruby-devel-1.8.7*.rpm
    ruby-rdoc-1.8.7*.rpm
    ruby-irb-1.8.7*.rpm

查看版本

    # ruby -v

## 安装 RubyGems

    # ruby setup.rb   

修改 RubyGems 镜像

    # gem source -l
    # gem source --remove http://rubygems.org/
    # gem source --add http://ruby.taobao.org/

    # gem install rails

`no ri` 参数，避免生成文档。

    # rails -v
    # gem install rails -v '3.1.3'

生成项目：

    # rails new itercast

会出现 sqlite 错误：

    # yum install -y sqlite-devel
    # gem install sqlite3 -v '1.3.6'

### bundle install
由于安装过程中发生了中断，所以这里需要使用 `bundle install` 重新安装。但在这一步之前需要修改 `Gemfile` 。

    # vim Gemfile
    > source 'http://ruby.taobao.org/

    # bundle install

`Gemfile` 是一个单独定义的配置文件，并不会继承全局的指定值。

不行的是，`rails server` 还不能够正常的启动，需要安装 `v8` 引擎。

    # vim Gemfile
    > 最下面添加
    > gem 'therubyracer'

    # bundle install


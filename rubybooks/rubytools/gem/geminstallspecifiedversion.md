# rails 安装、卸载、使用指定版本

## 安装指定版本：

    gem install rails -v VERSIONNUMBER

## 卸载指定版本：

    gem uninstall -v VERSIONNUMBER

## 用指定版本生成 rails 项目

    rails _1.2.5_ project

可以通过项目生成的 `environment.rb` 查看版本是否正确。

    RAILS_GEM_VERSION = '1.2.5' unless defined? RAILS_GEM_VERSION

又可以使用命令：

    ruby script/about

查看使用版本。

**Refs**

 * [rails安装、卸载、和使用 指定版本](http://fsjoy.blog.51cto.com/318484/100660)

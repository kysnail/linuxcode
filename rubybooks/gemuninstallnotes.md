## 删除所有的 gem 包
逐个删除 gem 包的方式不但麻烦，而且还经常出现不能删除的情况。如果你想重新安装系统，到时可以使用下面的方式删除所有的 Gem 包。

    root@mydebianwork:/work/demo/script# gem list

    *** LOCAL GEMS ***

    actionmailer (3.2.5)
    actionpack (3.2.5)
    activemodel (3.2.5)
    activerecord (3.2.5)
    activeresource (3.2.5)
    activesupport (3.2.5)
    arel (3.0.2)
    builder (3.0.0)
    bundler (1.1.4)
    coffee-rails (3.2.2)
    coffee-script (2.2.0)
    coffee-script-source (1.3.3)
    erubis (2.7.0)
    execjs (1.4.0)
    hike (1.2.1)
    i18n (0.6.0)
    journey (1.0.3)
    jquery-rails (2.0.2)
    json (1.7.3)
    libv8 (3.3.10.4 x86-linux)
    mail (2.4.4)
    mime-types (1.18)
    multi_json (1.3.6)
    polyglot (0.3.3)
    rack (1.4.1)
    rack-cache (1.2)
    rack-ssl (1.3.2)
    rack-test (0.6.1)
    rails (3.2.5)
    railties (3.2.5)
    rake (0.9.2.2)
    rdoc (3.12)
    sass (3.1.19)
    sass-rails (3.2.5)
    sprockets (2.1.3)
    sqlite3 (1.3.6)
    sqlite3-ruby (1.3.3)
    therubyracer (0.10.1)
    thor (0.15.2)
    tilt (1.3.3)
    treetop (1.4.10)
    tzinfo (0.3.33)
    uglifier (1.2.4)
    root@mydebianwork:/work/demo/script# 
    root@mydebianwork:/work/demo/script# gem list --local

    *** LOCAL GEMS ***

    actionmailer (3.2.5)
    actionpack (3.2.5)
    activemodel (3.2.5)
    activerecord (3.2.5)
    activeresource (3.2.5)
    activesupport (3.2.5)
    arel (3.0.2)
    builder (3.0.0)
    bundler (1.1.4)
    coffee-rails (3.2.2)
    coffee-script (2.2.0)
    coffee-script-source (1.3.3)
    erubis (2.7.0)
    execjs (1.4.0)
    hike (1.2.1)
    i18n (0.6.0)
    journey (1.0.3)
    jquery-rails (2.0.2)
    json (1.7.3)
    libv8 (3.3.10.4 x86-linux)
    mail (2.4.4)
    mime-types (1.18)
    multi_json (1.3.6)
    polyglot (0.3.3)
    rack (1.4.1)
    rack-cache (1.2)
    rack-ssl (1.3.2)
    rack-test (0.6.1)
    rails (3.2.5)
    railties (3.2.5)
    rake (0.9.2.2)
    rdoc (3.12)
    sass (3.1.19)
    sass-rails (3.2.5)
    sprockets (2.1.3)
    sqlite3 (1.3.6)
    sqlite3-ruby (1.3.3)
    therubyracer (0.10.1)
    thor (0.15.2)
    tilt (1.3.3)
    treetop (1.4.10)
    tzinfo (0.3.33)
    uglifier (1.2.4)
    root@mydebianwork:/work/demo/script# gem uninstall Rails
    ERROR:  While executing gem ... (Gem::InstallError)
        cannot uninstall, check `gem list -d Rails`
    root@mydebianwork:/work/demo/script# gem list -d Rails

    *** LOCAL GEMS ***

    rails (3.2.5)
        Author: David Heinemeier Hansson
        Homepage: http://www.rubyonrails.org
        Installed at: /var/lib/gems/1.8

        Full-stack web application framework.
    root@mydebianwork:/work/demo/script# gem uninstall rails
    Successfully uninstalled rails-3.2.5
    root@mydebianwork:/work/demo/script# gem uninstall rails
    ERROR:  While executing gem ... (Gem::InstallError)
        cannot uninstall, check `gem list -d rails`
    root@mydebianwork:/work/demo/script# gem uninstall rake
    Remove executables:
        rake

    in addition to the gem? [Yn]  Y
    Removing rake

    You have requested to uninstall the gem:
        rake-0.9.2.2
    therubyracer-0.10.1 depends on [rake (>= 0)]
    treetop-1.4.10 depends on [rake (>= 0)]
    thor-0.15.2 depends on [rake (~> 0.9)]
    libv8-3.3.10.4 depends on [rake (~> 0.9.2)]
    railties-3.2.5 depends on [rake (>= 0.8.7)]
    sprockets-2.1.3 depends on [rake (>= 0)]
    rack-1.4.1 depends on [rake (>= 0)]
    multi_json-1.3.6 depends on [rake (~> 0.9)]
    execjs-1.4.0 depends on [rake (>= 0)]
    If you remove this gems, one or more dependencies will not be met.
    Continue with Uninstall? [Yn]  Y
    Successfully uninstalled rake-0.9.2.2
    root@mydebianwork:/work/demo/script# 
    root@mydebianwork:/work/demo/script# gem uninstall Actionwebservice
    ERROR:  While executing gem ... (Gem::InstallError)
        cannot uninstall, check `gem list -d Actionwebservice`
    root@mydebianwork:/work/demo/script# gem list | cut -d" " -f1 | xargs gem uninstall -aIx 
    Successfully uninstalled actionmailer-3.2.5
    Successfully uninstalled actionpack-3.2.5
    Successfully uninstalled activemodel-3.2.5
    Successfully uninstalled activerecord-3.2.5
    Successfully uninstalled activeresource-3.2.5
    Successfully uninstalled activesupport-3.2.5
    Successfully uninstalled arel-3.0.2
    Successfully uninstalled builder-3.0.0
    Removing bundle
    Successfully uninstalled bundler-1.1.4
    Successfully uninstalled coffee-rails-3.2.2
    Successfully uninstalled coffee-script-2.2.0
    Successfully uninstalled coffee-script-source-1.3.3
    Removing erubis
    Successfully uninstalled erubis-2.7.0
    Successfully uninstalled execjs-1.4.0
    Successfully uninstalled hike-1.2.1
    Successfully uninstalled i18n-0.6.0
    Successfully uninstalled journey-1.0.3
    Successfully uninstalled jquery-rails-2.0.2
    Successfully uninstalled json-1.7.3
    Successfully uninstalled libv8-3.3.10.4-x86-linux
    Successfully uninstalled mail-2.4.4
    Successfully uninstalled mime-types-1.18
    Successfully uninstalled multi_json-1.3.6
    Successfully uninstalled polyglot-0.3.3
    Removing rackup
    Successfully uninstalled rack-1.4.1
    Successfully uninstalled rack-cache-1.2
    Successfully uninstalled rack-ssl-1.3.2
    Successfully uninstalled rack-test-0.6.1
    Removing rails
    Successfully uninstalled railties-3.2.5
    Removing rdoc
    Removing ri
    Successfully uninstalled rdoc-3.12
    Removing sass
    Removing sass-convert
    Removing scss
    Successfully uninstalled sass-3.1.19
    Successfully uninstalled sass-rails-3.2.5
    Successfully uninstalled sprockets-2.1.3
    Successfully uninstalled sqlite3-1.3.6
    Removing sqlite3_ruby
    Successfully uninstalled sqlite3-ruby-1.3.3
    Removing therubyracer
    Successfully uninstalled therubyracer-0.10.1
    Removing rake2thor
    Removing thor
    Successfully uninstalled thor-0.15.2
    Removing tilt
    Successfully uninstalled tilt-1.3.3
    Removing tt
    Successfully uninstalled treetop-1.4.10
    Successfully uninstalled tzinfo-0.3.33
    Successfully uninstalled uglifier-1.2.4
    root@mydebianwork:/work/demo/script# gem list

    *** LOCAL GEMS ***


    root@mydebianwork:/work/demo/script# rails -v
    bash: rails: command not found



## Making qemu images
项目遇到了这样一个需求，想通过 Qemu 的 -pflash 选项启动系统，欲满足此要求，需要先制作对应的 flash 镜像文件。由于 pc flash 镜像文件的制作相对比较复杂，而且没有现成的文档可以参考，所以只能先通过参考一些成熟的嵌入式项目完成 pc flash 的制作。

在此过程中，找到的最合适的文章莫过于这篇了。

[Making qemu images](http://wiki.gumstix.org/index.php?title=Making_qemu_images)

**flash image** 制作过程中会用到三个文件，其生成过程可以参考

[Verdex Pro SVN repository](http://neostix.com/software-development/open-embedded/190-verdex-svn-repository.html)

但现实的条件限制，无法正常完成编译的过程，多数的 ftp 站点已被墙，无奈只好再次寻找 pre-built image 了。

具体的 **Pre-Built Images** 可以从下面的站点获取。

[Pre-Built Images](http://neostix.com/download-prebuilt-images.html)

而相应的制作过程，则可以参考 [Making qemu images] 文章的内容。


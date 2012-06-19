## Tree Object
**tree object** 类似于文件系统中的目录，里面是 **blob** 和 **tree** 对象的集合。

	-------------------------
	|tree		|size	|
	-------------------------
	|blob	|5b1d3	|README	|
	|tree	|03e78	|lib	|
	|tree	|cdc8b	|test	|
	|blob	|cba0a	|test.rb|
	|blob	|911e7	|xdiff	|
	-------------------------

### git show 查看 tree 对象

	kysnail@mydebianwork:BPL$ git ls-tree HEAD
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01
	kysnail@mydebianwork:BPL$ git show 826cc258a6fd340b7cdab2e556a533e180258e15
	tree 826cc258a6fd340b7cdab2e556a533e180258e15

	bill.c
	fred.c
	lib.h
	program.c
	kysnail@mydebianwork:BPL$ 

### git ls-tree 
`git ls-tree` 从 options 的写法可以看出，类似于 git 这个虚拟的文件系统上应用 ls 命令。相对于上面的 git show 命令，这里可以提供更详细的信息。

	kysnail@mydebianwork:BPL$ git ls-tree HEAD
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01

	kysnail@mydebianwork:BPL$ pwd
	/work/repo/git/gh/linuxcode/BPL
	kysnail@mydebianwork:BPL$ tree
	.
	└── ch01
	    ├── bill.c
	    ├── fred.c
	    ├── lib.h
	    └── program.c

	1 directory, 4 files
	kysnail@mydebianwork:BPL$ 

	## git ls-tree 直接跟 patch 号并不一定能够查看到信息，还与当前所处的文件夹有关。
	kysnail@mydebianwork:BPL$ git ls-tree 826cc258a6fd340b7cdab2e556a533e180258e15
	kysnail@mydebianwork:BPL$ git ls-tree -t 826cc258a6fd340b7cdab2e556a533e180258e15
	kysnail@mydebianwork:BPL$ git ls-tree -r 826cc258a6fd340b7cdab2e556a533e180258e15
	kysnail@mydebianwork:BPL$ 
	kysnail@mydebianwork:BPL$ git ls-tree HEAD
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01
	kysnail@mydebianwork:BPL$ git ls-tree --full-tree 826cc258a6fd340b7cdab2e556a533e180258e15
	100644 blob ba5ef4b0acd99909426244ab69d14b7d52fd99b1	bill.c
	100644 blob 598b70842f78f9f10e72be5c885b3ede46551608	fred.c
	100644 blob 103ef88608bebc60a82fe6585abc3503ab7d6556	lib.h
	100644 blob 515c8ebe5445bc541fd2290a31f4205b2ee9f0ab	program.c
	kysnail@mydebianwork:BPL$ 

下面的这个例子更详细些。

	kysnail@mydebianwork:linuxcode$ git ls-tree -r
	usage: git ls-tree [<options>] <tree-ish> [path...]

	    -d                    only show trees
	    -r                    recurse into subtrees
	    -t                    show trees when recursing
	    -z                    terminate entries with NUL byte
	    -l, --long            include object size
	    --name-only           list only filenames
	    --name-status         list only filenames
	    --full-name           use full path names
	    --full-tree           list entire tree; not just current directory (implies --full-name)
	    --abbrev[=<n>]        use <n> digits to display SHA-1s

	kysnail@mydebianwork:linuxcode$ git ls-tree HEAD
	100644 blob 7b979c7bb91b3bf97015fee8272e662d14b2b707	.gitignore
	040000 tree 90057e813caf9ec41f482c7f6de396499a89efe3	BPL
	040000 tree d9dfdeb9951c2b88ecc6e34029f862c4e089bbfe	PVCUG
	100644 blob ad3a6cf275bbf70ff594669fbc07d6bb951abdc6	README
	040000 tree 73eb59368c73775f4a40860445140dfadcf1d99d	SHELL
	040000 tree 84de218cb24bd73c4b1653fffe548cc2020da1ea	algorithmbooks
	040000 tree a64ee6be16ebe9d28279fe65e1cc33c4500163c5	assemblybooks
	040000 tree 309a63425951bd10111d766c042deeb95f2f83fb	cbooks
	040000 tree ad7bd2f2f7985f2df2f21c6dd6162a78a8a993ae	cppbooks
	040000 tree ebc0adf85f6798a956ecee7e914bdb18f67a50c8	devtools
	040000 tree 90c8a42aa4318b91e5bc6e8d75d1bfd426c4b17d	dosite
	040000 tree 9e7ab0eb205a58ac090844bb24593e6beb53fa62	emacsbooks
	040000 tree 059b7b3e975bbe665588eb5ac440864ca2dd6505	gitbooks
	040000 tree 0c4b43d388b8d1a0e1e28a095e05d27f6630c65f	informationsecuritybooks
	040000 tree ae7bf4b16a734a91e47e368d0469426672f67fab	javabooks
	040000 tree 206721b223820008504aa734a8144d0cb70ecdf5	javascriptbooks
	040000 tree b6df8fd32f6c97ca326c58c228d289762a95b48e	kernelbooks
	040000 tree b734953b20c41626a625c38874ef606966a00d24	linuxbooks
	040000 tree e373cbaf09d1b52ee41a05fbbfc53a690140cede	lispbooks
	100644 blob ed0a4bbf54988b3be47824f6c612ab1d4e96c2f5	mkdnotes.mkd
	040000 tree c2626d1b9496cce2c90791475f9174a451c8cc31	oraclebooks
	040000 tree c38ac95b91bf4d391ef7f82c86f5d2bed9ef89cf	pythonbooks
	100644 blob b7deaf528b69e51b2a1026986e60ad8025ebf35e	rstnotes.rst
	040000 tree 58322dcf38ba10aada1349dd872ebb32f7a80918	rubybooks
	100644 blob d7091bf09919a350d72613aedd398ad48f06fabe	w3mnotes.rst
	040000 tree 4d1d6477153c798063d5df63335b07f937f01f76	webdesignbooks

	## show trees when recursing
	kysnail@mydebianwork:linuxcode$ git ls-tree -t 90057e813caf9ec41f482c7f6de396499a89efe3
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01

	kysnail@mydebianwork:linuxcode$ git ls-tree -t -r 90057e813caf9ec41f482c7f6de396499a89efe3
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01
	100644 blob ba5ef4b0acd99909426244ab69d14b7d52fd99b1	ch01/bill.c
	100644 blob 598b70842f78f9f10e72be5c885b3ede46551608	ch01/fred.c
	100644 blob 103ef88608bebc60a82fe6585abc3503ab7d6556	ch01/lib.h
	100644 blob 515c8ebe5445bc541fd2290a31f4205b2ee9f0ab	ch01/program.c
	kysnail@mydebianwork:linuxcode$ git ls-tree -t -r --full-name 90057e813caf9ec41f482c7f6de396499a89efe3
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01
	100644 blob ba5ef4b0acd99909426244ab69d14b7d52fd99b1	ch01/bill.c
	100644 blob 598b70842f78f9f10e72be5c885b3ede46551608	ch01/fred.c
	100644 blob 103ef88608bebc60a82fe6585abc3503ab7d6556	ch01/lib.h
	100644 blob 515c8ebe5445bc541fd2290a31f4205b2ee9f0ab	ch01/program.c

	## git ls-tree 直接跟 patch 号并不一定能够查看到信息，还与当前所处的文件夹有关。
	kysnail@mydebianwork:linuxcode$ git ls-tree 90057e813caf9ec41f482c7f6de396499a89efe3
	040000 tree 826cc258a6fd340b7cdab2e556a533e180258e15	ch01
	kysnail@mydebianwork:linuxcode$ 

tree 对象的功能就类似文件系统的 directory 对象，可以包含 blob 对象，也可以包含子 tree 对象。同样的类似于文件系统的 node 结构，存放的每个条目都有：

 * mode
 * object type
 * SHA1 name
 * name

按照 name 进行排序，用来表示一个目录树的内容。

### Notice 1
在 `submodule` 里，tree 对象也可以指向 commit 对象。

### Notice 2
所有的文件其 mode 位都是 644 或 755 ，这意味着 git 只关心文件的可执行位。

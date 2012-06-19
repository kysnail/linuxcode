## git directory and working directory

### git directory
'Git目录'是为你的项目存储所有历史和元信息的目录 - 包括所有的对象(commits,trees,blobs,tags), 这些对象指向不同的分支。

每一个项目只能有一个'Git目录'(这和SVN,CVS的每个子目录中都有此类目录相反),　这个叫'.git'的目录在你项目的根目录下(这是默认设置,但并不是必须的). 如果你查看这个目录的内容, 你可以看所有的重要文件:

    kysnail@mydebianwork:.git$ tree -L 1
    .
    ├── branches
    ├── COMMIT_EDITMSG
    ├── config                  # 项目的配置信息，git config 命令会改动它
    ├── description             # 项目的描述信息
    ├── FETCH_HEAD
    ├── HEAD                    # 这个 git 项目当前处在哪个分支里
    ├── hooks                   # 系统默认钩子脚本目录
    ├── index                   # 索引文件
    ├── info
    ├── logs                    # 各个 refs 的历史信息
    ├── objects                 # Git 本地仓库的所有对象（commits，trees，blobs，tags）
    ├── ORIG_HEAD
    ├── packed-refs
    └── refs                    # 标识你项目里的每个分支指向了哪个提交（commit）

    6 directories, 8 files

(也许现在还有其它 文件/目录 在 'Git目录' 里面, 但是现在它们并不重要)

### git working directory
t的 '工作目录' 存储着你现在签出(checkout)来用来编辑的文件. 当你在项目的不同分支间切换时, 工作目录里的文件经常会被替换和删除. 所有历史信息都保存在 'Git目录'中 ;　工作目录只用来临时保存签出(checkout) 文件的地方, 你可以编辑工作目录的文件直到下次提交(commit)为止.

## 注意
译者注: 'Git目录' 一般就是指项目根目录下的'.git'目录.

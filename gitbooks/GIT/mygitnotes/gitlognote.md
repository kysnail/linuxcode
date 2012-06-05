## git log configuration
之前没有注意过 git log 选项的配置，知道发现了 tig 这个工具。

原来 git log 本身还具有很强的定制能力。比如下面的这段代码：

	[alias]
		lg = log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --date=relative

配置方法如下：

	git config --global alias.lg "log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit --date=relative"

可以看到很酷的定制效果。

具体每个 placeholder 的含义如下：

    * %H: commit hash
    * %h: 缩短的commit hash
    * %T: tree hash
    * %t: 缩短的 tree hash
    * %P: parent hashes
    * %p: 缩短的 parent hashes
    * %an: 作者名字
    * %aN: mailmap的作者名字 (.mailmap对应，详情参照git-shortlog(1)或者git-blame(1))
    * %ae: 作者邮箱
    * %aE: 作者邮箱 (.mailmap对应，详情参照git-shortlog(1)或者git-blame(1))
    * %ad: 日期 (--date= 制定的格式)
    * %aD: 日期, RFC2822格式
    * %ar: 日期, 相对格式(1 day ago)
    * %at: 日期, UNIX timestamp
    * %ai: 日期, ISO 8601 格式
    * %cn: 提交者名字
    * %cN: 提交者名字 (.mailmap对应，详情参照git-shortlog(1)或者git-blame(1))
    * %ce: 提交者 email
    * %cE: 提交者 email (.mailmap对应，详情参照git-shortlog(1)或者git-blame(1))
    * %cd: 提交日期 (--date= 制定的格式)
    * %cD: 提交日期, RFC2822格式
    * %cr: 提交日期, 相对格式(1 day ago)
    * %ct: 提交日期, UNIX timestamp
    * %ci: 提交日期, ISO 8601 格式
    * %d: ref名称
    * %e: encoding
    * %s: commit信息标题
    * %f: sanitized subject line, suitable for a filename
    * %b: commit信息内容
    * %N: commit notes
    * %gD: reflog selector, e.g., refs/stash@{1}
    * %gd: shortened reflog selector, e.g., stash@{1}
    * %gs: reflog subject
    * %Cred: 切换到红色
    * %Cgreen: 切换到绿色
    * %Cblue: 切换到蓝色
    * %Creset: 重设颜色
    * %C(...): 制定颜色, as described in color.branch.* config option
    * %m: left, right or boundary mark
    * %n: 换行
    * %%: a raw %
    * %x00: print a byte from a hex code
    * %w([[,[,]]]): switch line wrapping, like the -w option of git-shortlog(1).

### Ref:

 * [pimping out git log](http://www.jukie.net/bart/blog/pimping-out-git-log)
 * [git-show(1) - Linux man page](http://linux.die.net/man/1/git-show)
 * [个性化你的Git Log的输出格式](http://ruby-china.org/topics/939)
 * [How can I browse Git Logs without Tig?](http://stackoverflow.com/questions/8934765/how-can-i-browse-git-logs-without-tig)

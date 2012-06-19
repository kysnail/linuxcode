## Different from SVN
传统的版本控制系统，比如 Subversion、CVS、Perforce、Mercurial 等，都是用 

	Delta Storage Systems - 增量文件系统

增量文件系统，每次仅存储版本之间的差异。而 Git 则不同，它会将每次提交的内容（snapshot）都记录下来。这个概念对于理解后续的操作很重要。

	It is important to note that this is very different from most SCM systems that you may be familiar with.
	Subversion, CVS, Perforce, Mercurial and the like all use *Delta Storage systems* - they store the differences
	between one commit and the next. Git does not do this - it stores a snapshot of what all the files in your 
	project look like in this tree structure each time you commit. This is a very important concept to understand
	when using Git.

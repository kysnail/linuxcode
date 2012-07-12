##pathogen.vim

	> mkdir -p ~/.vim/autoload ~/.vim/bundle
	> curl -so ~/.vim/autoload/pathogen.vim https://raw.github.com/tpope/vim-pathogen/master/autoload/pathogen.vim
	> vim ~/.vimrc
	call pathogen#infect()
	syntax on
	filetype plugin indent on

查看 `.vim` 目录结构

	> tree .vim
	.vim
	├── autoload
	│   └── pathogen.vim
	└── bundle

	2 directories, 1 file

查看 `.vimrc` 内容

	call pathogen#infect() 
	syntax on
	filetype plugin indent on

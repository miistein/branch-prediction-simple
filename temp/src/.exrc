if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <S-Tab> <Plug>SuperTabBackward
inoremap <C-Tab> 	
nnoremap J 
nnoremap K 
map Q gq
nnoremap \, :set cursorline!  " toggle highlighting the cursor line
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
imap 	 <Plug>SuperTabForward
inoremap  u
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autowrite
set background=dark
set backspace=indent,eol,start
set cmdheight=2
set copyindent
set directory=~/.vim/.tmp,~/tmp,/tmp
set display=truncate
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set hidden
set history=200
set ignorecase
set incsearch
set langnoremap
set nolangremap
set laststatus=2
set lazyredraw
set nomodeline
set nrformats=bin,hex
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim80,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set scrolloff=5
set shiftround
set shiftwidth=4
set showcmd
set showmatch
set smartcase
set smarttab
set softtabstop=4
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set noswapfile
set switchbuf=useopen
set tabstop=4
set termencoding=utf-8
set ttimeout
set ttimeoutlen=100
set undodir=~/.vim/.undo,~/tmp,/tmp
set undofile
set viminfo='20,\"80
set wildignore=*.swp,*.bak,*.pyc,*.class
set wildmenu
set wildmode=list:full
set nowritebackup
" vim: set ft=vim :

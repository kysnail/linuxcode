## The Object Model
现在我们已经分别了解了三种主要的对象类型，那么再让我们看看他们是如何组织到一起的吧。

If we have a simple project with the following directory structure:

    $>tree
    .
    |-- README
    `-- lib
        |-- inc
        |   `-- tricks.rb
        `-- mylib.rb

    2 directories, 3 files

And we committed this to a Git repository, it would be represented like this:

    ---------------------
    |commit     |size   |
    ---------------------                                   |-----------------> e8455..
    |tree       |0de24  |-------------> 0de24               |           --------------------------------
    ---------------------       ---------------------       |           |blob       |size              |
    |parent     |nil    |       |tree       |sieze  |       |           --------------------------------
    ---------------------       ---------------------       |           |== LICENSE:                   |
    |author     |Scott  |       |blob|e8455 |README |-------|           |(The MIT License)             |
    ---------------------       ---------------------                   |                              |         
    |committer  |Scott  |       |tree|10af9 |lib    |                   |Copyright (c) 2007 Tom Preston|
    ---------------------       ---------------------                   |                              |
    |my commit message  |               |                               --------------------------------
    |goes here and it is|               | 
    |really, really cool|               |
    ---------------------               ↓
                                      10af9                 |-----------------> bc52a..
                                ---------------------       |           --------------------------------
                                |tree       |sieze  |       |           |blob       |size              |
                                ---------------------       |           --------------------------------
                                |blob|bc52a|mylib.rb|-------|           |require 'grit/index'          |
                                ---------------------                   |require 'grit/status'         |
                                |tree|b70f8|inc     |                   |                              | 
                                ---------------------                   |module Grit                   |
                                        |                               |  class << self               |
                                        |                               |    attr_accessor :debug      |
                                        |                               --------------------------------
                                        ↓
                                      b70f8
                                ---------------------
                                |tree       |sieze  |       |-----------------> 0ad1a..
                                ---------------------       |           --------------------------------
                                |blob|0ad1a|tricks.rb|------|           |blob       |size              |
                                ---------------------                   --------------------------------
                                                                        |require 'grit/git-ruby/reposi'|
                                                                        |require 'grit/git-ruby/file_i |
                                                                        |                              | 
                                                                        |module Grit                   |
                                                                        |  module Tricks               |
                                                                        --------------------------------

You can see that we have create a tree object for each directory (including the root) and a blob object for each file. Then we have a commit object to point to the root, so we can track what our project looked like when it was committed.

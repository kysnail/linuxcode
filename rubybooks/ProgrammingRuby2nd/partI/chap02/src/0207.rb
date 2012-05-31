#!/usr/bin/ruby -w
puts "第一种创建单词数组的方式：a = [ 'ant', 'bee', 'cat', 'dog', 'elk' ]"
a = [ 'ant', 'bee', 'cat', 'dog', 'elk' ]
puts "a[0] = #{a[0]}"
puts "a[3] = #{a[3]}"

# this is the same:
puts "第二种创建单词数组的方式：a = %w{ant bee cat dog elk}"
a = %w{ant bee cat dog elk}
puts "a[0] = #{a[0]}"
puts "a[3] = #{a[3]}"


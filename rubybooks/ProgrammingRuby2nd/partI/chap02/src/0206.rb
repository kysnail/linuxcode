#!/usr/bin/ruby -w
a = [1, 'cat', 3.14]    # 有三个元素的数组

# 显示这个数组
puts "显示修改前的数组"
puts a

# 访问第一个元素
puts "\n访问第一个元素 a[0] = #{a[0]}"

# 设置第三个元素
a[2] = nil

# 显示这个数组
puts "\n显示修改后数组"
puts a

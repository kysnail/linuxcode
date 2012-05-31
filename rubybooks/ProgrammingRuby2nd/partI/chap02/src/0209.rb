#!/usr/bin/ruby -w

puts "创建一个空的散列表，并指定默认值 0 "
histogram = Hash.new(0)
puts "histogram['key1'] = #{histogram['key1']}    这里的键值 key1 应该是内置的。"

# 实现技术功能，统计每个键出现的次数。
puts "histogram['key1'] = histogram['key1'] + 1"

histogram['key1'] = histogram['key1'] + 1
puts "histogram['key1'] = #{histogram['key1']}"


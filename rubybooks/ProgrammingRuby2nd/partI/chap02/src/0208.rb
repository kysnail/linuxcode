#!/usr/bin/ruby -w

# 你可能想将乐器映射到它们所属的交响乐章节，可以这么做。
inst_section = {
    'cello'     =>  'string',
    'clarinet'  =>  'woodwind',
    'drum'      =>  'percussion', 
    'oboe'      =>  'woodwind',
    'trumpet'   =>  'brass',
    'violin'    =>  'string'
}

puts "inst_section['oboe'] = #{inst_section['oboe']}"
puts "inst_section['cello'] = #{inst_section['cello']}"
puts "inst_section['bassoon'] = #{inst_section['bassoon']}"

#!/usr/bin/env ruby

line = gets

char_map = {}


line.downcase.gsub(/\s+/, '').chars.each do |c|
  if char_map[c]
    char_map[c] += 1
  else
    char_map[c] = 1
  end
end

counter = 0

char_map.each do |k, v|
  if v.odd?
    counter += 1
  end
end

if counter == 1 or counter == 0
  puts "pal perm!"
else
  puts "not pal perm!"
end

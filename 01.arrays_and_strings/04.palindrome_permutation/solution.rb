#!/usr/bin/env ruby

# line = gets

m = Hash.new(0)
count=0

gets.downcase.gsub(/\s+/, '').chars.each do |c| 
  m[c] += 1
end

m.each do |_,v|
  v.odd? and count += 1
end

puts "palindrome permutation!" if count == 1 or count == 0

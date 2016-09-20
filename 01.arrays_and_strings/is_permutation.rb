#!/usr/bin/env ruby

# CTCI 1.3
# UNTIMED

def no
  puts "False"
  exit 0
end

def yes
  puts "True"
  exit 0
end

s1 = ARGV[0].split("")
s2 = ARGV[1].split("")

h = {}

s1.each do |c|
  if h[c] 
    h[c] += 1
  else
    h[c] = 1
  end
end

s2.each do |c|
  if h[c]
    h[c] -= 1
  else
    no
  end
end

h.each do |k,v|
  if v != 0
    no
  end
end

yes

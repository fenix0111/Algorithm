# Leetcode 1295. Find Numbers with Even Number of Digits
# https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

defmodule Solution do
  @spec find_numbers(nums :: [integer]) :: integer
  def find_numbers(nums) when length(nums) > 1 do
    [h | t] = nums 
    
    if even_number(h, 0) == 1 do
      find_numbers(t) + 1
    else
      find_numbers(t)
    end
  end
    
  def find_numbers(nums) when length(nums) == 1 do
    h = Enum.at(nums, 0) 
    
    if even_number(h, 0) == 1 do
      1
    else
      0
    end
  end
    
  def even_number(num, width) when num > 0 do
    even_number(div(num, 10), width + 1)
  end
  
  def even_number(num, width) when num == 0 do
    if rem(width, 2) == 0 do
      1
    else
      0
    end
  end
end

# Leetcode 1422. Maximum Score After Splitting a String
# https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

defmodule Solution do
  @spec max_score(s :: String.t) :: integer
  def max_score(s) do
    str = to_charlist(s)
    Enum.reduce(1..(Enum.count(str) - 1), 0, fn idx, max_val -> 
        {left, right} = Enum.split(str, idx)

        left_count = Enum.reduce(left, 0, fn num, count -> if num == ?0 , do: count + 1, else: count end)
        right_count = Enum.reduce(right, 0, fn num, count -> if num == ?1, do: count + 1, else: count end)

        left_count = if left_count == nil, do: 0, else: left_count
        right_count = if right_count == nil, do: 0, else: right_count
        
        max_val = max(max_val, left_count + right_count)
    end)
  end
end

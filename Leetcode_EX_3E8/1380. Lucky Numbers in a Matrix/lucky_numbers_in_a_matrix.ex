# Leetcode 1380. Lucky Numbers in a Matrix
# https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

defmodule Solution do
  @spec lucky_numbers (matrix :: [[integer]]) :: [integer]
  def lucky_numbers (matrix) do
    mins = Enum.reduce(matrix, MapSet.new, fn arr, res ->
      MapSet.put(res, Enum.min(arr))
    end)
    
    Enum.zip(matrix) |> Enum.reduce([], fn arr, res ->
      max_val = Enum.max(Tuple.to_list(arr))
      if MapSet.member?(mins, max_val), do: [max_val | res], else: res
    end)
  end
end

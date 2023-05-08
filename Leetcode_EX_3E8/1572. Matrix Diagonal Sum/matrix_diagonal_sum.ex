# Leetcode 1572. Matrix Diagonal Sum
# https://leetcode.com/problems/matrix-diagonal-sum/description/

defmodule Solution do
  @spec diagonal_sum(mat :: [[integer]]) :: integer
  def diagonal_sum(mat) do
    size = length(mat)
    Enum.with_index(mat)
    |> Enum.reduce(0, 
      fn {row, i}, acc ->
         left = i
         right = size - i - 1

         if left == right do
           acc + Enum.at(row, left)
         else
           acc + Enum.at(row, left) + Enum.at(row, right)
         end
    end)
  end
end

# Leetcode 1598. Crawler Log Folder
# https://leetcode.com/problems/crawler-log-folder/description/

defmodule Solution do
  @spec min_operations(logs :: [String.t]) :: integer
  def min_operations(logs) do
    Enum.reduce(logs, 0, fn op, depth ->
      case op do
        "../" -> if depth == 0, do: 0, else: depth - 1
        "./" -> depth
        _ -> depth + 1
      end
    end)
  end
end

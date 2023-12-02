# Leetcode 1592. Rearrange Spaces Between Words
# https://leetcode.com/problems/rearrange-spaces-between-words/description/

defmodule Solution do
  @spec reorder_spaces(text :: String.t) :: String.t
  def reorder_spaces(text) do
    words = String.split(text)
    whitespaces = text |> String.graphemes() |> Enum.count(fn c -> c == " " end)
    if length(words) == 1 do
      Enum.at(words, 0) <> String.duplicate(" ", whitespaces)
    else
      new_space = floor(whitespaces / (length(words) - 1))
      remain = rem(whitespaces, length(words) - 1)
      res = Enum.reduce_while(words, {0, ""}, fn word, {count, str} ->
        new_str = str <> word
        if count < length(words) - 1 do
          {:cont, {count + 1, new_str <> String.duplicate(" ", new_space)}}
        else
          {:halt, {count, new_str}}
        end
        
      end)

      elem(res, 1) <> String.duplicate(" ", remain)
    end
  end
end

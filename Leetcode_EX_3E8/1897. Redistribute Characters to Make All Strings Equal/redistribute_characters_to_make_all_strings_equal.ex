# Leetcode 1897. Redistribute Characters to Make All Strings Equal
# https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

defmodule Solution do
  @spec make_equal(words :: [String.t]) :: boolean
  def make_equal(words) do
    size = length(words)
    counts = Enum.reduce(words, %{}, fn word, res -> 
      str_list = String.graphemes(word)
      word_count = Enum.reduce(str_list, %{}, fn c, res -> 
        count = Map.get(res, c)
        if count == nil do
          Map.put(res, c, 1)
        else
          Map.put(res, c, count + 1)
        end
      end)

      res = Map.merge(res, word_count, fn k, v1, v2 -> v1 + v2 end)
    end)

    Enum.reduce_while(Map.values(counts), true, fn count, res ->
      if rem(count, size) == 0, do: {:cont, res}, else: {:halt, false}
    end)
  end
end

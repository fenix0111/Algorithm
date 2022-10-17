# Leetcode 1832. Check if the Sentence Is Pangram
# https://leetcode.com/problems/check-if-the-sentence-is-pangram/

defmodule Solution do
  @spec check_if_pangram(sentence :: String.t) :: boolean
  def check_if_pangram(sentence) do
    counter = 
    String.to_charlist(sentence) 
      |> Enum.reduce(MapSet.new(), fn c, acc -> MapSet.put(acc, c) end)

    MapSet.size(counter) == 26
  end
end

# Leetcode 1309. Decrypt String from Alphabet to Integer Mapping
# https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

defmodule Solution do
  @spec freq_alphabets(s :: String.t) :: String.t
  def freq_alphabets(s) do
    ss = String.to_charlist(s)
    clist = Enum.reduce(ss, [], 
      fn c, acc -> 
        case c do
          ?# ->
            {x, acc} = List.pop_at(acc, 0)
            {y, acc} = List.pop_at(acc, 0)

            [(?` + (y - ?`) * 10 + (x - ?`)) | acc]

          _ -> [?` + (c - ?0) | acc]
        end
      end)
    List.to_string(Enum.reverse(clist))
  end
end

# Leetcode 1957. Delete Characters to Make Fancy String
# https://leetcode.com/problems/delete-characters-to-make-fancy-string/

defmodule Solution do
  @spec make_fancy_string(s :: String.t) :: String.t
  def make_fancy_string(s) do
    str = to_charlist(s)
    res = make_string(str, 0, 1, [])
    List.to_string(Enum.reverse(res))
  end
    
  def make_string([h|t] = str, lastc, counts, res) do
    if h == lastc do
      if counts >= 2 do
        make_string(t, h, counts + 1, res)
      else
        make_string(t, h, counts + 1, [h|res])
      end
    else
      make_string(t, h, 1, [h|res])
    end
  end
      
  def make_string([] = str, lastc, counts, res) do
    res
  end
end

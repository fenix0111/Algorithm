# Leetcode 1496. Path Crossing
# https://leetcode.com/problems/path-crossing/description/

defmodule Solution do
  @spec is_path_crossing(path :: String.t) :: boolean
  def is_path_crossing(path) do
    path_str = to_charlist(path)
    {x, y, s, res} = 
        Enum.reduce_while(path_str, {0,0,MapSet.new(), false}, fn c, {x, y, s, r} ->
            case c do
            ?N -> 
                key = to_string(x) <> ":" <> to_string(y)
                if MapSet.member?(s, key) do
                    {:halt, {x, y, s, true}}
                else
                    {:cont, {x, y + 1, MapSet.put(s, key), false}}
                end
            ?E -> 
                key = to_string(x) <> ":" <> to_string(y)
                if MapSet.member?(s, key) do
                    {:halt, {x, y, s, true}}
                else
                    {:cont, {x + 1, y, MapSet.put(s, key), false}}
                end
            ?W -> 
                key = to_string(x) <> ":" <> to_string(y)
                if MapSet.member?(s, key) do
                    {:halt, {x, y, s, true}}
                else
                    {:cont, {x - 1, y, MapSet.put(s, key), false}}
                end
            ?S -> 
                key = to_string(x) <> ":" <> to_string(y)
                if MapSet.member?(s, key) do
                    {:halt, {x, y, s, true}}
                else
                    {:cont, {x, y - 1, MapSet.put(s, key), false}}
                end
            end            
        end)

    if res == true do
        true
    else
        key = to_string(x) <> ":" <> to_string(y)
        MapSet.member?(s, key)
    end
  end
end

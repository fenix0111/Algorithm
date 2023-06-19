# Leetcode 1732. Find the Highest Altitude
# https://leetcode.com/problems/find-the-highest-altitude/description/

defmodule Solution do
  @spec largest_altitude(gain :: [integer]) :: integer
  def largest_altitude(gain) do
    Enum.reduce(gain, {0, 0}, fn g, {alt, res} -> 
      {alt + g, max(res, alt + g)}
    end)
    |> elem(1)
  end
end

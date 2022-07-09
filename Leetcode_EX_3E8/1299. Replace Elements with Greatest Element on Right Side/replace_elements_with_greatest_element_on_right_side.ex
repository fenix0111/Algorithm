# Leetcode 1299. Replace Elements with Greatest Element on Right Side
# https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
# time complexity: 
# space complexity: 

defmodule Solution do
  @spec replace_elements(arr :: [integer]) :: [integer]
  def replace_elements(arr) do
    {result, ret_max} = replace_element(arr, Enum.count(arr))
    result
  end
    
  def replace_element(arr, n) when n == 1 do
    [h | _] = arr
    {[-1], h}
  end
    
  def replace_element(arr, n) do
    [h | t] = arr
    {result, ret_max} = replace_element(t, Enum.count(t))
    result = [ret_max | result]
    
    {result, max(h, ret_max)}
  end
end

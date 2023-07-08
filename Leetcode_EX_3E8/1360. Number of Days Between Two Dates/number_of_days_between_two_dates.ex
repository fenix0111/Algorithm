# Leetcode 1360. Number of Days Between Two Dates
# https://leetcode.com/problems/number-of-days-between-two-dates/description/

defmodule Solution do
  @spec days_between_dates(date1 :: String.t, date2 :: String.t) :: integer
  def days_between_dates(date1, date2) do
    {_, date1} =  Date.from_iso8601("#{yyyy}-#{mm}-#{dd}")
    {_, date2} =  Date.from_iso8601("#{yyyy}-#{mm}-#{dd}")

    abs(Date.diff(date1, date2))
  end
end

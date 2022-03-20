# Leetcode 1185. Day of the Week
# https://leetcode.com/problems/day-of-the-week/

# @param {Integer} day
# @param {Integer} month
# @param {Integer} year
# @return {String}
def day_of_the_week(day, month, year)
    Time.gm(year, month, day).strftime("%A")
end

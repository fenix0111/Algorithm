# Leetcode 1154. Day of the Year
# https://leetcode.com/problems/day-of-the-year/

# @param {String} date
# @return {Integer}
def day_of_year(date)
    days = [31,28,31,30,31,30,31,31,30,31,30,31]
    
    year = 0
    info = date.split('-')
    
    year = info[0].to_i
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) 
    if leap == true
        days[1] = 29
    end
    
    mon = info[1].to_i
    d = info[2].to_i
    result = 0
    i = 0
    while i < mon - 1
        result += days[i]
        i += 1
    end
    
    result += d
    return result
end

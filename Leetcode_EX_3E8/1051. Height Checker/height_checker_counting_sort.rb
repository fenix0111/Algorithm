# Leetcode 1051. Height Checker
# https://leetcode.com/problems/height-checker/
# time complexity: O(N)
# space complexity: O(N)

# @param {Integer[]} heights
# @return {Integer}

# using counting sort
def height_checker(heights)
    counter = Array.new(101, 0)
    heights.each { |h| counter[h] += 1 }
    
    i = 1
    j = 0
    result = 0
    while j < heights.length
        if counter[i] != 0
            counter[i] -= 1
            if heights[j] != i
                result += 1
            end
            
            j += 1
        else
            i += 1
        end
    end
    
    return result
end

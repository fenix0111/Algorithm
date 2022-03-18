# time complexity: O(NlogN)
# space complexity: O(1)

# @param {Integer[]} heights
# @return {Integer}
def height_checker(heights)
    sorted_h = heights.sort
    result = 0
    sorted_h.each_with_index do |h, i|
        if heights[i] != h
            result += 1
        end
    end
    
    return result
end

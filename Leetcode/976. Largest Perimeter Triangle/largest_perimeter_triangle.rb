# Leetcode 976. Largest Perimeter Triangle
# https://leetcode.com/problems/largest-perimeter-triangle/

# @param {Integer[]} nums
# @return {Integer}
def largest_perimeter(nums)
    nums = nums.sort
    i = nums.length - 1
    
    while i > 1
        sum = nums[i - 1] + nums[i - 2]
        if nums[i] < sum
            return nums[i] + sum
        end
        
        i -= 1
    end
    
    return 0
end

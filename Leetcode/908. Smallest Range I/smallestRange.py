# Leetcode 908. Smallest Range I
# https://leetcode.com/problems/smallest-range-i/

class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        nums.sort()
        target = nums[0] + k;
        
        for i, val in enumerate(nums):
            diff = target - nums[i]
            if diff >= -k and diff <= k:
                nums[i] = target
            else:
                if diff > 0:
                    nums[i] = nums[i] + k
                elif diff < 0:
                    nums[i] = nums[i] - k
                
        return nums[-1] - nums[0]

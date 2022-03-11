// Leetcode 961. N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        counter = dict()
        for num in nums:
            if num in counter:
                counter[num] = counter[num] + 1
            else:
                counter[num] = 1
            
        target = len(nums) / 2
        for k, v in counter.items():
            if v == target:
                return k
           
        # never reach here
        return -1

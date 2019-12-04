// Leetcode 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Runtime: 8ms

// Related:
// 808. Soup Servings

// O(n), xor through nums
class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int single = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            single ^= nums[i];
        }
        
        return single;
    }
};

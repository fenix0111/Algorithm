// Leetcode 136. Single Number
// https://leetcode.com/problems/single-number/
// Runtime: 12 ms
// Memory: 7.7 MB

// using xor bit manipulation
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ret = ret ^ nums[i];
        }
        
        return ret;
    }
};

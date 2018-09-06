// Leetcode 268. Missing Number
// https://leetcode.com/problems/missing-number/description/
// Runtime: 16ms

// doing xor the same numbers get 0
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int len = nums.size();
        int res = 0;
        
        for (int i = 0; i < len; i++)
        {
            res = res ^ nums[i];
        }
        
        for (int i = 1; i <= len; i++)
        {
            res = res ^ i;
        }
         
        return res;
    }
};

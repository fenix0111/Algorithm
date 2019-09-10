// Leetcode 260. Single Number III
// https://leetcode.com/problems/single-number-iii/
// Runtime: 16ms

// referred to discussion of this question
// bit operation magic
class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int uniq_1 = 0;
        int uniq_2 = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        res &= -res;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (res & nums[i])
                uniq_1 ^= nums[i];
            else
                uniq_2 ^= nums[i];
        }
        vector<int> ret{ uniq_1, uniq_2 };
        return ret;
    }
};

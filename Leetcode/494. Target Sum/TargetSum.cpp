// Leetcode 494. Target Sum
// https://leetcode.com/problems/target-sum/
// Runtime: 1304ms (terrible...)

class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        return helper(nums, S, 0, 0);
    }
    
    int helper(vector<int>& nums, int S, int sum, int pos)
    {
        if (sum == S && pos == nums.size())
        {
            return 1;
        }
        
        if (sum != S && pos >= nums.size())
        {
            return 0;
        }
        
        return helper(nums, S, sum + nums[pos], pos + 1) + helper(nums, S, sum - nums[pos], pos + 1);
    }
};

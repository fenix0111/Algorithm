// Leetcode 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/
// 
// 

class Solution 
{
public:
    int run(vector<int>& nums, vector<int>& dp, int target)
    {
        if (dp[target] != -1)
            return dp[target];
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                res += run(nums, dp, target - nums[i]);
            }
        }
        
        dp[target] = res;
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        run(nums, dp, target);
        
        return dp[target];
    }
};

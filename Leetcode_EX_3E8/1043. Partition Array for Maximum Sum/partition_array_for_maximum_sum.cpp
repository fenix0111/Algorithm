// Leetcode 1043. Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution
{
public:
    int helper(const vector<int>& arr, int k, int index, vector<int>& dp)
    {
        if (index >= arr.size())
        {
            return 0;
        }
        
        if (dp[index] != -1)
        {
            return dp[index];
        }
        
        int result = 0;
        int maxval = 0;
        for (int j = 1; j <= k && index + j <= arr.size(); j++)
        {
            maxval = max(maxval, arr[index + j - 1]);
            result = max(result, maxval * j + helper(arr, k, index + j, dp));
        }
        
        dp[index] = result;
        return result;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        vector<int> dp(arr.size(), -1);
        return helper(arr, k, 0, dp);
    }
};

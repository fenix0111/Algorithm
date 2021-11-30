// Leetcode 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// time complexity: 
// space complexity:

class Solution
{
    int MOD = 1000000007;
public:
    int helper(int d, int f, int target, int idx, vector<vector<int>>& tbl)
    {
        if (target == 0 && d == idx)
        {
            return 1;
        }
        
        if (d == idx)
        {
            return 0;
        }
        
        if (target < 0 || d <= idx)
        {
            return 0;
        }
        
        if (tbl[idx][target] != INT_MAX)
        {
            return tbl[idx][target];
        }
        
        int result = 0;

        for (int j = 1; j <= f; j++)
        {
            result += helper(d, f, target - j, idx + 1, tbl);
            result %= MOD;
        }
        
        tbl[idx][target] = result;
        return tbl[idx][target];
    }
    
    int numRollsToTarget(int d, int f, int target) 
    {
        if (d > target)
        {
            return 0;
        }
        
        vector<vector<int>> tbl(d, vector<int>(target + 1, INT_MAX));
        return helper(d, f, target, 0, tbl);
    }
};

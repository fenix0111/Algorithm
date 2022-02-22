// Leetcode 486. Predict the Winner
// https://leetcode.com/problems/predict-the-winner/
// time complexity: O(N^2)
// space complexity: O(N)

class Solution
{
public:
    int predict(vector<int>& nums, int i, int j, vector<vector<int>>& memo)
    {
        if (i == j)
        {
            return nums[i];
        }
        
        if (memo[i][j] != INT_MIN)
        {
            return memo[i][j];
        }
        
        int x = nums[i] - predict(nums, i + 1, j, memo);
        int y = nums[j] - predict(nums, i, j - 1, memo);
        memo[i][j] = max(x, y);
        
        return memo[i][j];
    }
    
    bool PredictTheWinner(vector<int>& nums)
    {
        int sz = nums.size();
        // vector<vector<int>> memo(sz, vector<int>(sz, INT_MIN));
        vector<int> memo(sz, INT_MIN);
        
        for (int i = sz - 1; i >= 0; i--)
        {
            for (int j = i; j < sz; j++)
            {
                if (i == j)
                {
                    memo[i] = nums[i];
                }
                else
                {
                    int x = nums[i] - memo[j];
                    int y = nums[j] - memo[j - 1];
                    memo[j] = max(x, y);
                }
            }
        }
        
        return memo[sz - 1] >= 0;
    }
};

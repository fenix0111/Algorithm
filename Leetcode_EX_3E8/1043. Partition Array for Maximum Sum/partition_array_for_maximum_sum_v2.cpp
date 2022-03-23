class Solution
{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        vector<int> dp(arr.size() + 1, 0);
        
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int maxval = 0;
            for (int j = 1; j <= k; j++)
            {
                if (i + j > arr.size())
                {
                    break;
                }
                
                maxval = max(maxval, arr[i + j - 1]);
                
                dp[i] = max(dp[i], maxval * j + dp[i + j]);
            }
        }
        
        return dp.front();
    }
};

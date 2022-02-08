// Leetcode 646. Maximum Length of Pair Chain
// https://leetcode.com/problems/maximum-length-of-pair-chain/
// time complexity: O(N^2)
// space complexity: O(N)

class Solution
{
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0];
        });
        
        int sz = pairs.size();
        vector<int> dp(sz, 1);
        int result = 1;
        
        for (int i = sz - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (pairs[i][1] < pairs[j][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    result = max(dp[i], result);
                }
            }
        }
        
        return result;
    }
};

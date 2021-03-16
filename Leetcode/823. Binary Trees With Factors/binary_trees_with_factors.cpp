// Leetcode 823. Binary Trees With Factors
// https://leetcode.com/problems/binary-trees-with-factors/
// time complexity: O(n * n)
// space complexity: O(n)

class Solution 
{
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        unordered_map<int, int> M;
        int mod = 1000000007;
        int size = arr.size();
        long long result = 0;
        sort(arr.begin(), arr.end());
        
        vector<long long> dp(size, 1);
        
        for (int i = 0; i < size; i++)
        {
            M[arr[i]] = i;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int q = arr[i] / arr[j];
                    if (M.find(q) != M.end())
                    {
                        dp[i] = (dp[i] + dp[j] * dp[M[q]]) % mod;
                    }
                }
            }
            
            result += dp[i];
        }
        
        return result % mod;
    }
};

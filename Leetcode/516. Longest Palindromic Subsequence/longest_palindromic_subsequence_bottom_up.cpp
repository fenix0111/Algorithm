// Leetcode 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/
// time complexity: O(len(s)^2)
// space complexity: O(len(s)^2)

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int len = s.length();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        // i: left index
        // j: right index
        for (int j = 0; j < len; j++)
        {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; i--)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = (dp[i + 1][j - 1] + 2);
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][len - 1];
    }
};

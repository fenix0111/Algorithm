// Leetcode 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/
// time complexity: O(len(word1) * len(word2))
// space complexity: O(len(word1) * len(word2))

// actually a longest common subsequence problem
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int row = word1.length();
        int col = word2.length();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        
        for (int r = 1; r <= row; r++)
        {
            for (int c = 1; c <= col; c++)
            {
                if (word1[r - 1] == word2[c - 1])
                {
                    dp[r][c] = dp[r - 1][c - 1] + 1;
                }
                else
                {
                    dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
                }
            }
        }
        
        int lcs = dp.back().back();
        return (word1.length() - lcs) + (word2.length() - lcs);
    }
};

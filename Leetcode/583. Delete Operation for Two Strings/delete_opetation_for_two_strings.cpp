// Leetcode 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/
// time complexity: O(len(word1) * len(word2))
// space complexity: O(len(word1) * len(word2))

// actually a longest common subsequence problem
class Solution 
{
public:
    int longestCommonSubsequence(string& text1, string& text2) 
    {
        int row = text2.length();
        int col = text1.length();
        
        int tbl[row + 1][col + 1];
        for (int i = 0; i <= row; i++)
        {
            tbl[i][0] = 0;
        }
        
        for (int i = 0; i <= col; i++)
        {
            tbl[0][i] = 0;
        }
        
        for (int r = 1; r <= row; r++)
        {
            for (int c = 1; c <= col; c++)
            {
                if (text1[c - 1] == text2[r - 1])
                {
                    tbl[r][c] = tbl[r - 1][c - 1] + 1;
                }
                else
                {
                    tbl[r][c] = tbl[r - 1][c] > tbl[r][c - 1] ? tbl[r - 1][c] : tbl[r][c - 1];
                }
            }
        }

        return tbl[row][col];
    }
    
    int minDistance(string word1, string word2) 
    {
        int lcs = longestCommonSubsequence(word1, word2);
        return word1.length() - lcs + word2.length() - lcs;
    }
};

// Leetcode 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/
// Runtime: 16 ms
// Memory: 10.6 MB

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
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
};

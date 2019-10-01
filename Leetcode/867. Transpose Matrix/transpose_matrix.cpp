// Leetcode 867. Transpose Matrix
// https://leetcode.com/problems/transpose-matrix/
// Runtime: 28ms

class Solution 
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        int row = A.size();
        if (row == 0)
            return A;
        
        int col = A[0].size();
        vector<vector<int>> ret(col, vector<int>(row, 0));
        for (int c = 0; c < col; c++)
        {
            for (int r = 0; r < row; r++)
            {
                ret[c][r] = A[r][c];
            }
        }
        
        return ret;
    }
};

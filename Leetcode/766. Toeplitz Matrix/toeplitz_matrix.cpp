// Leetcode 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/
// time complexity: O(R*C)
// space complexity: O(1)

// trivial solution
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int r = row - 1; r >= 0; r--)
        {
            int num = matrix[r][0];
            
            int i = r + 1;
            int j = 1;
            while (i < row && j < col)
            {
                if (matrix[i][j] != num)
                {
                    return false;
                }
                
                i++;
                j++;
            }
        }
        
        for (int c = 1; c < col; c++)
        {
            int num = matrix[0][c];
            
            int i = 1;
            int j = c + 1;
            while (i < row && j < col)
            {
                if (matrix[i][j] != num)
                {
                    return false;
                }
                
                i++;
                j++;
            }
        }
        
        return true;
    }
};

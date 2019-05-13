// Leetcode 221. Maximal Square
// https://leetcode.com/problems/maximal-square/
// Runtime: 20ms

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int row_size = matrix.size();
        
        if (row_size < 1)
        {
            return 0;
        }
        
        int col_size = matrix[0].size();
        int max = 0;
        
        if (row_size < 2 || col_size < 2)
        {
            bool has_one = false;
            for (int r = 0; r < row_size; r++)
            {
                for (int c = 0; c < col_size; c++)
                {
                    has_one |= (matrix[r][c] == '1');
                }
            }
            
            return has_one;
        }
        
        vector< vector<int> > tbl(row_size, vector<int>(col_size));
        
        for (int r = 0; r < row_size; r++)
        {
            for (int c = 0; c < col_size; c++)
            {
                if (matrix[r][c] == '1')
                {
                    tbl[r][c] = 1;
                }
            }
        }
        
        for (int r = 0; r < row_size - 1; r++)
        {
            for (int c = 0; c < col_size - 1; c++)
            {
                if (matrix[r][c] == '1' && matrix[r][c + 1] == '1' && matrix[r + 1][c] == '1' && matrix[r + 1][c + 1] == '1')
                {
                    int min = tbl[r][c];
                    if (min > tbl[r][c + 1])
                    {
                        min = tbl[r][c + 1];
                    }
                    
                    if (min > tbl[r + 1][c])
                    {
                        min = tbl[r + 1][c];
                    }
                    
                    tbl[r + 1][c + 1] = min + 1;
                    if (min + 1 > max)
                    {
                        max = min + 1;
                    }
                }
            }
        }
        
        // no square found
        // check if matrix has the single '1'
        if (max == 0)
        {
            bool has_one = false;
            for (int r = 0; r < row_size; r++)
            {
                for (int c = 0; c < col_size; c++)
                {
                    has_one |= (matrix[r][c] == '1');
                }
            }
            if (has_one)
            {
                max = 1;
            }
        }
        
        return max * max;
    }
};

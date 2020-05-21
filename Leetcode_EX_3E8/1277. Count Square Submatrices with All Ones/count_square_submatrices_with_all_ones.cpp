// Leetcode 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    int min(int x, int y, int z)
    {
        if (x <= y && x <= z)
            return x;
        
        if (y <= x && y <= z)
            return y;
        
        if (z <= x && z <= y)
            return z;
        
        return x;
    }

    int countSquares(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int **tbl = (int**)malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++)
        {
            tbl[i] = (int*)malloc(sizeof(int) * col);
        }
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                tbl[r][c] = 0;
            }
        }
        
        int square = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (r == 0 || c == 0)
                {
                    tbl[r][c] = matrix[r][c];
                }
                else
                {
                    if (matrix[r][c] == 0)
                    {
                        tbl[r][c] = 0;
                    }
                    else
                    {
                        int minval = min(tbl[r - 1][c - 1], tbl[r - 1][c], tbl[r][c - 1]);
                        tbl[r][c] = minval + 1;
                    }
                }
                
                square += tbl[r][c];
            }
        }
        
        return square;
    }
};

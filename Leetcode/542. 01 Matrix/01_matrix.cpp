// Leetcode 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/
// time complexity: 
// space complexity: O(size of matrix)

class Solution 
{
public:
    void DFS(int r, int c, vector<vector<int>>& ret, vector<vector<int>>& matrix, int row, int col, int step)
    {
        if (step > row + col)
        {
            return;
        }
        
        if (r < 0 || r >= row || c < 0 || c >= col)
        {
            return;
        }
        
        if (step > ret[r][c])
        {
            return;
        }
        
        if (matrix[r][c] == 1)
        {
            if (step < ret[r][c])
            {
                ret[r][c] = step;
            }
            
            DFS(r + 1, c, ret, matrix, row, col, step + 1);
            DFS(r, c + 1, ret, matrix, row, col, step + 1);
            DFS(r - 1, c, ret, matrix, row, col, step + 1);
            DFS(r, c - 1, ret, matrix, row, col, step + 1);
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> ret(row, vector<int>(col, INT_MAX));
        
        // pre-processing
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (matrix[r][c] == 0)
                {
                    ret[r][c] = 0;
                    
                    if (r > 0)
                    {
                        if (matrix[r - 1][c] == 1)
                        {
                            ret[r - 1][c] = 1;
                        }
                    }
                
                    if (c > 0)
                    {
                        if (matrix[r][c - 1] == 1)
                        {
                            ret[r][c - 1] = 1;
                        }
                    }

                    if (c < col - 1)
                    {
                        if (matrix[r][c + 1] == 1)
                        {
                            ret[r][c + 1] = 1;
                        }
                    }

                    if (r < row - 1)
                    {
                        if (matrix[r + 1][c] == 1)
                        {
                            ret[r + 1][c] = 1;
                        }
                    }
                }
            }
        }
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (matrix[r][c] == 0)
                {
                    ret[r][c] = 0;
                    DFS(r + 1, c, ret, matrix, row, col, 1);
                    DFS(r, c + 1, ret, matrix, row, col, 1);
                    DFS(r - 1, c, ret, matrix, row, col, 1);
                    DFS(r, c - 1, ret, matrix, row, col, 1);
                }
            }
        }
        
        return ret;
    }
};

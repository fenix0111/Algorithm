// Leetcode 807. Max Increase to Keep City Skyline
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/
// Runtime: 4ms

class Solution 
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> newGrid(row, vector<int>(col, 0));
        
        // fill row-max
        for (int r = 0; r < row; r++)
        {
            int max = -1;
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] > max)
                {
                    max = grid[r][c];
                }
            }
            
            for (int c = 0; c < col; c++)
            {
                newGrid[r][c] = max;
            }
        }
        
        // fill column-max
        // if value is greater than column-max, lower it
        for (int c = 0; c < col; c++)
        {
            int max = -1;
            for (int r = 0; r < row; r++)
            {
                if (grid[r][c] > max)
                {
                    max = grid[r][c];
                }
            }
            
            for (int r = 0; r < row; r++)
            {
                if (newGrid[r][c] > max)
                {
                    newGrid[r][c] = max;
                }
            }
        }
        
        // accumulate the differences
        int ret = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                ret = ret + newGrid[r][c] - grid[r][c];
            }
        }
        
        return ret;
    }
};

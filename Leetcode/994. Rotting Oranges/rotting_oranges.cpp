// Leetcode 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/
// 
// 

class Solution 
{
public:
    void rot(vector<vector<int>>& tbl, vector<vector<int>>& grid, int minute, int r, int c)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        if (r < 0 || r >= row || c < 0 || c >= col)
        {
            return;
        }
        
        if (grid[r][c] == 0)
        {
            return;
        }
        
        if (minute < tbl[r][c])
        {
            tbl[r][c] = minute;
            rot(tbl, grid, minute + 1, r + 1, c);
            rot(tbl, grid, minute + 1, r - 1, c);
            rot(tbl, grid, minute + 1, r, c + 1);
            rot(tbl, grid, minute + 1, r, c - 1);
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> tbl(row, vector<int>(col, INT_MAX));
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 2)
                {
                    rot(tbl, grid, 0, r, c);
                }
            }
        }
        
        int minimumMinutes = INT_MIN;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] != 0 && tbl[r][c] > minimumMinutes)
                {
                    minimumMinutes = tbl[r][c];
                }
            }
        }
        
        // there is still remaining refresh orange
        if (minimumMinutes == INT_MAX)
        {
            minimumMinutes = -1;
        }
        
        // nothing happen
        if (minimumMinutes == INT_MIN)
        {
            minimumMinutes = 0;
        }
        
        return minimumMinutes; 
    }
};

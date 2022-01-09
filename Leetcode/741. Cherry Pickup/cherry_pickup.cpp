// Leetcode 741. Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/
// time complexity: O(pow(n, 3))
// space complexity: O(pow(n, 4)), n = row of matrix

// similar to cherry pickup II
class Solution
{
public:
    int pickup(const vector<vector<int>>& grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>>& tbl)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        if (r1 < 0 || r1 >= row || r2 < 0 || r2 >= row || c1 < 0 || c1 >= col || c2 < 0 || c2 >= col)
        {
            return INT_MIN;
        }
        
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        
        if (r1 == row - 1 && c1 == col - 1)
        {
            return grid[r1][c1];
        }
        
        if (r2 == row - 1 && c2 == col - 1)
        {
            return grid[r2][c2];
        }
        
        if (tbl[r1][c1][r2][c2] != -1)
        {
            return tbl[r1][c1][r2][c2];
        }
        
        int result = 0;

        if (r1 == r2 && c1 == c2)
        {
            result += grid[r1][c1];
        }
        else
        {
            result += grid[r1][c1] + grid[r2][c2];
        }
        
        int a = pickup(grid, r1 + 1, c1, r2 + 1, c2, tbl);
        int b = pickup(grid, r1 + 1, c1, r2, c2 + 1, tbl);
        int c = pickup(grid, r1, c1 + 1, r2 + 1, c2, tbl);
        int d = pickup(grid, r1, c1 + 1, r2, c2 + 1, tbl);
        
        result += max({a,b,c,d});
        tbl[r1][c1][r2][c2] = result;
        return result;
    }
    
    int cherryPickup(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<vector<vector<int>>>> tbl(row, vector<vector<vector<int>>>(col, vector<vector<int>>(row, vector<int>(col, -1))));
        
        int res = pickup(grid, 0, 0, 0, 0, tbl);
        
        return max(0, res);
    }
};

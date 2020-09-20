// Leetcode 980. Unique Paths III
// https://leetcode.com/problems/unique-paths-iii/

class Solution 
{
public:
    bool check(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (!visited[r][c] && grid[r][c] == 0)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void run(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int& path)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        {
            return;
        }
        
        if (grid[row][col] == -1 || visited[row][col])
        {
            return;
        }
        
        if (grid[row][col] == 2)
        {
            if (check(grid, visited, row, col))
            {
                path += 1;
            }
            
            return;
        }
        
        visited[row][col] = true;
        
        run(grid, visited, row + 1, col, path);
        run(grid, visited, row - 1, col, path);
        run(grid, visited, row, col + 1, path);
        run(grid, visited, row, col - 1, path);
        
        visited[row][col] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        int r1, c1;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    r1 = r;
                    c1 = c;
                    break;
                }
            }
        }
        
        int result = 0;
        run(grid, visited, r1, c1, result);
        
        return result;
    }
};

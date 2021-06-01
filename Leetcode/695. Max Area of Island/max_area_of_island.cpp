// Leetcode 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/
// time complexity: O(n), n = row * col
// space complexity: O(n)

// DFS
class Solution 
{
public:
    void bfs(vector<vector<int>>& grid, int& maxArea, vector<vector<bool>>& visited, int row, int col, int currentRow, int currentCol, int& lastArea)
    {
        if (currentRow < 0 || currentRow >= row || currentCol < 0 || currentCol >= col)
        {
            return;
        }
        
        if (visited[currentRow][currentCol])
        {
            return;
        }        
        
        if (grid[currentRow][currentCol] == 0)
        {
            return;
        }
        
        visited[currentRow][currentCol] = true;
        
        lastArea += 1;
        
        bfs(grid, maxArea, visited, row, col, currentRow + 1, currentCol, lastArea);
        bfs(grid, maxArea, visited, row, col, currentRow, currentCol + 1, lastArea);
        bfs(grid, maxArea, visited, row, col, currentRow - 1, currentCol, lastArea);
        bfs(grid, maxArea, visited, row, col, currentRow, currentCol - 1, lastArea);
        
        maxArea = max(maxArea, lastArea);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        int result = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int lastArea = 0;
                if (grid[r][c] == 1 && !visited[r][c])
                {
                    bfs(grid, result, visited, row, col, r, c, lastArea);
                }
            }
        }
        
        return result;
    }
};

// Leetcode 1020. Number of Enclaves
// https://leetcode.com/problems/number-of-enclaves/description/
// time complexity: O(NxN)
// space complexity: O(NxN)

// Sum up the number of grid with 1.
// For 4 edges, calculate the number of grid which could be reached.
// Then take it out from the sum.
class Solution
{
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    result++;
                }
            }
        }   

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        // top row
        for (int c = 0; c < col; c++)
        {
            if (grid[0][c] == 1)
            {
                result -= go(grid, visited, 0, c);
            }        
        }

        // bottom row
        for (int c = 0; c < col; c++)
        {
            if (grid[row - 1][c] == 1)
            {
                result -= go(grid, visited, row - 1, c);
            }        
        }

        // left column
        for (int r = 0; r < row; r++)
        {
            if (grid[r][0] == 1)
            {
                result -= go(grid, visited, r, 0);
            }
        }

        // right column
        for (int r = 0; r < row; r++)
        {
            if (grid[r][col - 1] == 1)
            {
                result -= go(grid, visited, r, col - 1);
            }
        }

        return result;
    }

    int go(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
        {
            return 0;
        }

        if (visited[row][col] || grid[row][col] == 0)
        {
            return 0;
        }

        visited[row][col] = true;

        int left = go(grid, visited, row, col - 1);
        int top = go(grid, visited, row - 1, col);
        int right = go(grid, visited, row, col + 1);
        int bottom = go(grid, visited, row + 1, col);

        return left + top + right + bottom + 1;

    }
};

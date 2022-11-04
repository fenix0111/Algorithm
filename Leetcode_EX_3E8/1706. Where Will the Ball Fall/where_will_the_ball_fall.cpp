// Leetcode 1706. Where Will the Ball Fall
// https://leetcode.com/problems/where-will-the-ball-fall/
// time complexity: O(n)
// space complexity: O(1)

// using simulation
class Solution
{
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> result(col, -1);
        
        if (col == 1)
        {
            return result;
        }
        
        for (int i = 0; i < col; i++)
        {
            int r = 0;
            int c = i;
            while (r >= 0 && r <= row && c >= 0 && c < col)
            {
                if (r == row)
                {
                    result[i] = c;
                    break;
                }
                
                if (c == col - 1 && grid[r][c - 1] == 1)
                {
                    // stuck in the right
                    break;
                }
                
                if (c == 0 && grid[r][c + 1] == -1)
                {
                    break;
                }
                
                if (grid[r][c] == 1 && c < col - 1 && grid[r][c + 1] == grid[r][c])
                {
                    // go to right
                    r++;
                    c++;
                    continue;
                }
                
                if (grid[r][c] == -1 && c > 0 && grid[r][c - 1] == grid[r][c])
                {
                    // go to left
                    r++;
                    c--;
                    continue;
                }
                
                if (c < col - 1 && grid[r][c] != grid[r][c + 1])
                {
                    break;
                }
                
                if (c > 0 && grid[r][c] != grid[r][c - 1])
                {
                    break;
                }
            }
        }
        
        return result;
    }
};

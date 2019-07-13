// Leetcode 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/
// Runtime: 68ms

// perimeter of one "land" is equal to the number of "water" surrrounding it
// take care of boundary
class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int water_around = 0;
                if (grid[r][c] == 1)
                {
                    if (r == 0)
                    {
                        water_around++;
                    }
                    
                    if (r == row - 1)
                    {
                        water_around++;
                    }
                    
                    if (c == 0)
                    {
                        water_around++;
                    }
                    
                    if (c == col - 1)
                    {
                        water_around++;
                    }
                    
                    if (r < row - 1 && grid[r + 1][c] == 0)
                    {
                        water_around++;
                    }
                    
                    if (r > 0 && grid[r - 1][c] == 0)
                    {
                        water_around++;
                    }
                    
                    if (c < col - 1 && grid[r][c + 1] == 0)
                    {
                        water_around++;
                    }
                    
                    if (c > 0 && grid[r][c - 1] == 0)
                    {
                        water_around++;
                    }
                }
                
                perimeter += water_around;
            }
        }
        
        return perimeter;
    }
};

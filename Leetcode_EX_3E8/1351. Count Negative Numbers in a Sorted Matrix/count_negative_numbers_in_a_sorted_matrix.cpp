// Leetcode 1351. Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// time complexity: O(row + col)
// space complexity: O(1)

class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        int r = 0;
        int c = col - 1;
        while (r < row)
        {
            while (c >= 0 && grid[r][c] < 0)
            {
                c--;
            }
            
            result += (col - c - 1);
            r++;
        }
        
        return result;
    }
};

// time complexity: O(row + col)
// space complexity: O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int r = 0;
        int c = col - 1;
        
        while (r < row && c >= 0)
        {
            if (target > matrix[r][c])
            {
                r++;
            }
            else if (target < matrix[r][c])
            {
                c--;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};

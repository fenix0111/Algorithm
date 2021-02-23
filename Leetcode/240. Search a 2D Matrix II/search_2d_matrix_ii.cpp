// more efficient solution

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        if (row == 0)
        {
            return false;
        }
        int col = matrix[0].size();
        
        int r = 0;
        int c = col - 1;
        
        // resemble binary search tree traversal
        while (r < row && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        
        return false;
    }
};

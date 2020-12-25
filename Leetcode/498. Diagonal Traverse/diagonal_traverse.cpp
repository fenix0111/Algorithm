// Leetcode 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/
// time complexity: O(n) --> row x column
// space complexity: O(1)

class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        int maxrow = matrix.size();
        if (maxrow == 0)
        {
            return vector<int>();
        }
        int maxcol = matrix[0].size();
        int sz = maxrow * maxcol;
        
        int count = 0;
        vector<int> result(sz, 0);
        int row = 0;
        int col = 0;
        bool NE = true; // to the north east direction
        while (count < sz)
        {
            result[count++] = matrix[row][col];
            
            if (NE)
            {
                if (row == 0 || col == maxcol - 1)
                {
                    NE = false;
                    if (row == 0 && col == maxcol - 1)
                    {
                        row++;
                        continue;
                    }
                    
                    if (row == 0)
                    {
                        col++;
                        continue;
                    }
                    
                    if (col == maxcol - 1)
                    {
                        row++;
                        continue;
                    }
                }
                else
                {
                    row--;
                    col++;
                }
            }
            else
            {
                if (row == maxrow - 1 || col == 0)
                {
                    NE = true;
                    if (row == maxrow - 1 && col == 0)
                    {
                        col++;
                        continue;
                    }
                    
                    if (row == maxrow - 1)
                    {
                        col++;
                        continue;
                    }
                    
                    if (col == 0)
                    {
                        row++;
                        continue;
                    }
                }
                else
                {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};

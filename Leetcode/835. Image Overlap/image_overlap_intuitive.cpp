// Leetcode 835. Image Overlap
// https://leetcode.com/problems/image-overlap/
// time complexity: O(pow(size of matrix, 2))
// space complexity: O(size of matrix)

class Solution 
{
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        int row = A.size();
        int col = A[0].size();
        
        int nr = 1;
        int nc = 1;
        vector<vector<int>> v(row, vector<int>(col, 0));
        int maxOverlap = INT_MIN;
        
        // go right & down
        for (int nr = 0; nr < row; nr++)
        {
            // reset
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    v[r][c] = 0;
                }
            }
            
            for (int nc = 0; nc < col; nc++)
            {
                // reset
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        v[r][c] = 0;
                    }
                }
                
                // copy
                for (int r = 0; r < row - nr; r++)
                {                    
                    for (int c = 0; c < col - nc; c++)
                    {
                        v[r + nr][c + nc] = A[r][c];
                    }
                }
                                
                // compare
                int overlap = 0;
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        if (v[r][c] == 1 && B[r][c] == 1)
                        {
                            overlap++;
                        }
                    }
                }
                
                if (overlap > maxOverlap)
                {
                    maxOverlap = overlap;
                }
            }
        }
        
        // go left & up
        for (int nr = 0; nr < row; nr++)
        {
            // reset
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    v[r][c] = 0;
                }
            }
            
            for (int nc = 0; nc < col; nc++)
            {
                // reset
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        v[r][c] = 0;
                    }
                }
                
                // copy
                for (int r = 0; r < row - nr; r++)
                {                    
                    for (int c = 0; c < col - nc; c++)
                    {
                        v[r][c] = A[r + nr][c + nc];
                    }
                }
                
                // compare
                int overlap = 0;
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        if (v[r][c] == 1 && B[r][c] == 1)
                        {
                            overlap++;
                        }
                    }
                }
                
                if (overlap > maxOverlap)
                {
                    maxOverlap = overlap;
                }
            }
        }
        
        return maxOverlap;
    }
};

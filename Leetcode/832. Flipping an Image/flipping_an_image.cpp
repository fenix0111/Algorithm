// Leetcode 832. Flipping an Image
// https://leetcode.com/problems/flipping-an-image/
// Runtime: 8ms

class Solution 
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        int row = A.size();
        int col = A[0].size();
        
        for (int r = 0; r < row; r++)
        {
            int beg = 0;
            int end = col - 1;
            while (beg < end)
            {
                int tmp = A[r][beg];
                A[r][beg] = A[r][end];
                A[r][end] = tmp;
                
                beg++;
                end--;
            }
            
            for (int c = 0; c < col; c++)
            {
                if (A[r][c] == 1)
                    A[r][c] = 0;
                else
                    A[r][c] = 1;
            }
        }
        
        return A;
    }
};

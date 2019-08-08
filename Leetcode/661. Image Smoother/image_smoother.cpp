// Leetcode 661. Image Smoother
// https://leetcode.com/problems/image-smoother/
// Runtime: 144ms

class Solution 
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
    {
        vector< vector<int> > ret;
        int row = M.size();
        if (row == 0)
            return ret;
        
        int col = M[0].size();
        int count = 1;
        int sum = 0;
        
        for (int r = 0; r < row; r++)
        {
            vector<int> v(col, 0);
            for (int c = 0; c < col; c++)
            {
                count = 1;
                sum = M[r][c];
                
                if (r - 1 >= 0 && c - 1 >= 0) // top-left
                {
                    sum += M[r - 1][c - 1];
                    count++;
                }
                
                if (r - 1 >= 0)  // top
                {
                    sum += M[r - 1][c];
                    count++;
                }
                
                if (r + 1 < row && c - 1 >= 0) // left-bottom
                {
                    sum += M[r + 1][c - 1];
                    count++;
                }
                
                if (c - 1 >= 0) // left
                {
                    sum += M[r][c - 1];
                    count++;
                }
                
                if (r + 1 < row && c + 1 < col) // right-bottom
                {
                    sum += M[r + 1][c + 1];
                    count++;
                }
                
                if (r + 1 < row) // bottom
                {
                    sum += M[r + 1][c];
                    count++;
                }
                
                if (r - 1 >= 0 && c + 1 < col) // top-right
                {
                    sum += M[r - 1][c + 1];
                    count++;
                }
                
                if (c + 1 < col)  // right
                {
                    sum += M[r][c + 1];
                    count++;
                }
                
                v[c] = sum / count;
            }
            
            ret.push_back(v);
        }
        
        return ret;
    }
};

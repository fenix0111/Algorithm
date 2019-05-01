// Leetcode 304. Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Runtime: 32ms

// similar to 1D version of Range Sum Query
// flattened 2D look-up table to avoid memory allocations in the for-loop
class NumMatrix 
{
private:
    int *tbl = NULL;
    int row_pad = 0; // same as column size
    
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int rsz = matrix.size();
        if (rsz > 0)
        {
            int csz = matrix[0].size();
            row_pad = csz;
        
            if (csz > 0)
            {
                tbl = (int*)malloc(sizeof(int) * (rsz * csz));

                for (int i = 0; i < rsz; i++)
                {
                    tbl[i * row_pad] = matrix[i][0];
                    for (int j = 1; j < csz; j++)
                    {
                        tbl[i * row_pad + j] = tbl[i * row_pad + j - 1] + matrix[i][j];
                    }
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int ret = 0;
        
        for (int i = row1; i <= row2; i++)
        {
            if(col1 == 0)
            {
                ret += tbl[i * row_pad + col2];
            }
            else
            {
                ret += tbl[i * row_pad + col2] - tbl[i * row_pad + col1 - 1];
            }
        }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

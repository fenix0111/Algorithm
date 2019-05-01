// Leetcode 304. Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Runtime: 32ms

// similar to 1D version of Range Sum Query
class NumMatrix 
{
private:
    int **tbl = NULL;
    
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int rsz = matrix.size();
        if (rsz > 0)
        {
            int csz = matrix[0].size();
            if (csz > 0)
            {
                tbl = (int**)malloc(sizeof(int*) * rsz);
                for (int i = 0; i < rsz; i++)
                {
                    tbl[i] = (int*)malloc(sizeof(int) * csz);
                }

                for (int i = 0; i < rsz; i++)
                {
                    tbl[i][0] = matrix[i][0];
                    for (int j = 1; j < csz; j++)
                    {
                        tbl[i][j] = tbl[i][j - 1] + matrix[i][j];
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
                ret += tbl[i][col2];
            }
            else
            {
                ret += (tbl[i][col2] - tbl[i][col1 - 1]);
            }
        }
        return ret;
    }
};

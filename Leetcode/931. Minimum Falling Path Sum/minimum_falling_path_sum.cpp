// Leetcode 931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/
// Runtime: 16ms

class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        int sz = A.size();
        int **tbl = (int**)malloc(sizeof(int*) * sz);
        for (int i = 0; i < sz; i++)
        {
            tbl[i] = (int*)malloc(sizeof(int) * sz);
            for (int j = 0; j < sz; j++)
            {
                tbl[i][j] = INT_MAX;
            }
        }
        
        for (int c = 0; c < sz; c++)
        {
            tbl[0][c] = A[0][c];
        }
        
        for (int r = 1; r < sz; r++)
        {
            for (int c = 0; c < sz; c++)
            {
                if (A[r][c] + tbl[r - 1][c] < tbl[r][c])
                {
                    tbl[r][c] = A[r][c] + tbl[r - 1][c];
                }
                
                if (c == 0)
                {
                    if (A[r][c + 1] + tbl[r - 1][c] < tbl[r][c + 1])
                    {
                        tbl[r][c + 1] = A[r][c + 1] + tbl[r - 1][c];
                    }
                }
                else if (c == sz - 1)
                {
                    if (A[r][c - 1] + tbl[r - 1][c] < tbl[r][c - 1])
                    {
                        tbl[r][c - 1] = A[r][c - 1] + tbl[r - 1][c];
                    }
                }
                else
                {
                    if (A[r][c + 1] + tbl[r - 1][c] < tbl[r][c + 1])
                    {
                        tbl[r][c + 1] = A[r][c + 1] + tbl[r - 1][c];
                    }
                    if (A[r][c - 1] + tbl[r - 1][c] < tbl[r][c - 1])
                    {
                        tbl[r][c - 1] = A[r][c - 1] + tbl[r - 1][c];
                    }
                }
            }
        }
        
        int min = INT_MAX;
        for (int c = 0; c < sz; c++)
        {
            if (tbl[sz - 1][c] < min)
                min = tbl[sz - 1][c];
        }
        
        return min;
    }
};

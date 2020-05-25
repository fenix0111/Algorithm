// Leetcode 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/
// time complexity: O(sizeA * sizeB)
// space complexity: O(sizeA * sizeB)

class Solution {
public:        
    int maxUncrossedLines(vector<int>& A, vector<int>& B) 
    {
        int row = A.size();
        int col = B.size();
        int **tbl = (int**)malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++)
        {
            tbl[i] = (int*)malloc(sizeof(int) * col);
        }
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (A[r] == B[c])
                {
                    tbl[r][c] = 1;
                }
                else
                {
                    tbl[r][c] = 0;
                }
            }
        }
        
        for (int r = 1; r < row; r++)
        {
            if (tbl[r][0] == 0)
                tbl[r][0] = tbl[r - 1][0];
        }
        
        for (int c = 1; c < col; c++)
        {
            if (tbl[0][c] == 0)
                tbl[0][c] = tbl[0][c - 1];
        }
        
        for (int r = 1; r < row; r++)
        {
            for (int c = 1; c < col; c++)
            {
                if (tbl[r][c] == 1)
                {
                    tbl[r][c] = min(tbl[r - 1][c - 1], min(tbl[r][c - 1], tbl[r - 1][c])) + 1;
                }
                else
                {
                    tbl[r][c] = max(tbl[r - 1][c - 1], max(tbl[r][c - 1], tbl[r - 1][c]));
                }
            }
        }
    
        return tbl[row - 1][col - 1];
    }
};

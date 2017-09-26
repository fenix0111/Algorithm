// Leetcode 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/description/
// Runtime: 3ms

// DP格子三部曲最后一题
// 主要思想是当前为止最小和是当前值与上一个最小值的和
// 按着这个思路填充一遍辅助矩阵
int minPathSum(int** grid, int gridRowSize, int gridColSize) 
{
    int** t = (int**)malloc(sizeof(int*) * gridRowSize);
    for (int i = 0; i < gridRowSize; i++)
    {
        t[i] = (int*)malloc(sizeof(int) * gridColSize);
    }

    for (int i = 0; i < gridRowSize; i++)
    {
        if (i == 0)
            t[i][0] = grid[i][0];
        else
            t[i][0] = grid[i][0] + t[i - 1][0];
    }
    
    for (int i = 0; i < gridColSize; i++)
    {
        if (i == 0)
            t[0][i] = grid[0][i];
        else
            t[0][i] = grid[0][i] + t[0][i - 1];
    }

    int top = 0;
    int left = 0;
    int cur = 0;
    for (int i = 1; i < gridRowSize; i++)
    {
        for (int j = 1; j < gridColSize; j++)
        {
            top = t[i - 1][j];
            left = t[i][j - 1];
            cur = grid[i][j];
            if (top > left)
                t[i][j] = cur + left;
            else
                t[i][j] = cur + top;
        }
    }

    return t[gridRowSize - 1][gridColSize - 1];
}

// Leetcode 62. Unique Paths
// https://leetcode.com/problems/unique-paths/description/
// Runtime: 0ms

// 动态规划题
// 这道题还有后面两道类似的格子题能用填充矩阵解决的大前提就是"每次只能向右或向下移动"
// 要是能自由移动就变成图相关问题了
int uniquePaths(int m, int n) 
{
    int** t = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++)
    {
        t[i] = (int*)malloc(sizeof(int) * n);
    }
    
    for (int i = 0; i < m; i++) 
    {
        t[i][0] = 1;
    }

    for (int i = 0; i < n; i++) 
    {
        t[0][i] = 1;
    }

    for (int i = 1; i < m; i++) 
    {
        for (int j = 1; j < n; j++) 
        {
            t[i][j] = t[i - 1][j] + t[i][j - 1];
        }
    }

    return t[m - 1][n - 1];
}

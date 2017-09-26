// Leetcode 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/description/
// Runtime: 0ms

// 62题的一个变种但主要思路不变
// 不能对有障碍物的格子进行计算
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) 
{
    int** t = (int**)malloc(sizeof(int*) * obstacleGridRowSize);
    for (int i = 0; i < obstacleGridRowSize; i++)
	{
        t[i] = (int*)malloc(sizeof(int) * obstacleGridColSize);
        
        // 为了日后方便先把所有内存值初始化为0
        memset(t[i], 0, sizeof(int) * obstacleGridColSize);
    }

    // 对第一行和第一列, 若有障碍物则障碍物之后的格子不能初始化(因为走不通)
    for (int i = 0; i < obstacleGridRowSize; i++)
    {
        if (obstacleGrid[i][0] == 1)
            break;
        t[i][0] = 1;
    }

    for (int i = 0; i < obstacleGridColSize; i++)
    {
        if (obstacleGrid[0][i] == 1)
            break;
        t[0][i] = 1;
    }

    for (int i = 1; i < obstacleGridRowSize; i++)
    {
        for (int j = 1; j < obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j] == 0)
                t[i][j] = t[i - 1][j] + t[i][j - 1];
        }
    }

    return t[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}

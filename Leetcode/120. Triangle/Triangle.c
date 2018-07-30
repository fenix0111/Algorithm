// Leetcode 120. Triangle
// https://leetcode.com/problems/triangle/description/
// Runtime: 3ms

// 动态规划题。反正只要求给最小值所以不用每条线路都遍历一遍。
// current_min = last_min + previous_min
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    if (triangleRowSize == 1)
        return triangle[0][0];
    
    // 辅助空间保存各地点的最小值
    int **tmp = (int**)malloc(sizeof(int*) * triangleRowSize);
    for (int i = 0; i < triangleRowSize; i++)
    {
        tmp[i] = (int*)malloc(sizeof(int) * triangleColSizes[i]);
    }
    
    tmp[0][0] = triangle[0][0];
    for (int row = 1; row < triangleRowSize; row++)
    {
        for (int col = 1; col < triangleColSizes[row] - 1; col++)
        {
            int ll = tmp[row - 1][col];
            int rr = tmp[row - 1][col - 1];
            int t = 0;
            if (ll > rr)
                t = rr;
            else
                t = ll;
            tmp[row][col] = t + triangle[row][col];
        }
        
        // 每一行第一个和最后一个值只受影响于上一行的对应位置的值
        tmp[row][0] = tmp[row - 1][0] + triangle[row][0];
        int last = triangleColSizes[row] - 1;
        tmp[row][last] = tmp[row - 1][last - 1] + triangle[row][last];
    }
    
    // 在辅助数组最后一行找最小值(用qsort是否会更快一些?)
    int min = INT_MAX;
    for (int i = 0; i < triangleColSizes[triangleRowSize - 1]; i++)
    {
        if (tmp[triangleRowSize - 1][i] < min)
            min = tmp[triangleRowSize - 1][i];
    }
    
    return min;
}

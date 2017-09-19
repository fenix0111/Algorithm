// Leetcode 120. Triangle
// https://leetcode.com/problems/triangle/description/
// Runtime: 3ms

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes)
{
    if (triangleRowSize == 1)
        return triangle[0][0];
    
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
        
        tmp[row][0] = tmp[row - 1][0] + triangle[row][0];
        int last = triangleColSizes[row] - 1;
        tmp[row][last] = tmp[row - 1][last - 1] + triangle[row][last];
    }
    
    
    int min = INT_MAX;
    for (int i = 0; i < triangleColSizes[triangleRowSize - 1]; i++)
    {
        if (tmp[triangleRowSize - 1][i] < min)
            min = tmp[triangleRowSize - 1][i];
    }
    
    return min;
}

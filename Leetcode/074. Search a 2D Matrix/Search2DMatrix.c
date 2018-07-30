// Leetcode 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/
// Runtime: 3ms

// 对第一列元素进行二分查找。之后对所在行进行二分查找
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    if (matrixColSize == 0)
        return false;

    int row = -1;
    int start = 0;
    int end = matrixRowSize - 1;
    int mid = 0;

    // 对第一列元素进行二分查找
    while (start < end)
    {
        mid = start + (end - start) / 2;
        int t = matrix[mid][0];
        if (target < t)
            end = mid - 1;
        else if (target > t)
            start = mid + 1;
        else if (target == t)
            // find it!
            return true;
    }

    // 当start等于end时退出循环
    // 判断start行第一个元素与target大小关系。
    if (matrix[start][0] > target)
        row = start - 1;
    else if (matrix[start][0] < target)
        row = start;
    else
        return true;

    // 当target比第一行第一个元素小的时候row会变成负数
    if (row < 0)
        return false;
    
    start = 0;
    end = matrixColSize - 1;
    mid = 0;
    
    // 对所在行进行二分查找
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int t = matrix[row][mid];
        if (target < t)
            end = mid - 1;
        else if (target > t)
            start = mid + 1;
        else if (target == t)
            // find it!
            return true;
    }
    return false;
}

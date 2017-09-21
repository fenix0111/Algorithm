// Leetcode 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/
// Runtime: 3ms

// 对第一列元素进行二分查找。之后对所在行进行二分查找
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) 
{
    if (matrixColSize == 0)
        return false;

    // 这部分对第一列做搜索的可以再优化成二分查找
    int row = -1;
    for (int i = 0; i < matrixRowSize; i++)
    {
        if (i == 0)
        {
            if (matrix[i][0] > target)
                return false;
            else if (matrix[i][0] == target)
                return true;
        }
        else
        {
            if (matrix[i][0] > target)
            {
                row = i - 1;
                break;
            }
            else if (matrix[i][0] == target)
            {
                return true;
            }
        }
    }
	
    if (row == -1)
        row = matrixRowSize - 1;
	
    int start = 0;
    int end = matrixColSize - 1;
    int mid = 0;

    // search in the row
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

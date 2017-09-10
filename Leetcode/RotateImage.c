// Leetcode 48. Rotate Image
// https://leetcode.com/problems/rotate-image/description/
// Runtime: 3ms

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int l = 0;
    int r = matrixColSize - 1;
    int ref = 0;
    
    while (l < r)
    {
        for(int i = 0; i < r - l; i++)
        {
            ref = matrix[l][l + i];
            swap(&ref, &matrix[l + i][r]);
            swap(&ref, &matrix[r][r - i]);
            swap(&ref, &matrix[r - i][l]);
            swap(&ref, &matrix[l][l + i]);
        }
        l++;
        r--;
    }
}

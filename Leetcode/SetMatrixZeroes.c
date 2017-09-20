// Leetcode 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/description/
// Runtime: 19ms

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
    // 临时数组
    int **col = (int**)malloc(sizeof(int*) * matrixRowSize);
    for (int r = 0; r < matrixRowSize; r++)
    {
        int zeroes = 0;
        for (int c = 0; c < matrixColSize; c++)
        {
            if (matrix[r][c] == 0)
                zeroes++;
        }
        col[r] = (int*)malloc(sizeof(int) * (zeroes + 1));
        col[r][0] = zeroes; // 每行第一列元素保存该行列数
        if (zeroes == 0)
            continue;

        int ci = 1;
        for (int c = 0; c < matrixColSize; c++)
        {
            if (matrix[r][c] == 0)
            {
                col[r][ci] = c;
                ci++;
            }
        }
    }

    for (int r = 0; r < matrixRowSize; r++)
    {
        bool haszero = false;
        for (int c = 1; c <= col[r][0]; c++)
        {
            // 设bool值使得每行只需置零一次。否则每次循环都会反复置零
            if (col[r][0] > 0)
                haszero = true;

            // zero the column
            // 感觉这里也可以优化,例如记录该列是否已被置零
            for (int rw = 0; rw < matrixRowSize; rw++)
                matrix[rw][col[r][c]] = 0;
        }

        if (haszero)
        {
            // zero the row
            for (int cl = 0; cl < matrixColSize; cl++)
                matrix[r][cl] = 0;
        }
    }

    // leetcode系统不强制要求free内存,但还是写上吧 :)
    free(col);
}

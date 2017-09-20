// Leetcode 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/description/
// Runtime: 19ms

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
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
		col[r][0] = zeroes; // first column stores colsize at that row
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
			if (col[r][0] > 0)
				haszero = true;

			// zero the column
			for (int rw = 0; rw < matrixRowSize; rw++)
			{
				matrix[rw][col[r][c]] = 0;
			}
		}

		if (haszero)
		{
			// zero the row
			for (int cl = 0; cl < matrixColSize; cl++)
			{
				matrix[r][cl] = 0;
			}
		}
	}

	free(col);
}

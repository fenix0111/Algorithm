// Leetcode 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/description/
// Runtime: 3ms

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) 
{
        int **res = (int**)malloc(sizeof(int*) * n);

		for (int i = 0; i < n; i++)
		{
			res[i] = (int*)malloc(sizeof(int) * n);
		}

		if (n == 1)
		{
			res[0][0] = 1;
			return res;
		}

		int horizontal_begin = 0;
		int horizontal_end = n - 1;
		int vertical_begin = 0;
		int vertical_end = n - 1;

		int round = 2 * n - 1;

		int num = 1;
		while (round >= 0)
		{
			// ->
			if (round >= 0)
			{
				for (int x = horizontal_begin; x <= horizontal_end; x++)
				{
					res[vertical_begin][x] = num;
					num++;
				}
				vertical_begin++;
				round--;
			}
			
			// |V
			if (round >= 0)
			{
				for (int y = vertical_begin; y <= vertical_end; y++)
				{
					res[y][horizontal_end] = num;
					num++;
				}
				horizontal_end--;
				round--;
			}
			
			// <-
			if (round >= 0)
			{
				for (int z = horizontal_end; z >= horizontal_begin; z--)
				{
					res[vertical_end][z] = num;
					num++;
				}
				vertical_end--;
				round--;
			}
			
			// |^
			if (round >= 0)
			{
				for (int w = vertical_end; w >= vertical_begin; w--)
				{
					res[w][horizontal_begin] = num;
					num++;
				}
				horizontal_begin++;
				round--;
			}
		}
		
		return res;
}

// 0ms参考解法
int** generateMatrix(int n) {
    int i, j;
    int rs, re, cs, ce;
    int **ret;
    int count = 0;
    
    rs = cs = 0;
    re = n - 1;
    ce = n - 1;
    
    ret = (int **)malloc(sizeof(int *)*n);
    for (i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int)*n);
    }
    for (i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            ret[i][j] = 0;
        }
    }
    
    while ((rs <= re) && (cs <= ce)) {
        for (i = cs; i <= ce; i++) {
            ret[rs][i] = count + 1;
            count++;
        }
        for (i = rs + 1; i <= re; i++) {
            ret[i][ce] = count + 1;
            count++;
        }
        if (re > rs) { 
            for (i = ce - 1; i >= cs; i--) {
                ret[re][i] = count + 1;
                count++;
            }
        }
        if (ce > cs) {
            for (i = re - 1; i > rs; i--) {
                ret[i][cs] = count + 1;
                count++;
            }
        }
        rs++;
        re--;
        cs++;
        ce--;
    }
    return ret;
}

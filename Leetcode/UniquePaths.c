// Leetcode 62. Unique Paths
// https://leetcode.com/problems/unique-paths/description/
// Runtime: 0ms

// 动态规划题
int uniquePaths(int m, int n) {
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

// Leetcode 62. Unique Paths
// https://leetcode.com/problems/unique-paths/description/
// Runtime: 1ms

// 动态规划题
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] tab = new int[m][n];
        for (int i = 0; i < m; i++) {
            tab[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            tab[0][i] = 1;
        }

        int res = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                tab[i][j] = tab[i - 1][j] + tab[i][j - 1];
            }
        }

        res = tab[m - 1][n - 1];
        return res;
    }
}

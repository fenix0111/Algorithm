// Leetcode 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/


class Solution
{
    int MOD = 1000000007;
public:
    int find(vector<vector<vector<int>>>& tbl, int& result, int m, int n, int maxMove, int move, int row, int col)
    {
        if (move > maxMove)
        {
            return 0;
        }
        
        if (row < 0 || row == m || col < 0 || col == n)
        {
            return 1;
        }
        
        if (tbl[row][col][move] != -1)
            return tbl[row][col][move];
        
        int res = 0;
        res += find(tbl, result, m, n, maxMove, move + 1, row + 1, col);
        res %= MOD;
        res += find(tbl, result, m, n, maxMove, move + 1, row, col + 1);
        res %= MOD;
        res += find(tbl, result, m, n, maxMove, move + 1, row - 1, col);
        res %= MOD;
        res += find(tbl, result, m, n, maxMove, move + 1, row, col - 1);
        tbl[row][col][move] = (res % MOD);
        return tbl[row][col][move];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        int result = 0;
        vector<vector<vector<int>>> tbl(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return find(tbl, result, m, n, maxMove, 0, startRow, startColumn);
    }
};

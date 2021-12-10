// Leetcode 790. Domino and Tromino Tiling
// https://leetcode.com/problems/domino-and-tromino-tiling/
// time complexity: O(n)
// space complexity: O(n)

// greate explanation: https://youtu.be/yn2jnmlepY8
class Solution
{
public:
    int numTilings(int n)
    {
        vector<vector<int>> tbl(n + 1, vector<int>(4, 0));
        tbl[0][3] = 1;
        int MOD = 1000000007; // really hate this guy
        
        // [ ] [X] [ ] [X]
        // [ ] [ ] [X] [X]
        //  0   1   2   3
        for (int i = 1; i <= n; i++)
        {
            tbl[i][0] += (tbl[i - 1][3]);
            tbl[i][0] %= MOD;
            
            tbl[i][1] += (tbl[i - 1][0]);
            tbl[i][1] %= MOD;
            tbl[i][1] += (tbl[i - 1][2]);
            tbl[i][1] %= MOD;
            
            tbl[i][2] += (tbl[i - 1][0]);
            tbl[i][2] %= MOD;
            tbl[i][2] += (tbl[i - 1][1]);
            tbl[i][2] %= MOD;
            
            tbl[i][3] += (tbl[i - 1][0]);
            tbl[i][3] %= MOD;
            tbl[i][3] += (tbl[i - 1][1]);
            tbl[i][3] %= MOD;
            tbl[i][3] += (tbl[i - 1][2]);
            tbl[i][3] %= MOD;
            tbl[i][3] += (tbl[i - 1][3]);
            tbl[i][3] %= MOD;
        }
        
        return tbl[n][3] % MOD;
    }
};

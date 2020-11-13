// Leetcode 51. N-Queens
// https://leetcode.com/problems/n-queens/
// time complexity: O(N!)
// space complexity: O(n*n)

class Solution 
{
public:
    void solve(vector<vector<string>>& result, vector<bool>& col, int n, int currentRow, vector<vector<bool>>& mat)
    {
        if (currentRow == n)
        {
            vector<string> res;
            for (int r = 0; r < n; r++)
            {
                string str = "";
                for (int c = 0; c < n; c++)
                {
                    if (mat[r][c])
                    {
                        str.push_back('Q');
                    }
                    else
                    {
                        str.push_back('.');
                    }
                }
                res.push_back(str);
            }
            result.push_back(res);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (!col[i])
            {
                // check diagonal
                bool is_valid = true;
                int tmprow = currentRow;
                int tmpcol = i;
                
                // diagonal top-left
                while (tmprow >= 0 && tmpcol >= 0)
                {
                    if (mat[tmprow][tmpcol])
                    {
                        is_valid = false;
                        break;
                    }
                    tmprow--;
                    tmpcol--;
                }
                if (!is_valid) continue;
                
                tmprow = currentRow;
                tmpcol = i;
                
                // diagonal top-right
                while (tmprow >= 0 && tmpcol < n)
                {
                    if (mat[tmprow][tmpcol])
                    {
                        is_valid = false;
                        break;
                    }
                    tmprow--;
                    tmpcol++;
                }
                
                if (!is_valid) continue;
                
                col[i] = true;
                mat[currentRow][i] = true;
                
                solve(result, col, n, currentRow + 1, mat);
                
                col[i] = false;
                mat[currentRow][i] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<bool> col(n, false);
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        vector<vector<string>> result;
        
        solve(result, col, n, 0, mat);
        
        return result;
    }
};

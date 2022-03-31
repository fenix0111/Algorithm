// Leetcode 1314. Matrix Block Sum
// https://leetcode.com/problems/matrix-block-sum/
// time complexity: O(row * col)
// space complexity: O(row * col)

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();
        
        int** buf = (int**)malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++)
        {
            buf[i] = (int*)malloc(sizeof(int) * col);
        }
        
        for (int r = 0; r < row; r++)
        {
            buf[r][0] = mat[r][0];
            for (int c = 1; c < col; c++)
            {
                buf[r][c] = mat[r][c] + buf[r][c - 1];
            }
        }
        
        vector<vector<int>> answer(row, vector<int>(col, 0));
        
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int rbegin = max(0, r - k);
                int rend = min(row - 1, r + k);
                int cbegin = max(0, c - k);
                int cend = min(col - 1, c + k);
                
                int sum = 0;
                for (int i = rbegin; i <= rend; i++)
                {
                    if (cbegin == 0)
                    {
                        sum += buf[i][cend];
                    }
                    else
                    {
                        sum += (buf[i][cend] - buf[i][cbegin - 1]);
                    }
                }
                
                answer[r][c] = sum;
            }
        }
        
        return answer;
    }
};

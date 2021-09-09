// Leetcode 764. Largest Plus Sign
// https://leetcode.com/problems/largest-plus-sign/
// time complexity: O(N), N = n * n 
// space complexity: O(N)

// Because the order is minimum arm length among four directions,
// therefore the minimum number of consecutive 1 in each direction need to be counted
class Solution 
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) 
    {
        vector<vector<int>> M(n, vector<int>(n, 1));
        vector<vector<int>> C(n, vector<int>(n, 0));
        int order = 0;
        for (auto& mine : mines)
        {
            M[mine[0]][mine[1]] = 0;
        }
        
        for (int r = 0; r < n; r++)
        {
            int count = 0;
            for (int c = 0; c < n; c++)
            {
                if (M[r][c] == 1)
                {
                    count++;
                    C[r][c] = count;
                }
                else
                {
                    count = 0;
                }
            }
            
            count = 0;
            for (int c = n - 1; c >= 0; c--)
            {
                if (M[r][c] == 1)
                {
                    count++;
                    C[r][c] = min(count, C[r][c]);
                }
                else
                {
                    count = 0;
                }
            }
        }
        
        for (int c = 0; c < n; c++)
        {
            int count = 0;
            for (int r = 0; r < n; r++)
            {
                if (M[r][c] == 1)
                {
                    count++;
                    C[r][c] = min(count, C[r][c]);
                }
                else
                {
                    count = 0;
                }
            }
            
            count = 0;
            for (int r = n - 1; r >= 0; r--)
            {
                if (M[r][c] == 1)
                {
                    count++;
                    C[r][c] = min(count, C[r][c]);
                    order = max(C[r][c], order);
                }
                else
                {
                    count = 0;
                }
            }
        }
        
        return order;
    }
};

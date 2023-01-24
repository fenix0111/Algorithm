// Leetcode 909. Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders/description/
// time complexity: O(n*n)
// space complexity: O(n*n)

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        unordered_map<int, vector<int>> M;
        int n = board.size();
        int r = n - 1;
        int c = 0;
        bool right = true;
        for (int i = 1; i <= n * n; i++)
        {
            M[i] = {r, c};
            if (right)
            {
                c++;
            }
            else
            {
                c--;
            }

            if (c < 0)
            {
                r--;
                c = 0;
                right = true;
            }
            else if (c >= n)
            {
                r--;
                c = n - 1;
                right = false;
            }
        }

        int result = 1;
        queue<int> q;
        q.push(1);
        vector<bool> visited(n * n, false);
        visited[0] = true;
        while (!q.empty())
        {
            int qsz = q.size();
            while (!q.empty() && qsz > 0)
            {
                qsz--;
                int curr = q.front();
                q.pop();
                int range_min = curr + 1;
                int range_max = min(curr + 6, n * n);

                if (range_max == n * n)
                {
                    return result;
                }

                for (int i = range_min; i <= range_max; i++)
                {
                    vector<int> coord = M[i];
                    int row = coord[0];
                    int col = coord[1];
                    int next = board[row][col];

                    if (next == n * n)
                    {
                        return result;
                    }

                    if (visited[i - 1])
                    {
                        continue;
                    }

                    visited[i - 1] = true;
                    if (next == -1)
                    {
                        q.push(i);
                    }
                    else
                    {
                        q.push(next);
                    }
                }
            }

            if (q.empty())
            {
                return -1;
            }

            result++;
        }

        return -1;
    }
};

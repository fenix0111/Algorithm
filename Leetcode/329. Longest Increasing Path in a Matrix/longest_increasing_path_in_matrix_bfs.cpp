// Leetcode 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// time complexity: ??
// space complexity: O(n)

class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int result = 0;
        vector<vector<int>> dist(row, vector<int>(col, 1));
        
        queue<pair<int,int>> q;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                q.push(make_pair(r, c));
                while (!q.empty())
                {
                    auto node = q.front();
                    q.pop();
                    int R = node.first;
                    int C = node.second;
                    int D = dist[R][C];
                    
                    int next_row, next_col;
                    
                    if (D > result)
                    {
                        result = D;
                    }
                    
                    next_row = R + 1;
                    next_col = C;
                    
                    if (next_row < row && matrix[next_row][next_col] > matrix[R][C] && dist[next_row][next_col] <= D)
                    {
                        dist[next_row][next_col] += 1;
                        q.push(make_pair(next_row, next_col));
                    }
                    
                    next_row = R - 1;
                    next_col = C;
                    if (next_row >= 0 && matrix[next_row][next_col] > matrix[R][C] && dist[next_row][next_col] <= D)
                    {
                        dist[next_row][next_col] += 1;
                        q.push(make_pair(next_row, next_col));
                    }
                    
                    next_row = R;
                    next_col = C + 1;
                    if (next_col < col && matrix[next_row][next_col] > matrix[R][C] && dist[next_row][next_col] <= D)
                    {
                        dist[next_row][next_col] += 1;
                        q.push(make_pair(next_row, next_col));
                    }
                    
                    next_row = R;
                    next_col = C - 1;
                    if (next_col >= 0 && matrix[next_row][next_col] > matrix[R][C] && dist[next_row][next_col] <= D)
                    {
                        dist[next_row][next_col] += 1;
                        q.push(make_pair(next_row, next_col));
                    }
                }
            }
        }
        
        return result;
    }
};

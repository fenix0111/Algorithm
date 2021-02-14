// Leetcode 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// time complexity: O(V*E) --> actually the number of edges could be considered as constant, as each cell can reach out to eight directions
// space complexity: O(V)

// using breadth-first search
class Solution 
{
public:
    void check(vector<vector<int>>& grid, vector<vector<int>>& dist)
    {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        dist[0][0] = 1;
        
        while (!q.empty())
        {
            int R = q.front().first;
            int C = q.front().second;
            int D = dist[R][C];
            q.pop();
            
            if (R + 1 >= 0 && R + 1 < row && C >= 0 && C < col && grid[R + 1][C] == 0 && D + 1 < dist[R + 1][C])
            {
                dist[R + 1][C] = D + 1;
                q.push(make_pair(R + 1, C));
            }
            
            if (R + 1 >= 0 && R + 1 < row && C + 1 >= 0 && C + 1 < col && grid[R + 1][C + 1] == 0 && D + 1 < dist[R + 1][C + 1])
            {
                dist[R + 1][C + 1] = D + 1;
                q.push(make_pair(R + 1, C + 1));
            }
            
            if (R + 1 >= 0 && R + 1 < row && C - 1 >= 0 && C - 1 < col && grid[R + 1][C - 1] == 0 && D + 1 < dist[R + 1][C - 1])
            {
                dist[R + 1][C - 1] = D + 1;
                q.push(make_pair(R + 1, C - 1));
            }
            
            if (R >= 0 && R < row && C + 1 >= 0 && C + 1 < col && grid[R][C + 1] == 0 && D + 1 < dist[R][C + 1])
            {
                dist[R][C + 1] = D + 1;
                q.push(make_pair(R, C + 1));
            }
            
            if (R >= 0 && R < row && C - 1 >= 0 && C - 1 < col && grid[R][C - 1] == 0 && D + 1 < dist[R][C - 1])
            {
                dist[R][C - 1] = D + 1;
                q.push(make_pair(R, C - 1));
            }
            
            if (R - 1 >= 0 && R - 1 < row && C >= 0 && C < col && grid[R - 1][C] == 0 && D + 1 < dist[R - 1][C])
            {
                dist[R - 1][C] = D + 1;
                q.push(make_pair(R - 1, C));
            }
            
            if (R - 1 >= 0 && R - 1 < row && C - 1 >= 0 && C - 1 < col && grid[R - 1][C - 1] == 0 && D + 1 < dist[R - 1][C - 1])
            {
                dist[R - 1][C - 1] = D + 1;
                q.push(make_pair(R - 1, C - 1));
            }
            
            if (R - 1 >= 0 && R - 1 < row && C + 1>= 0 && C + 1 < col && grid[R - 1][C + 1] == 0 && D + 1 < dist[R - 1][C + 1])
            {
                dist[R - 1][C + 1] = D + 1;
                q.push(make_pair(R - 1, C + 1));
            }
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid[0][0] == 1)
        {
            return -1;
        }
        
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        check(grid, dist);
        
        int result = dist[row - 1][col - 1];
        return result == INT_MAX ? -1 : result;
    }
};

// Leetcode 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/
// time complexity: O(n)
// space complexity: O(n)

// binary search + BFS
class Solution
{
public:
    bool reachEnd(const pair<int,int>& pos, int row , int col)
    {
        return (pos.first == row - 1) && (pos.second == col - 1);
    }
    
    bool isValid(const pair<int, int>& pos, int row, int col)
    {
        return (pos.first >= 0) && (pos.first < row) && 
               (pos.second >= 0) && (pos.second < col);
    }
    
    void reset(queue<pair<int,int>>& q, vector<vector<bool>>& visited, int row, int col)
    {
        while (!q.empty())
        {
            q.pop();
        }

        q.push({0, 0});
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                visited[i][j] = false;
            }
        }
        visited[0][0] = true;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int mindiff = INT_MAX;
        int maxdiff = 0;
        int row = heights.size();
        int col = heights[0].size();
        int result = INT_MAX;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (r > 0)
                {
                    mindiff = min(mindiff, abs(heights[r][c] - heights[r - 1][c]));
                    maxdiff = max(maxdiff, abs(heights[r][c] - heights[r - 1][c]));
                }
                
                if (c > 0)
                {
                    mindiff = min(mindiff, abs(heights[r][c] - heights[r][c - 1]));
                    maxdiff = max(maxdiff, abs(heights[r][c] - heights[r][c - 1]));
                }
                
                if (r < row - 1)
                {
                    mindiff = min(mindiff, abs(heights[r][c] - heights[r + 1][c]));
                    maxdiff = max(maxdiff, abs(heights[r][c] - heights[r + 1][c]));
                }
                
                if (c < col - 1)
                {
                    mindiff = min(mindiff, abs(heights[r][c] - heights[r][c + 1]));
                    maxdiff = max(maxdiff, abs(heights[r][c] - heights[r][c + 1]));
                }
            }
        }
        
        int mid = mindiff + (maxdiff - mindiff) / 2;
        int beg = mindiff;
        int end = maxdiff;
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pair<int,int> dir[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    
        while (beg <= end)
        {
            mid = beg + (end - beg) / 2;
            reset(q, visited, row, col);
            bool found = false;
            
            while (!q.empty())
            {
                pair<int,int>& pos = q.front();
                
                if (reachEnd(pos, row, col))
                {
                    found = true;
                    break;
                }
                
                for (int i = 0; i < 4; i++)
                {
                    pair<int,int> newPos = {pos.first + dir[i].first, pos.second + dir[i].second};
                    if (isValid(newPos, row, col) && !visited[newPos.first][newPos.second])
                    {
                        if (abs(heights[newPos.first][newPos.second] - heights[pos.first][pos.second]) <= mid)
                        {
                            q.push(newPos);
                            visited[newPos.first][newPos.second] = true;
                        }
                    }
                }
                
                q.pop();
            }
            
            if (!found)
            {
                beg = mid + 1;
            }
            else
            {
                result = min(mid, result);
                end = mid - 1;
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
};

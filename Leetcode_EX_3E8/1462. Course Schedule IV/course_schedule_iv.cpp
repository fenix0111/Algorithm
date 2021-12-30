// Leetcode 1462. Course Schedule IV
// https://leetcode.com/problems/course-schedule-iv/
// time complexity: O(ExV)
// space complexity: O(VxV)

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        unordered_map<int, unordered_set<int>> G;
        vector<vector<bool>> canReach(n, vector<bool>(n, false));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        for (vector<int>& p : prerequisites)
        {
            G[p[0]].insert(p[1]);
        }
        
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                if (!visited[i][node])
                {
                    visited[i][node] = true;
                    unordered_set<int>& neighbors = G[node];
                    for (auto it = neighbors.begin(); it != neighbors.end(); it++)
                    {
                        canReach[i][*it] = true;
                        q.push(*it);
                    }
                }
            }
        }

        vector<bool> ret;
        
        for (vector<int>& query : queries)
        {
            ret.push_back(canReach[query[0]][query[1]]);
        }
        
        return ret;
    }
};

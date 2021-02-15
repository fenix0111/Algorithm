// Leetcode 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/
// time complexity: O(V*E)
// space complexity: O(V)

class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int sz = graph.size();
        vector<char> state(sz, 0);

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            
            if (state[v] == 0)
            {
                state[v] = 1;
            }
            
            for (int n : graph[v])
            {
                if (state[v] == state[n])
                {
                    return false;
                }
                
                if (state[n] != 0) continue;
                
                if (state[v] == 1)
                {
                    state[n] = 2;
                }
                else
                {
                    state[n] = 1;
                }

                q.push(n);
            }
            
            // in case of isolated node
            if (q.empty())
            {
                if (v + 1 < sz)
                {
                    q.push(v + 1);
                }
            }
        }
        
        return true;
    }
};

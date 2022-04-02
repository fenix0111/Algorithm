// Leetcode 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/
// time complexity: O(E)
// space complexity: O(V)

class Solution
{
public:
    bool canReachTerminal(int node, const unordered_set<int>& terminalNodes, 
                          const vector<vector<int>>& graph, vector<bool>& canReach,
                          vector<bool>& visited)
    {
        if (terminalNodes.count(node))
        {
            return true;
        }
        
        if (visited[node])
        {
            return canReach[node];
        }
        
        visited[node] = true;
        
        if (canReach[node])
        {
            return true;
        }
        
        const vector<int>& neighbors = graph[node];
        bool reachable = true;
        for (int v : neighbors)
        {
            bool result = canReachTerminal(v, terminalNodes, graph, canReach, visited);
            reachable &= result;
        }
                
        canReach[node] = reachable;
        
        return reachable;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> result;
        unordered_set<int> terminalNodes;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 0)
            {
                terminalNodes.insert(i);
            }
        }
        
        vector<bool> canReach(n, false);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (canReachTerminal(i, terminalNodes, graph, canReach, visited))
            {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

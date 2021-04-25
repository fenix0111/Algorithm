// Leetcode 1192. Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network/
// time complexity: O(V + E), total vertices V , total edges E
// space complexity: O(n)

// refer to Tarjan's algorithm
class Solution 
{
public:    
    void dfs(vector<vector<int>>& result, 
             unordered_map<int, vector<int>>& G, 
             int index, 
             vector<int>& ids, 
             int& time, 
             vector<int>& low, 
             int parent)
    {
        ids[index] = time;
        low[index] = time;
        time += 1;
        
        vector<int>& neighbors = G[index];
        
        for (int neighbor : neighbors)
        {
            if (neighbor == parent)
            {
                continue;
            }
            
            if (ids[neighbor] == -1)
            {
                dfs(result, G, neighbor, ids, time, low, index);
                if (low[neighbor] > ids[index])
                {
                    result.push_back({neighbor, index});
                }
            }
            low[index] = min(low[neighbor], low[index]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> G;
        
        for (vector<int>& e : connections)
        {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        int time = 0;
        vector<int> ids(n, -1);
        vector<int> low(n, -1);
        
        dfs(result, G, 0, ids, time, low, 0);
        
        return result;
    }
};

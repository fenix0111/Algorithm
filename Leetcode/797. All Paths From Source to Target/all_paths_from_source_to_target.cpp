// Leetcode 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/
// time complexity: O(V + E)
// space complexity: O(V + E)

class Solution 
{
public:
    void DFS(int vertex, unordered_map<int, vector<int>>& G, vector<int>& path, vector<vector<int>>& result, int target)
    {
        path.push_back(vertex);
        auto it = G.find(vertex);
        if (it == G.end())
        {
            // reach the end
            if (vertex == target)
            {
                vector<int> path_copy(path);
                result.push_back(path_copy);
            }
        }
        else
        {
            vector<int>& neighbors = it->second;
            for (int v : neighbors)
            {
                DFS(v, G, path, result, target);
                if (!path.empty())
                {
                    path.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> G;
        int size = graph.size();
        for (int i = 0; i < size; i++)
        {
            vector<int>& edge = graph[i];
            for (int v : edge)
            {
                G[i].push_back(v);
            }
        }
        
        vector<vector<int>> result;
        vector<int> path;
        DFS(0, G, path, result, size - 1);
        
        return result;
    }
};

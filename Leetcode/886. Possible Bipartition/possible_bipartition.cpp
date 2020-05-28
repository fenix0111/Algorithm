// Leetcode 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/
// time complexity: O(N + E)
// space complexity: 

// using BFS & colouring
class Solution 
{
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        unordered_map<int, vector<int>> adj_list;
        vector<int> colour(N + 1, 0);
        vector<bool> visited(N + 1, false);
        queue<int> q;
        
        for (vector<int> edge : dislikes)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        for (auto it = adj_list.begin(); it != adj_list.end(); it++)
        {
            int root = it->first;
            if (visited[root])
                continue;
            
            colour[root] = 1;
            q.push(root);
            
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                
                if (visited[node])
                {
                    continue;
                }
                
                visited[node] = true;
                vector<int> neighbours = adj_list[node];
                
                for (int n : neighbours)
                {
                    if (colour[node] == colour[n])
                    {
                        return false;
                    }

                    if (colour[node] == 1)
                    {
                        colour[n] = 2;
                    }
                    else
                    {
                        colour[n] = 1;
                    }
                    q.push(n);
                }
            }
        }
          
        return true;
    }
};

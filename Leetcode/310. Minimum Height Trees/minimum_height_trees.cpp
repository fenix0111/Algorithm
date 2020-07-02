// Leetcode 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/
// time complexity: O(n)
// space complexity: O(n)

// like peeling the onion
// remove the leaf nodes layer by layer
// finally, there would be one or two nodes could be the root node

class Solution 
{
public:    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ret;
        if (n < 3)
        {
            for (int i = 0; i < n; i++)
            {
                ret.push_back(i);
            }
            
            return ret;
        }
        
        unordered_map<int, unordered_set<int>> G;
        unordered_set<int> leaves;
        
        for (vector<int> e : edges)
        {
            G[e[0]].insert(e[1]);
            G[e[1]].insert(e[0]);
        }
        
        for (auto it = G.begin(); it != G.end(); it++)
        {
            if (it->second.size() == 1)
            {
                leaves.insert(it->first);
            }
        }
        
        int size = n;
        
        while (size > 2)
        {
            size -= leaves.size();
            unordered_set<int> newleaves;
            for (auto it = leaves.begin(); it != leaves.end(); it++)
            {
                int leaf = *it;
                int neighbor = *(G[leaf].begin());
                
                G[neighbor].erase(leaf);
                
                if (G[neighbor].size() == 1)
                {
                    newleaves.insert(neighbor);
                }
            }
            
            leaves = newleaves;
        }
        
        for (auto it = leaves.begin(); it != leaves.end(); it++)
        {
            ret.push_back(*it);
        }
        
        return ret;
    }
};

// Leetcode 847. Shortest Path Visiting All Nodes
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

// ciritical point is how to set state so that avoid visiting node repeatedly which will make a cycle
// we can use bit mask represents that which nodes have been already visited up to current node
// if we revisit same node but with different bit mask
// it means that we are going to visit other node, just go through the current node

typedef struct Vertex
{
    int cost;
    int id;
    int bitmask;
    
    Vertex() {}
    Vertex(int c, int i, int b)
    {
        cost = c;
        id = i;
        bitmask = b;
    }
};

struct VHash
{
    size_t operator()(const Vertex& v) const
    {
        hash<int> hash_func;

        return hash_func(v.cost) ^ hash_func(v.id) ^ hash_func(v.bitmask);
    }
};

bool operator==(const Vertex& a, const Vertex& b)
{
    return a.cost == b.cost && a.id == b.id && a.bitmask == b.bitmask;
}

class Solution
{    
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        queue<Vertex> q;        
        unordered_set<Vertex, VHash> visited;
        
        int sz = graph.size();
        for (int i = 0; i < sz; i++)
        {
            int bits = (1 << i);
            Vertex v(0, i, bits);
            q.push(v);
            visited.insert(v);
        }
        
        while (!q.empty())
        {
            Vertex v = q.front();
            q.pop();
            
            if (v.bitmask == (1 << sz) - 1)
            {
                return v.cost;
            }
            
            vector<int>& neighbors = graph[v.id];
            for (int n : neighbors)
            {
                int mask = v.bitmask;
                mask |= (1 << n);
                
                Vertex newV(0, n, mask);
                if (!visited.count(newV))
                {
                    visited.insert(newV);
                    q.push({v.cost + 1, n, mask});
                }
            }
        }
        
        return 0;
    }
};

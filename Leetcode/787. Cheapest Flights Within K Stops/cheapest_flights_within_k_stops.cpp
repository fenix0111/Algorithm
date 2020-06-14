// Leetcode 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// time complexity: 
// space complexity: 

// sorting priority queue in ascending order
struct comp
{
    bool operator() (vector<int> x, vector<int> y)
    {
        return x[0] > y[0];
    }
};

// similar to dijkstra algorithm
// no need to track the path
class Solution 
{
public:    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        unordered_map<int, vector<int>> G;
        vector<vector<int>> price(n, vector<int>(n, 0));
       
        for (vector<int>& f : flights)
        {
            price[f[0]][f[1]] = f[2];
            G[f[0]].push_back(f[1]);
        }

        priority_queue<vector<int>, vector<vector<int>>, comp> q;
        vector<int> info = { 0, src, K }; // cost, dst, K
        q.push(info);
        
        while (!q.empty())
        {
            vector<int> v = q.top();
            q.pop();
            if (v[1] == dst)
                return v[0];
            
            if (v[2] < 0)
                continue;
            
            auto it = G.find(v[1]);
            if (it != G.end())
            {
                vector<int> neighbours = it->second;
                for (int n : neighbours)
                {
                    q.push({ v[0] + price[v[1]][n], n, v[2] - 1 });
                }
            }
        }

        return -1;
    }
};

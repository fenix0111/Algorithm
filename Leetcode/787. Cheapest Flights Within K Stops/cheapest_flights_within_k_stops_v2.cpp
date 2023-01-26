typedef std::pair<int, int> Flight;
 
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution
{
public:    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        // src -> [{dst, price}]
        unordered_map<int, vector<vector<int>>> G;
        for (vector<int>& f : flights)
        {
            G[f[0]].push_back({ f[1], f[2] });
        }

        // {src, dst} -> price
        unordered_map<Flight, int, pair_hash> price;

        vector<int> visited(n, false);
        queue<vector<int>> q;
        q.push({ src, 0 });

        int stop = 0;
        int min_price = INT_MAX;
        while (!q.empty() && stop <= K)
        {
            int sz = q.size();
            while (sz > 0)
            {
                sz--;
                vector<int>& cur = q.front();
                
                int node = cur[0];
                int cost = cur[1];
                vector<vector<int>>& neighbors = G[node];
                for (vector<int>& neighbor : neighbors)
                {
                    pair<int, int> key = make_pair(node, neighbor[0]);
                    int p = neighbor[1];

                    int total_cost = cost + p;

                    if (neighbor[0] == dst && total_cost < min_price)
                    {
                        min_price = total_cost;
                    }
                    if (price.count(key))
                    {
                        if (total_cost < price[key])
                        {
                            price[key] = total_cost;
                            q.push({ neighbor[0], total_cost });
                        }
                    }
                    else
                    {
                        price[key] = total_cost;
                        q.push({ neighbor[0], total_cost });
                    }
                }

                q.pop();
            }

            stop++;
        }

        return min_price == INT_MAX ? -1 : min_price;
    }
};

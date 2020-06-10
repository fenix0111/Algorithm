// Leetcode 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/
// time complexity: 
// space complexity: 

class Solution {
public:
    void calculateDelay(vector<vector<int>>& tbl, int K, vector<int>& delay, unordered_map<int, vector<int>>& m, vector<bool>& visited)
    {
        queue<int> q;
        q.push(K);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            auto it = m.find(node);
            if (it != m.end())
            {
                vector<int>& neighbours = it->second;
                for (int n : neighbours)
                {
                    if (!visited[n])
                    {
                        delay[n] = delay[node] + tbl[node][n];
                        visited[n] = true;
                        q.push(n);
                    }
                    else
                    {
                        // even if the neighbour have been visited, the new path have less weight
                        // put this neighbour to the queue for further update
                        if (delay[node] + tbl[node][n] < delay[n])
                        {
                            delay[n] = delay[node] + tbl[node][n];
                            q.push(n);
                        }   
                    }
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<int> delay(N + 1, -1);  // minimum delay time to each vertex
        vector<vector<int>> tbl(N + 1, vector<int>(N + 1, 0)); // keep delay between two vertices
        unordered_map<int, vector<int>> m; // edges
        vector<bool> visited(N + 1, false);
        
        for (vector<int>& T : times)
        {
            tbl[T[0]][T[1]] = T[2];
            m[T[0]].push_back(T[1]);
        }
        
        delay[K] = 0;
        visited[K] = true;
        calculateDelay(tbl, K, delay, m, visited);
        int delayTime = INT_MIN;
        bool notReachAll = false;
        
        for (int i = 1; i <= N; i++)
        {
            // failure if there is one or more vertices was not visited
            if (i != K && delay[i] == -1)
            {
                notReachAll = true;
                break;
            }
            
            if (delay[i] > delayTime)
                delayTime = delay[i];
        }
        
        if (notReachAll)
            return -1;
        
        return delayTime;
    }
};

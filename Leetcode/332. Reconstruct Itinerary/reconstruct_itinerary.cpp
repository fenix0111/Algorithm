// Leetcode 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/
// time complexity: O(E)
// space complexity: O(V + E)

// using Hierholzer's Algorithm to find Eulerian Path
class Solution 
{
public:
    void reconstruct(unordered_map<string, vector<string>>& G, 
                     vector<string>& ret, 
                     const string& from, 
                     unordered_map<string, int>& outDegree)
    {
        while (outDegree[from] > 0)
        {
            reconstruct(G, ret, G[from][--outDegree[from]], outDegree);
        }
        
        ret.push_back(from);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        unordered_map<string, vector<string>> G;
        unordered_map<string, int> outDegree;
        
        for (vector<string>& ticket : tickets)
        {
            G[ticket[0]].push_back(ticket[1]);
            ++outDegree[ticket[0]];
        }
        
        for (auto it = G.begin(); it != G.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), greater<string>());
        }
        
        vector<string> ret;
        
        reconstruct(G, ret, "JFK", outDegree);
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};

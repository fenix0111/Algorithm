// Leetcode 1557. Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        queue<int> candidates;
        vector<int> in_deg(n, 0);

        for (const vector<int>& e : edges)
        {
            int from = e[0];
            int to = e[1];

            in_deg[to]++;
        }

        vector<int> result;
    
        for (int i = 0; i < n; i++)
        {
            if (in_deg[i] == 0)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

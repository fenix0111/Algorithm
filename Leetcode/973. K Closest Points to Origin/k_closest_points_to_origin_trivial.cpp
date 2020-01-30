// Leetcode 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/
// Runtime: 328ms

// naive solution
class Solution 
{
public:
    static bool comp(vector<int> &p1, vector<int> &p2)
    {
        unsigned int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
        unsigned int dist2 = p2[0] * p2[0] + p2[1] * p2[1];
        
        return dist1 < dist2;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ret;
        for (int i = 0; i < K; i++)
        {
            ret.push_back(points[i]);
        }
        
        return ret;
    }
};

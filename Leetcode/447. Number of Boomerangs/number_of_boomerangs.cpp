// Leetcode 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/
// time complexity: O(N^2)
// space complexity: O(N)

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        int result = 0;
        int sz = points.size();
        
        // collection of points with same length to ith point
        // index is same as points array
        vector<unordered_map<int, vector<int>>> M(sz);
        
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (i == j)
                {
                    continue;
                }
                
                vector<int>& pi = points[i];
                vector<int>& pj = points[j];

                int dx = pi[0] - pj[0];
                int dy = pi[1] - pj[1];
                int len_ij = dx * dx + dy * dy;
                M[i][len_ij].push_back(j);
            }
        }
        
        for (int i = 0; i < sz; i++)
        {
            unordered_map<int, vector<int>>& m = M[i];
            for (auto it = m.begin(); it != m.end(); it++)
            {
                int psz = it->second.size();
                if (psz > 1)
                {
                    result += (psz * (psz - 1));
                }
            }
        }
        
        return result;
    }
};

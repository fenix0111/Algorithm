// Leetcode 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/
// time complexity: O(NlogN)
// space complexity: O(N)

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        int sz = arr.size();
        vector<int> result(sz, 0);
        map<int, int> M;
        for (int e : arr)
        {
            M[e] = 0;
        }
        
        int rank = 1;
        for (auto it = M.begin(); it != M.end(); it++)
        {
            it->second = rank;
            rank++;
        }
        
        for (int i = 0; i < sz; i++)
        {
            result[i] = M[arr[i]];
        }
        
        return result;
    }
};

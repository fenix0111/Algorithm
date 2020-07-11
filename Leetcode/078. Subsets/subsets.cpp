// Leetcode 78. Subsets
// https://leetcode.com/problems/subsets/
// time complexity: O(n x 2 power of n)
// space complexity: O(n x 2 power of n)

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        
        for (int n : nums)
        {
            int size = ret.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> v = ret[i];
                v.push_back(n);
                ret.push_back(v);
            }
        }
        
        return ret;
    }
};

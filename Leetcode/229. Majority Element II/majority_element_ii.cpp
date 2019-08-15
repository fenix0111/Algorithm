// Leetcode 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/
// Runtime: 8ms

// the solution is not O(1) space complexity
class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int sz = nums.size() / 3;
        unordered_map<int, int> tbl;
        for (int i : nums)
        {
            auto it = tbl.find(i);
            if (it != tbl.end())
            {
                it->second++;
            }
            else
            {
                tbl.insert(make_pair(i, 1));
            }
        }
        
        vector<int> ret;
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            if (it->second > sz)
                ret.push_back(it->first);
        }
        
        return ret;
    }
};

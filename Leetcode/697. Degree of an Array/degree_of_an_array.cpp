// Leetcode 697. Degree of an Array
// https://leetcode.com/problems/degree-of-an-array/
// Runtime: 44ms

class Solution 
{
public:
    int findShortestSubArray(vector<int>& nums)
    {
        int max = 0;
        vector<int> maxv;
        unordered_map< int, vector<int> > tbl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tbl.find(nums[i]) == tbl.end())
            {
                vector<int> v;
                v.push_back(i);
                tbl.insert(make_pair(nums[i], v));
                if (1 > max)
                    max = 1;
            }
            else
            {
                (tbl.find(nums[i])->second).push_back(i);
                if ( (tbl.find(nums[i])->second).size() > max )
                    max = (tbl.find(nums[i])->second).size();
            }
        }
        
        for (auto it = tbl.begin(); it != tbl.end(); it++)
        {
            if ( (it->second).size() == max )
            {
                maxv.push_back(it->first);
            }
        }
        
        int ret = INT_MAX;
        for (int i = 0; i < maxv.size(); i++)
        {
            vector<int> v = tbl.find(maxv[i])->second;
            if (v[v.size() - 1] - v[0] + 1 < ret)
            {
                ret = v[v.size() - 1] - v[0] + 1;
            }
        }
        
        return ret;
    }
};

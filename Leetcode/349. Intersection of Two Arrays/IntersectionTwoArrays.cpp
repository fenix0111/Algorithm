// Leetcode 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// Runtime: 4ms

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        vector<int> ret;
        unordered_set<int> ts;
        
        for (int i = 0; i < nums2.size(); i++)
        {
            if (binary_search(nums1.begin(), nums1.end(), nums2[i]))
            {
                if (ts.find(nums2[i]) == ts.end())
                {
                    ts.insert(nums2[i]);
                }
            }
        }
        
        ret.reserve(ts.size());
        
        for (auto it = ts.begin(); it != ts.end(); it++)
        {
            ret.push_back(*it);
        }
        
        return ret;
    }
};

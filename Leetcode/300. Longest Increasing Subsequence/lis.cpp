// Leetcode 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence
// Runtime: 44 ms

// 1-D Dynamic Programming
// using binary search could improve to O(N*logN)
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int sz = nums.size();
        if (sz < 2)
            return sz;
        
        vector<int> lis;
        lis.reserve(sz);  // prevent dynamically increasing vector size when pushing back
        lis.push_back(nums[0]);
        
        vector<int>::iterator pos;
        for (int i = 1; i < sz; i++)
        {
            if (lis.back() < nums[i])
            {
                lis.push_back(nums[i]);
            }
            else
            {
                // binary search for replacement position
                pos = lower_bound(lis.begin(), lis.end(), nums[i]);
                *pos = nums[i];
            }
        }
        
        return lis.size();
    }
};

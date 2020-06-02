// Leetcode 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/
// time complexity: ??
// space complexity: O(k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        multiset<long long> ms;  
        for (int i = 0; i < nums.size(); i++)
        {
            long long lower = (long long)nums[i] - t; // will cause integer overflow if using integer type here
            auto lit = ms.lower_bound(lower);
            
            if (lit != ms.end() && *lit <= (long long)nums[i] + t)
            {
                return true;
            }
            
            ms.insert(nums[i]);
            if (i >= k)
            {
                ms.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

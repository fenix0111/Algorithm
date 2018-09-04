// Leetcode 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/description/
// Runtime: 28ms

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if (nums.size() < 2) 
        {
            return false;
        }
        
        map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (m.find(nums[i]) == m.end()) 
            {
                m.insert(make_pair(nums[i], i));
            } 
            else 
            {
                int pos = m.find(nums[i])->second;
                if (i - pos <= k) 
                {
                    return true;
                } 
                else 
                {
                    m.erase(nums[i]);
                    m.insert(make_pair(nums[i], i));
                }
            }
        }
        
        return false;
    }
};

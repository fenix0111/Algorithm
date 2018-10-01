// Leetcode 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/description/
// Runtime: 4ms

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int ret = 0;
        if (nums.size() == 1)
            return 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                if (nums[i] > nums[i + 1])
                    return i;
                continue;
            }
            
            if (i == nums.size() - 1)
            {
                if (nums[i] > nums[i - 1])
                    return i;
                continue;
            }
            
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                ret = i;
                break;
            }
        }
        
        return ret;
    }
};

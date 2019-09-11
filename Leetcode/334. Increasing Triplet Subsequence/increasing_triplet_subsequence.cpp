// Leetcode 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/
// Runtime: 4ms

class Solution 
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int sz = nums.size();
        int l = INT_MIN;  // smaller one
        int r = INT_MIN;
        int i = 1;
        while (i < sz)
        {
            if (nums[i] > nums[i - 1])
            {
                l = nums[i - 1];
                r = nums[i];
                break;
            }
            i++;
        }
        
        if (i == sz)
            return false;
        
        for (int j = i; j < sz - 1; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                if (nums[j + 1] > r)
                {
                    return true;
                }
                else
                {
                    if (nums[j] > l)
                    {
                        r = nums[j];
                    }
                    else
                    {
                        l = nums[j];
                        r = nums[j + 1];
                    }
                }
            }
            else if (nums[j] > nums[j + 1])
            {
                if (nums[j + 1] > r)
                {
                    return true;
                }
            }
        }
         
        return false;
    }
};

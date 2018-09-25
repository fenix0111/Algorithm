// Leetcode 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// Runtime: 0ms

// using binary search
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int len = nums.size();
        int b = 0;
        int e = len - 1;
        int m = e / 2;
        
        while (b <= e)
        {
            if (nums[b] <= nums[e])
                return nums[b];
            
            if (nums[m] > nums[e])
            {
                b = m + 1;
            }
            else
            {
                e = m;
            }
            
            m = (e + b) / 2;
        }
        
        return nums[b];
    }
};

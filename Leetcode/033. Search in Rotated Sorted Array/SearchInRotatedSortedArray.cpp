// Leetcode 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Runtime: 4ms

class Solution 
{
public:
    int binsearch(int beg, int end, vector<int> &nums, int target)
    {
        int b = beg;
        int e = end;
        int m = (beg + end) / 2;
        while (b <= e)
        {
            if (target < nums[m])
            {
                e = m - 1;
            }
            else if (target > nums[m])
            {
                b = m + 1;
            }
            else
            {
                return m;
            }
            m = (e + b) / 2;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int sz = nums.size();
        if (sz < 1)
            return -1;
        
        int mid = 0;
        for (int i = 0; i < sz - 1; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
            
            if (nums[i] > nums[i + 1])
            {
                mid = i + 1;
                break;
            }
        }
        
        return binsearch(mid, sz - 1, nums, target);
    }
};

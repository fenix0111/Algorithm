// Leetcode 581. Shortest Unsorted Continuous Subarray
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Runtime: 44ms

// creating an temporary array, sort it then compare with original array
class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> v(nums);
        sort(v.begin(), v.end());

        int beg = 0;
        int end = nums.size() - 1;
        while (nums[beg] == v[beg] && beg < end)
        {
            beg++;
        }
        
        while (nums[end] == v[end] && beg < end)
        {
            end--;
        }
        
        // the array has already been sorted 
        if (beg == end)
        {
            return 0;
        }
        
        return end - beg + 1;
    }
};

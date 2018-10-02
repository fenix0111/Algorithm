// Leetcode 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Runtime: 12ms

// using priority queue may increase the runtime, but it need extra space.
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int len = nums.size();
        make_heap(nums.begin(), nums.end());
        
        int c = 0;
        while (c < k)
        {
            pop_heap(nums.begin(), nums.begin() + len - c);
            c++;
        }
        
        return nums[len - c];
    }
};

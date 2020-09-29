// Leetcode 713. Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k <= 1)
            return 0;
        
        int l = 0;
        int r = 0;
        int result = 0;
        int prod = 1;
        for (; r < nums.size(); r++)
        {
            prod *= nums[r];
            while (prod >= k)
            {
                prod /= nums[l++];
            }
            
            result += (r - l + 1);
        }
        
        return result;
    }
};

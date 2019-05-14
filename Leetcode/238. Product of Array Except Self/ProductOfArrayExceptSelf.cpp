// Leetcode 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Runtime: 40ms

// output[i]等于 (nums[0] * nums[1] *... * nums[i - 1) * (nums[i + 1] * .... nums[nums.size() - 1])
// 需要从数组正方向走一遍再从数组尾部反方向走一遍

// follow up: 需要改进到O(1)空间复杂度
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> tbl_fwd;
        vector<int> tbl_rev;
        vector<int> ret;
        
        int sz = nums.size();

        tbl_fwd.assign(sz, 1);
        tbl_rev.assign(sz, 1);
        ret.assign(sz, 1);
        tbl_fwd[0] = nums[0];
        tbl_rev[sz - 1] = nums[sz - 1];
        
        for (int i = 1; i < sz; i++)
        {
            tbl_fwd[i] = nums[i] * tbl_fwd[i - 1];
        }
        
        for (int i = sz - 2; i >= 0; i--)
        {
            tbl_rev[i] = nums[i] * tbl_rev[i + 1];
        }
        
        ret[0] = tbl_rev[1];
        ret[sz - 1] = tbl_fwd[sz - 2];
        
        for (int i = 1; i < sz - 1; i++)
        {
            ret[i] = tbl_fwd[i - 1] * tbl_rev[i + 1];
        }
        
        return ret;
    }
};

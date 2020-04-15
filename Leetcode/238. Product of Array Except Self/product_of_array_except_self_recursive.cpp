// Leetcode 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Runtime: 40 ms
// Memory: 14.2 MB

// recursive way
// still cost space in stack
class Solution {
public:
    int calc(vector<int> &v, int i, int left_prod, const vector<int> &nums)
    {
        if (i == v.size() - 1)
        {
            int last = v[i];
            v[i] = left_prod;
            
            return last;
        }
        
        int current = nums[i];
        v[i] = left_prod;
        
        int right_prod = calc(v, i + 1, left_prod * current, nums);
        v[i] *= right_prod;
        
        return right_prod * current;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int sz = nums.size();
        vector<int> ret;
        ret.assign(sz, 1);
        
        ret[0] = nums[0];
        ret[sz - 1] = nums[sz - 1];
        
        calc(ret, 0, 1, nums);
        
        return ret;
    }
};

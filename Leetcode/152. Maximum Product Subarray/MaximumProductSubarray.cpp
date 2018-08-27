// Leetcode 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/description/
// Runtime: 152ms (...)

// brutal-force, need optimization
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int res = INT_MIN;
        
        int *maxarr = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            maxarr[i] = INT_MIN;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int max = nums[i];
            if (max > maxarr[i]) {
                maxarr[i] = max;
            }
            
            for (int j = i + 1; j < nums.size(); j++) {
                max = max * nums[j];
                if (max > maxarr[j]) {
                    maxarr[j] = max;
                }
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (maxarr[i] > res) {
                res = maxarr[i];
            }
        }
        
        return res;
    }
};

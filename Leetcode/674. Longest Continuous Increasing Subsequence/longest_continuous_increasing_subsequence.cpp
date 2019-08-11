// Leetcode 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/
// Runtime: 12ms

class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int sz = nums.size();
        if (sz < 1)
            return 0;
        
        int count = 1;
        int i = 0;
               
        while (i < sz)
        {
            int j = i;
            while (j < sz - 1 && nums[j] < nums[j + 1])
            {
                j++;
            }

            if (j - i + 1 > count)
                count = j - i + 1;
            
            i = j + 1;
        }
        
        return count;
    }
};

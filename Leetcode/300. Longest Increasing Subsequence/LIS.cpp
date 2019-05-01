// Leetcode 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence
// Runtime: 44 ms

// 1-D Dynamic Programming
// using binary search could improve to O(N*logN)
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int sz = nums.size();
        if (sz < 2)
            return sz;
        
        int *tbl = new int[sz];
        int max = 0;
        for (int i = 0; i < sz; i++)
        {
            tbl[i] = 0;
        }
        
        for (int i = 1; i < sz; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (tbl[i] < tbl[j] + 1)
                        tbl[i] = tbl[j] + 1;
                }
                
                if (tbl[i] > max)
                    max = tbl[i];
            }
        }
        
        return max + 1;
    }
};

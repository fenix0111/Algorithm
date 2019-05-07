// Leetcode 31. Next Permutation
// https://leetcode.com/problems/next-permutation/
// Runtime: 4ms

class Solution 
{
public:
    void swap(vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void nextPermutation(vector<int>& nums) 
    {
        int sz = nums.size();
        if (sz < 2)
            return;
        
        // from right to left, first element less than its right neighbor
        int p = sz - 1; 
        
        // from right to left, first element greater than nums[p]
        // index also need to greater than p
        int q = sz - 1;
        int i = sz - 1;
        while (i > 0)
        {
            if (nums[i - 1] < nums[i])
            {
                p = i - 1;
                break;
            }
            else
            {
                i--;
            }
        }
        
        i = sz - 1;
        while (i >= 0)
        {
            if (nums[i] > nums[p] && i > p)
            {
                q = i;
                break;
            }
            else
            {
                i--;
            }
        }
        
        if (p != q)
            swap(nums, p, q);
        
        if (p == q)
        {
            // in case of the nums was already sorted in descending order
            reverse(nums.begin(), nums.end());
        }
        else
        {
            reverse(nums.begin() + p + 1, nums.end());
        }
    }
};

// Leetcode 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/
// Runtime: 68ms

class Solution 
{
public:
    void wiggleSort(vector<int>& nums) 
    {
        vector<int> tbl(nums);
        int sz = nums.size();

        sort(tbl.begin(), tbl.end());
        int beg = 0;
        
        // number of the least elements are at most half of the elements + 1
        int end =  1 + nums.size() / 2;
        int c = 0;
        while(c < nums.size())
        {
            if (beg <= nums.size() / 2)
                nums[c++] = tbl[beg];
            
            if (end < nums.size())
                nums[c++] = tbl[end];
            
            beg++;
            end++;
        }
        
        // if last two elements are the same
        // right shift one element, then reverse the remaining elements
        if (sz > 2 && nums[sz - 1] == nums[sz - 2])
        {
            int last = nums[sz - 1];
            for (int i = sz - 2; i >= 0; i--)
            {
                nums[i + 1] = nums[i];
            }
            
            nums[0] = last;
            
            for (int i = 1; i < sz / 2; i++)
            {
                int tmp = nums[i];
                nums[i] = nums[sz - 1 - i];
                nums[sz - 1 - i] = tmp;
            }
        }
    }
};

// Leetcode 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/
// Runtime: 12 ms
// Memory: 7.1 MB

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int l = 0;
        int r = 1;
        
        if (nums.size() < 2)
        {
            return;
        }
        
        while (l < nums.size() && r < nums.size())
        {
            if (nums[l] == 0)
            {
                if (nums[r] != 0)
                {
                    // no need to do conventional swapping
                    nums[l] = nums[r];
                    nums[r] = 0;
                    
                    l++;
                    r = r + 1;
                }
                else
                {
                    r++;
                }
            }
            else 
            {
                l++;
                r++;
            }
        }
    }
};

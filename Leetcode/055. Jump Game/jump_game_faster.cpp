// Leetcode 55. Jump Game
// https://leetcode.com/problems/jump-game/
// Runtime: 8 ms
// Memory: 7.9 MB

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int end = nums.size() - 1;
        int last = nums.size() - 1; // the last point to which we can jump
        
        int i = last;
        while (i > 0)
        {
            // if we can jump from previous point, just go one step backward
            if (last - i <= nums[i] || i + nums[i] >= end)
            {
                i--;
                last = i + 1;
                continue;
            }
            
            // ignore 0 for now
            if (nums[i] == 0)
            {
                i--;
                continue;
            }
            
            // in other case, just go back
            i--;
        }
        
        // calculate the distance between last point and first point
        if (last - i <= nums[i] || i + nums[i] >= end)
        {
            return true;
        }
        
        return false;
    }
};

// Leetcode 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/
// 
//

class Solution 
{
public:
    void check(vector<int>& nums, vector<int>& tbl, int index, int numJump)
    {
        // reach the end
        if (index >= nums.size())
        {
            if (tbl[nums.size() - 1] > numJump)
            {
                tbl[nums.size() - 1] = numJump;
            }
            
            return;
        }
        
        if (tbl[index] > numJump)
        {
            tbl[index] = numJump;
        }
        
        int length = nums[index];
        for (int i = length; i >= 1; i--)
        {            
            // check if next jump will reach the end
            // or, if total number of jump in the next is greater than previous, then quit the loop (no need to proceed)
            if (index + i >= nums.size())
            {
                if (tbl[nums.size() - 1] > numJump + 1)
                {
                    tbl[nums.size() - 1] = numJump + 1;
                }
                
                return;
            }
            else
            {
                if (tbl[index + i] <= numJump + 1)
                {
                    return;
                }
            }
            
            check(nums, tbl, index + i, numJump + 1);
        }
    }
        
    int jump(vector<int>& nums) 
    {
        int sz = nums.size();
        vector<int> tbl(sz, INT_MAX);
        
        check(nums, tbl, 0, 0);
        
        return tbl[sz - 1];
    }
};

// Leetcode 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/
// time complexity: O(n)
// space complexity: O(1)

// drawing a diagram will help 
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int size = nums.size();
        if (size < 2)
            return size;
        
        int prev_diff = nums[1] - nums[0];
        int counter;
        if (prev_diff == 0)
        {
            counter = 1;
        }
        else
        {
            counter = 2;
        }
        
        int diff;
        for (int i = 2; i < nums.size(); i++)
        {
            diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0)) 
            {
                counter++;
                prev_diff = diff;
            }
        }
        
        return counter;
    }
};

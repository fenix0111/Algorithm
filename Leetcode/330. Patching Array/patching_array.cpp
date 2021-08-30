// Leetcode 330. Patching Array
// https://leetcode.com/problems/patching-array/
// time complexity: O(n) (maybe ?)
// space complexity: O(1)

// we could treat this problem as a variation of problem given below
// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
        unsigned int next = 1;
        int result = 0;
        
        int i = 0;
        while (next <= n)
        {
            if (i < nums.size() && nums[i] <= next)
            {
                next += nums[i];
                i++;
            }
            else
            {
                result++;
                next += next;
            }
        }
        
        return result;
    }
};

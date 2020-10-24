// Leetcode 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/
// time complexity: O(n2)
// space complexity: O(1)

class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        int inum = nums[0];
        int jnum = INT_MIN;
        int sz = nums.size();
        
        for (int i = 0; i < sz - 2; i++)
        {
            int ii = nums[i];
            int jj = nums[i + 1];
            for (int k = i + 2; k < sz; k++)
            {
                if (nums[k] > ii && nums[k] < jj)
                {
                    return true;
                }
                
                if (nums[k] > jj)
                {
                    jj = nums[k];
                }
            }
        }
        
        return false;
    }
};

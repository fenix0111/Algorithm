// Leetcode 665. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int pos = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                // already met problematic position, return false directly
                if (pos != -1)
                {
                    return false;
                }
                
                pos = i;
            }
        }
        
        // ignore the position in the head or tail of the array
        if (pos == -1 || pos == 0 || pos == nums.size() - 2)
        {
            return true;
        }
        else
        {
            if (nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

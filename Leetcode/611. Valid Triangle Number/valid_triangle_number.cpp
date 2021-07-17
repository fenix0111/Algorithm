// Leetcode 611. Valid Triangle Number
// https://leetcode.com/problems/valid-triangle-number/
// time complexity: O(n*n*logn)
// space complexity: ?

class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int up = nums[j] + nums[i];
                
                int right = lower_bound(nums.begin() + j + 1, nums.end(), up) - nums.begin();
                if (j < right)
                {
                    result += (right - j - 1);
                }
            }
        }
        
        return result;
    }
};

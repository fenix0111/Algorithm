// Leetcode 1005. Maximize Sum Of Array After K Negations
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/

class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        int result = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                k = 0;
            }
            else if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }

            if (k == 0)
            {
                break;
            }
        }
        
        int minval = INT_MAX;
        for (int num : nums)
        {
            result += num;
            minval = min(num, minval);
        }
        
        if (k % 2 == 0)
        {
            return result;
        }
        
        result -= (2 * minval);
        
        return result;
    }
};

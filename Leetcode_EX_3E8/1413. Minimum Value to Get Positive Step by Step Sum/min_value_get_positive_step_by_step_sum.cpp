// Leetcode 1413. Minimum Value to Get Positive Step by Step Sum
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    int minStartValue(vector<int>& nums)
    {
        int result = 0;
        int min_sum = INT_MAX;
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            min_sum = min(min_sum, sum);
        }
        
        if (min_sum > 0)
        {
            result = 1;
        }
        else
        {
            result = -min_sum + 1;
        }
        
        return result;
    }
};

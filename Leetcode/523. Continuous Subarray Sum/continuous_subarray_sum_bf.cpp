// Leetcode 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
// time complexity: O(N*N)
// space complexity: O(1)

// brute force solution
class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                
                // checking if the k equals to zero
                if (k == 0 && sum == 0)
                {
                    return true;
                }
                
                if (k != 0 && sum % k == 0)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

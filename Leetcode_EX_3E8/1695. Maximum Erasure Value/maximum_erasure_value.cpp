// Leetcode 1695. Maximum Erasure Value
// https://leetcode.com/problems/maximum-erasure-value/
// time complexity: O(n), moving pointers have amortized O(1) time complexity
// space complexity: O(n)

class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int result = 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        bool seen[100001] = { false };
        
        for (int num : nums)
        {
            if (seen[num])
            {
                while (nums[left] != num)
                {
                    sum -= nums[left];
                    seen[nums[left]] = false;
                    left++;
                }
                
                sum -= num;
                seen[num] = false;
                left++;
            }
            
            right++;
            sum += num;
            seen[num] = true;
            
            result = max(sum, result);
        }
        
        return result;
    }
};

// Leetcode 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// time complexity: O(n)
// space complexity: O(1)

// find the subarray which sum is equal to "sum(array) - x"
class Solution 
{
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sz = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target == 0)
        {
            return sz;
        }
        
        int result = INT_MAX;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        while (i <= j && j < sz)
        {            
            sum += nums[j];
            
            if (sum == target)
            {
                int len = j - i + 1;
                if (sz - len < result)
                {
                    result = sz - len;
                }
                
                sum -= nums[i];
                
                i++;
                j++;
            }
            else if (sum > target)
            {                    
                if (i == j)
                {
                    sum -= nums[j];
                    i++;
                    j++;
                }
                else
                {
                    sum -= nums[i];
                    sum -= nums[j];
                    i++;
                }
            }
            else
            {
                j++;
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

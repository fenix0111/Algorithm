// Leetcode 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
// time complexity: O(N)
// space complexity: O(N)

// keep the "sum of nums" mod k, and check if there are same mod results appeared twice in which distance between two indices is greater than 1.
// if there are two same mod results, it means there is a multiple of k between them, since mod of multiple k is zero. 
// take care if k is zero

class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> tbl;
        tbl[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (k != 0)
            {
                sum %= k;
            }
            
            if (tbl.find(sum) != tbl.end())
            {
                if (i - tbl[sum] > 1)
                {
                    return true;
                }
            }
            else
            {
                tbl[sum] = i;
            }
        }
        
        return false;
    }
};

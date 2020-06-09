// Leetcode 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
// time complexity: O(size of nums * sums)
// space complexity: O(sum)

class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for (int& i : nums)
        {
            sum += i;
        }
        
        if (sum & 1)
            return false;
        
        sum = sum >> 1;
        
        bool* tbl = (bool*)malloc(sizeof(bool) * (sum + 1));
        for (int i = 0; i < sum + 1; i++)
        {
            tbl[i] = false;
        }
        tbl[0] = true;
        
        for (int num : nums) 
        {
            for (int i = sum; i > 0; i--) 
            {
                if (i >= num) 
                {
                    tbl[i] = tbl[i] || tbl[i - num];
                }
            }
        }
        
        return tbl[sum];
    }
};

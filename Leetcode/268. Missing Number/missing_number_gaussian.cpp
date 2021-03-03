// using Gaussian formula

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int len = nums.size();
        int sum_of_nums = 0;
        for (int i = 0; i < len; i++)
        {
            sum_of_nums += nums[i];
        }
        
        int tsum = ((1 + len) * len) / 2;
        
        return tsum - sum_of_nums;
    }
};

// Leetcode 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/description/
// Runtime: 252 (Grade F)

int maxSubArray(int* nums, int numsSize) 
{
    if (numsSize == 1)
        return nums[0];
    
    int range = 0;
    int sum = INT_MIN;
    
    for (int i = 0; i < numsSize; i++)
    {
        int tmp = nums[i];
        if (tmp > sum)
            sum = tmp;
                
        if (tmp < 0)
            continue;
			
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] > sum)
                sum = nums[j];
            tmp += nums[j];
            if (tmp > sum)
                sum = tmp;
        }
    }
    return sum;
}

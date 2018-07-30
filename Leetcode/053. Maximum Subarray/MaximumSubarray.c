// Leetcode 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/description/
// Runtime: 6ms

// Kadane算法: https://en.wikipedia.org/wiki/Maximum_subarray_problem
int maxSubArray(int* nums, int numsSize) 
{
    int sum = INT_MIN;
    int last = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] + last > sum)
            sum = nums[i] + last;

        last = last + nums[i];
        if (last < 0)
            last = 0;
    }
    
    return sum;
}

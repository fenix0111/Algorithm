// Leetcode 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Runtime: 6ms

// 肯定的，这个解法不是最优的，不然根本不值得成为Normal难度的题
int search(int* nums, int numsSize, int target) 
{
    for (int i = 0; i < numsSize; i++)
    {
        if (target == nums[i])
        {
            return i;
        }
    }
    return -1;
}

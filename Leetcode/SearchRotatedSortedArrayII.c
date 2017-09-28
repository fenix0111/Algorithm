// Leetcode 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// Runtime: 3ms

// 这问题有点古怪...
bool search(int* nums, int numsSize, int target) 
{
    for (int i = 0; i < numsSize; i++)
    {
        if (target == nums[i])
        {
            return true;
        }
    }
    return false;
}

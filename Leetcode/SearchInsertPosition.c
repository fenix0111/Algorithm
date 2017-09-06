// Leetcode 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/description/
// Runtime: 3 ms

int binsearch(int *nums, int low, int high, int target)
{
    if (low == high)
    {
        if (target <= nums[low])
        {
            if (low == 0)
            {
                return 0;
            }
            else
            {
                return low;
            }
        }
        else
        {
            return low + 1;
        }
    }
    
    int mid = (high - low) / 2;
    if (nums[low + mid] == target)
    {
        return low + mid;
    }
    else if (nums[low + mid] < target)
    {
        return binsearch(nums, low + mid + 1, high, target);
    }
    else if (nums[low + mid] > target)
    {
        return binsearch(nums, low, low + mid, target);
    }
    return;
}

int searchInsert(int* nums, int numsSize, int target) 
{
    return binsearch(nums, 0, numsSize - 1, target);
}

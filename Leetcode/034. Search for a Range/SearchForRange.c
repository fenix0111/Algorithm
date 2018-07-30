// Leetcode 34. Search for a Range
// https://leetcode.com/problems/search-for-a-range/description/
// Runtime: 6ms

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int *res = (int*)malloc(sizeof(int) * 2);      
    *returnSize = 2;
    if (numsSize == 1)
    {
        if (nums[0] == target)
        {
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        else
        {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
    }
    
    int mid = numsSize / 2;
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right)
    {
        int tmp = nums[mid];
        if (target > tmp)
        {
            if (right - 1 == mid)
            {
                if (nums[right] != target)
                {
                    break;
                }
                else
                {
                    res[0] = right;
                    res[1] = right;
                    return res;
                }
            }
            left = mid;
            mid = mid + (right - left) / 2;
        }
        else if (target < tmp)
        {
            if (left == mid)
            {
                break;
            }
            right = mid;
            mid = (right - left) / 2;
        }
        else if (target == tmp)
        {
            left = mid;
            right = mid;
            while (left >= 0)
            {
                if (nums[left] == target)
                {
                    left--;
                }
                else
                {
                    break;
                }
            }
            left++;
            
            while (right < numsSize)
            {
                if (nums[right] == target)
                {
                    right++;
                }
                else
                {
                    break;
                }
            }
            right--;
            
            res[0] = left;
            res[1] = right;
            return res;
        }
    }

    res[0] = -1;
    res[1] = -1;
    return res;
}

// Leetcode 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Runtime: 233 ms (最差的一道, 普遍12ms)

int removeDuplicates(int* nums, int numsSize) 
{
    int len = numsSize;
    int h = 0;
    int f = h + 1;
    while (h < len - 1)
    {
        f = h + 1;
        if (nums[h] != nums[f])
        {
            h++;
        }
        else
        {
            int c = 0;
            while (nums[f] == nums[h])
            {
                if (f < len - 1)
                {
                    f++;
                    c++;
                    continue;
                }
				
                if (f == len - 1)
                {
                    c++;
                    break;
                }
            }

            int tmph = h + 1;
            for (int i = f; i < len; i++)
            {
                nums[tmph++] = nums[i];
            }
            len = len - c;
        }
    }
    return len;
}

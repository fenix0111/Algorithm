// Leetcode 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
// Runtime: 6ms

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1 || numsSize == 2)
        return numsSize;
    
    int res = 0;
    int dup = 1;
    int last = nums[0];
    int len = numsSize;
    
    int i = 1;
    while (i < len)
    {
        if (nums[i] == last)
        {
            if (dup < 2)
            {
                dup++;
                i++;
            }
            else
            {
                int j = i;
                while (j < numsSize)
                {
                    if (nums[j] != last)
                        break;
                    j++;
                }
                
                int ii = 0;
                for (int k = j; k < len; k++)
                {
                    nums[i + ii] = nums[k];
                    ii++;
                }
                len = len - (j - i);
            }
        }
        else
        {
            res = res + dup;
            dup = 1;
            last = nums[i];
            i++;
        }
    }
    
    return res + dup;
}

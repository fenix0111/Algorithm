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

// Updated
// Runtime: 8ms

int removeDuplicates(int* nums, int numsSize) 
{
    if (numsSize <= 1) 
    {
        return numsSize;
    }

    int res = 1;
    int last = nums[0];
    int lastindex = 0;
    int insertpos = 0;
    int i = 1;
    while (i < numsSize)
    {
        if (last == nums[i]) 
        {
            if (insertpos == 0)
            {
                insertpos = lastindex + 1;
            }
			
            while (last == nums[i]) 
            {
                i++;
            }
            nums[insertpos] = nums[i];
        }
        else 
        {
            if (insertpos != 0) 
            {
                nums[insertpos] = nums[i];
                insertpos++;
            }

            last = nums[i];
            lastindex = i;
            res++;
            i++;
        }
    }
    
    return res;
}

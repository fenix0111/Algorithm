// Leetcode 27. Remove Element
// https://leetcode.com/problems/remove-element/description/
// Runtime: 6ms

void arrange(int *nums, int numsSize, int begin)
{
	for (int i = begin; i < numsSize; i++)
	{
		*(nums + i) = *(nums + i + 1);
	}
}

int removeElement(int* nums, int numsSize, int val) 
{
	int size = numsSize;
	int cur = 0;
	while (cur < size)
	{
		if (*(nums + cur) == val)
		{
			size--;
			arrange(nums, size, cur);
		}
		else
		{
			cur++;
		}
	}
	return size;
}

// 3ms参考解法
int removeElement(int* nums, int numsSize, int val) {
    int i;
    int array_size = numsSize;
    while (i<array_size)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[array_size-1];
            array_size--;
        }
        else
        {
            i++;
        }
    }
    return array_size;
}

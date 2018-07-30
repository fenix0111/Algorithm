// Leetcode 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
// Runtime: 3ms

// 有点奇怪的题。。用冒泡排序也能过
void swap(int *n, int *m)
{
    int tmp = *n;
    *n = *m;
    *m = tmp;
}

void sortColors(int* nums, int numsSize) 
{
    int h = 0;
    int t = numsSize - 1;
    
    // 先把0排到前面
    while (h < t)
    {
        while (nums[h] == 0 && h < numsSize)
            h++;

        while (nums[t] != 0 && t >= 0)
            t--;

        // 有时候h会比t大,这时候就不能交换数据了
        if (h < t)
            swap(&nums[h], &nums[t]);
    }

    t = numsSize - 1;

    // 之后把1排到前面
    while (h < t)
    {
        while (nums[h] == 1 && h < numsSize)
            h++;

        while (nums[t] != 1 && t >= 0)
            t--;

        if (h < t)
            swap(&nums[h], &nums[t]);
    }
}

// Leetcode 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/description/
// Runtime: 3ms

// 十多次提交后终于通过。。
// 此题不讲究技巧但非常讲究各种边缘条件的判断
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int firstMissingPositive(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        if (nums[0] <= 0)
        {
            return 1;
        }
        else
        {
            if (nums[0] > 1)
                return 1;
            else if (nums[0] == 1)
                return nums[0] + 1;
        }
    }
    
    // 先排序。这里直接在原始数组排了序可能不太合适
    qsort(nums, numsSize, sizeof(int), compare);
    
    // 尾数为负数
    if (nums[numsSize - 1] <= 0)
        return 1;
    
    // 第一个数大于1, 直接返回1
    if (nums[0] > 1)
        return 1;
    
    // 尾数为1
    if (nums[numsSize - 1] == 1)
        return 2;
    
    int containOne = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] < 0)
        {
            continue;
        }
        else
        {
            if (nums[i] == 1)
                containOne = 1;
                
            if (nums[i + 1] - nums[i] <= 1)
            {
                // 前后为连续的整数或相同的整数
                continue;
            }
            else
            {
                if (nums[i] == 0)
                    return 1;
                
                if (nums[i] == 1)
                {
                    return 2;
                }
                else
                {
                    if (containOne)
                        return nums[i] + 1;
                    else
                        return 1;
                }
            }
        }
    }
    
    // 顺利通过for循环说明数组元素全为连续的整数
    // 当所有元素为非负数
    if (nums[0] == 1 || nums[0] == 0)
        return nums[numsSize - 1] + 1;
    
    // 这里需要判断数组里是否包含1
    if (nums[numsSize - 1] > 1)
    {
        if (containOne)
            return nums[numsSize - 1] + 1;
        else
            return 1;
    }
    
    return 1;
}

// Leetcode 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// Runtime: 139ms (Grade F)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int len = nums.size();
        std::vector<int> res;
        for (int i = 0; i < len; i++) 
        {
            for (int j = i + 1; j < len; j++) 
            {
                if (nums.at(i) + nums.at(j) == target) 
                { 
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
};

// Update: 
// Runtime: 3ms
// 使用了辅助空间复制了原始数据并做了排序。
// 之后用头尾指针扫一遍数组。
// 发现两个和为target的值回到原数组找下标。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int *res = (int*)malloc(sizeof(int) * 2);
    
    // 辅助空间
    int *sorted = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        sorted[i] = nums[i];
    }

    // C标准库里的快速排序函数
    qsort(sorted, numsSize, sizeof(int), compare);

    int head = 0;
    int tail = numsSize - 1;
    while (head < tail)
    {
        int tmp = sorted[head] + sorted[tail];
        if (tmp == target)
        {
            for (int x = 0; x < numsSize; x++)
            {
                if (nums[x] == sorted[head])
                {
                    res[0] = x;
                    break;
                }
            }
            for (int x = 0; x < numsSize; x++)
            {
                // 因为数组可能包含两个相同的元素且相同元素的和为target。
                // 故需要做下标重复判断。赋给res[0]的就不能给res[1]
                if (nums[x] == sorted[tail] && x != res[0])
                {
                    res[1] = x;
                    break;
                }
            }
            break;
        }
        else if (tmp < target)
        {
            head++;
        }
        else if (tmp > target)
        {
            tail--;
        }
    }
    
    free(sorted);
    return res;
}

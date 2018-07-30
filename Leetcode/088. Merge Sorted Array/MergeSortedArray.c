// Leetcode 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/description/
// Runtime: 3ms

void merge(int* nums1, int m, int* nums2, int n) 
{
    if (n == 0)
    {
        return;
    }
   
    int *tmp = (int*)malloc(sizeof(int) * (m + n));
    int xm = 0;
    int xn = 0;
    int xt = 0;
    while (xm < m && xn < n)
    {
        if (nums1[xm] <= nums2[xn])
        {
            tmp[xt] = nums1[xm];
            xm++;
            xt++;
        }
        else
        {
            tmp[xt] = nums2[xn];
            xn++;
            xt++;
        }
    }
    
    if (xm == m)
    {
        while (xn < n)
        {
            tmp[xt] = nums2[xn];
            xn++;
            xt++;
        }
    }
    else if (xn == n)
    {
        while (xm < m)
        {
            tmp[xt] = nums1[xm];
            xm++;
            xt++;
        }
    }
    memcpy(nums1, tmp, sizeof(int) * (m + n));
}

// 0ms参考解法
void merge(int* nums1, int m, int* nums2, int n) 
{
    int i, j, k ;
    i = m - 1; j = n - 1; k = m + n -1;
    while(i >= 0 || j >= 0)
    {
        if(j < 0|| (i >= 0 && nums1[i] > nums2[j]))
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    return ;
}

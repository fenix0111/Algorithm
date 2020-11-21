// Leetcode 493. Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/
// 
// 

class Solution 
{
public:
    void MergeSort(vector<int>& indices, vector<int>& nums, int left, int right, int& result, vector<int>& working)
    {
        if (left >= right)
        {
            return;
        }
        
        int mid = left + (right - left) / 2;
        MergeSort(indices, nums, left, mid, result, working);
        MergeSort(indices, nums, mid + 1, right, result, working);
        
        int l = left;
        int m = mid + 1;
        int i = left;
        
        for (int i = left; i <= mid; i++)
        {
            // using 2L in case of integer overflow
            while (m <= right && nums[indices[i]] > 2L * nums[indices[m]])
            {
                m++;
            }
            
            result += (m - mid - 1);
        }
        
        l = left;
        m = mid + 1;
        i = left;
        while (l <= mid && m <= right)
        {
            if (nums[indices[l]] <= nums[indices[m]])
            {
                working[i] = indices[l];
                l++;
            }
            else
            {
                working[i] = indices[m];
                m++;
            }
            i++;
        }
        
        while (l <= mid)
        {
            working[i] = indices[l];
            l++;
            i++;
        }
        
        while (m <= right)
        {
            working[i] = indices[m];
            m++;
            i++;
        }
        
        for (int i = left; i <= right; i++)
        {
            indices[i] = working[i];
        }
    }
    
    int reversePairs(vector<int>& nums) 
    {
        int result = 0;
        vector<int> working(nums.size(), 0);        
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            indices.push_back(i);
        }
        
        MergeSort(indices, nums, 0, nums.size() - 1, result, working);

        return result;
    }
};

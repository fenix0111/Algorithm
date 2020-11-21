// Leetcode 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// 
// 

class Solution 
{
public:
    void MergeSort(vector<int>& indices, vector<int>& nums, int left, int right, vector<int>& result, vector<int>& working)
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
        
        for (int i = left; i <= mid; i++)
        {
            while (m <= right && nums[indices[i]] > nums[indices[m]])
            {
                m++;
            }
            
            result[indices[i]] += (m - mid - 1);
        }
        
        l = left;
        m = mid + 1;
        int i = left;
        
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
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int> result(nums.size(), 0);
        vector<int> working(nums.size(), 0);
        
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            indices.push_back(i);
        }
        
        MergeSort(indices, nums, 0, nums.size() - 1, result, working);
        if (result.size() > 1)
            result[result.size() - 1] = 0;
        
        return result;
    }
};

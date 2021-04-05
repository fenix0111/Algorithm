// Leetcode 775. Global and Local Inversions
// https://leetcode.com/problems/global-and-local-inversions/
// time complexity:O(nlogn)
// space complexity: O(n)

// using merge sort in https://leetcode.com/problems/count-of-smaller-numbers-after-self/
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
        int i = left;
        
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
    
    bool isIdealPermutation(vector<int>& A) 
    {
        int localInversions = 0;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                localInversions++;
            }
        }
        
        vector<int> result(A.size(), 0);
        vector<int> working(A.size(), 0);
        
        vector<int> indices;
        for (int i = 0; i < A.size(); i++)
        {
            indices.push_back(i);
        }
        
        MergeSort(indices, A, 0, A.size() - 1, result, working);
        if (result.size() > 1)
            result[result.size() - 1] = 0;
        
        int globalInversions = 0;
        for (int n : result)
        {
            globalInversions += n;
        }
        
        return localInversions == globalInversions;
    }
};

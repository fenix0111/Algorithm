// Leetcode 969. Pancake Sorting
// https://leetcode.com/problems/pancake-sorting/
// time complexity: O(pow(size of array, 2))
// space complexity: O(1)

// the problem description is a bit misleading
class Solution 
{
public:
    void invert(vector<int>& A, int begin, int end)
    {
        int b = begin;
        int e = end;
        while (b < e)
        {
            int tmp = A[b];
            A[b] = A[e];
            A[e] = tmp;
            b++;
            e--;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) 
    {
        int sz = A.size();
        int boundary = sz - 1;
        vector<int> steps;
        
        int index = 0;
        int greater = INT_MIN;
        bool is_sorted = true;
        for (int i = 0; i < sz - 1; i++)
        {
            if (A[i] >= A[i + 1])
            {
                is_sorted = false;
            }
        }
        
        if (is_sorted)
        {
            return steps;
        }
        
        while (boundary > 0)
        {            
            int next = 0;
            for (int i = 0; i <= boundary; i++)
            {
                if (A[i] > greater)
                {
                    greater = A[i];
                    index = i;
                }
            }
            
            invert(A, 0, index);
            invert(A, 0, boundary);
            
            steps.push_back(index + 1);
            steps.push_back(boundary + 1);
            
            boundary--;
            greater = INT_MIN;
        }
        
        return steps;
    }
};

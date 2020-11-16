// Leetcode 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    int longestMountain(vector<int>& A) 
    {
        int sz = A.size();
        if (sz < 3)
            return 0;
        
        int summit = -1;
        int piemonte = 0;
        int result = 0;
        
        for (int i = 1; i < sz - 1; i++)
        {
            if (A[i] > A[i - 1] && A[i] > A[i + 1])
            {
                summit = i;
                continue;
            }
            
            if (A[i] <= A[i - 1] && A[i] <= A[i + 1])
            {
                if (summit != -1)
                {
                    int length = i - piemonte + 1;
                    if (length > result)
                    {
                        result = length;
                    }
                }
                
                piemonte = i;
                summit = -1;  // reset summit index
            }
        }
        
        if (summit > piemonte)
        {
            if (sz - piemonte > result)
            {
                result = sz - piemonte;
            }
        }
        
        return result;
    }
};

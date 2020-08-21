// Leetcode 905. Sort Array By Parity
// https://leetcode.com/problems/sort-array-by-parity/
// time complexity: O(size of array)
// space complexity: O(1)

class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        int odd = A.size() - 1;
        int even = 0;
        
        while (even < odd)
        {
            if ((A[even] & 1) == 0)
            {
                even++;
            }
            else
            {
                int tmp = A[odd];
                A[odd] = A[even];
                A[even] = tmp;
                
                odd--;
            }
        }
        
        return A;
    }
};

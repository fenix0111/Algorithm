// Leetcode 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/
// time complexity: O(n)
// space complexity: O(1)

// count the number of same differences in a row
class Solution 
{
public:
    int getSize(int n)
    {
        if (n < 3)
        {
            return 0;
        }
        
        if (n == 3)
        {
            return 1;
        }
        
        return getSize(n - 1) + n - 2;
    }
    
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int result = 0;
        int sz = A.size();
        if (sz < 3)
        {
            return 0;
        }
        int i = 0;
        int diff = INT_MAX;
        int count = 1;
        while (i < sz - 1)
        {
            if (A[i] - A[i + 1] != diff)
            {
                diff = A[i] - A[i + 1];
                result += getSize(count + 1);        
                count = 1;
            }
            else
            {
                count++;
            }
            i++;
        }
        
        result += getSize(count + 1);
        
        return result;
    }
};

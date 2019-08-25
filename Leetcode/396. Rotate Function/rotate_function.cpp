// Leetcode 396. Rotate Function
// https://leetcode.com/problems/rotate-function/
// Runtime: 8ms

// take care of integer overflow
class Solution 
{
public:
    int maxRotateFunction(vector<int>& A) 
    {
        long long sumA = (long long)accumulate(A.begin(), A.end(), (long long)0);
        long long sumB = 0;
        long long max = LLONG_MIN;
        int sz = A.size();
        
        for (int i = 0; i < sz; i++)
        {
            sumB += i * (long long)A[i];
        }
        
        if (sumB > max)
            max = sumB;
        
        for (int i = sz - 1; i >= 0; i--)
        {
            sumB = sumB + sumA - sz * (long long)A[i];
            if (sumB > max)
                max = sumB;
        }
        
        return max;
    }
};

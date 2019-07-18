// Leetcode 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// Runtime: 0ms

class Solution 
{
public:
    int fib(int N) 
    {
        if (N == 0)
            return 0;
        
        if (N == 1)
            return 1;
        
        int *tbl = (int*)malloc(sizeof(int) * (N + 1));
        tbl[0] = 0;
        tbl[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            tbl[i] = tbl[i - 1] + tbl[i - 2];
        }
        
        return tbl[N];
    }
};

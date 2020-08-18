// Leetcode 967. Numbers With Same Consecutive Differences
// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// 
// 

class Solution 
{
public:    
    void makeNumbers(vector<int>& result, int N, int K, int len, int val, int num)
    {
        if (len == N)
        {
            result.push_back(val);
            return;
        }
        
        if (K == 0)
        {
            makeNumbers(result, N, K, len + 1, 10 * val + num, num);
        }
        else
        {
            if (num + K < 10)
            {
                makeNumbers(result, N, K, len + 1, 10 * val + num + K, num + K);
            }

            if (num - K >= 0)
            {
                makeNumbers(result, N, K, len + 1, 10 * val + num - K, num - K);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) 
    {
        vector<int> result;
        if (N == 1)
        {
            result.push_back(0);
        }
        
        for (int i = 1; i <= 9; i++)
        {
            makeNumbers(result, N, K, 1, i, i);
        }
        
        return result;
    }
};

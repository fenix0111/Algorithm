// Leetcode 507. Perfect Number
// https://leetcode.com/problems/perfect-number/
// Runtime: 0ms

class Solution 
{
public:
    bool checkPerfectNumber(int num) 
    {
        if (num < 2)
            return false;
        
        set<int> buf;
        int root = (int)sqrt(num);
        int n = 1;
        while (n <= root)
        {
            if (num % n == 0)
            {
                buf.insert(n);
                int q = num / n;
                if (q != num)
                    buf.insert(q);
            }
            n++;
        }
        
        int sum = 0;
        for (auto it = buf.begin(); it != buf.end(); it++)
        {
            sum += *it;
        }
        
        return (sum == num);
    }
};

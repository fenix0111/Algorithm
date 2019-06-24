// Leetcode 338. Counting Bits
// https://leetcode.com/problems/counting-bits/
// Runtime: 56ms

// trivial solution
class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> ret;
        ret.reserve(num + 1);
        for (int i = 0; i <= num; i++)
        {
            int n = i;
            int c = 0;
            while (n > 0)
            {
                if (n & 1)
                {
                    c++;
                }
                n = n >> 1;
            }
            ret.push_back(c);
        }
        
        return ret;
    }
};

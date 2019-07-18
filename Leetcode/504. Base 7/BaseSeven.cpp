// Leetcode 504. Base 7
// https://leetcode.com/problems/base-7/
// Runtime: 4ms

class Solution {
public:
    string convertToBase7(int num) 
    {
        if (num == 0)
            return "0";
        
        int p = 0;
        bool neg = false;
        if (num < 0)
            neg = true;
        
        int n = num;
        string ret = "";
        if (neg)
        {
            n = -num;
            ret += "-";
        }
        
        while ((unsigned long)pow(7, p) <= n)
        {
            p++;
        }
        p--;

        while (p >= 0)
        {
            unsigned int pow7 = (unsigned int)pow(7, p);
            int quot = n / pow7;
            ret += to_string(quot);
            p--;
            n -= pow7 * quot;
        }
        
        return ret;
    }
};

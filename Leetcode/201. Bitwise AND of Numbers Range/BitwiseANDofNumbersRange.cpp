// Leetcode 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
// Runtime: 28ms

class Solution 
{
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        unsigned int ret = m;
        if (m == 0 || n == 0)
        {
            return 0;
        }
        
        if (m == n)
        {
            return m;
        }
        
        unsigned int pow2[] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,
                               65536,131072,262144,524288,1048576,
                               2097152,4194304,8388608,16777216,33554432,
                               67108864,134217728,268435456,536870912,1073741824,2147483648 };
        
        int mgt, ngt;
        for (int i = 0; i < 32; i++)
        {
            if ((unsigned int)m >= pow2[i])
            {
                mgt = i;
            }
            
            if ((unsigned int)n >= pow2[i])
            {
                ngt = i;
            }
            
            if ((unsigned int)m < pow2[i] && (unsigned int)n < pow2[i])
            {
                break;
            }
        }
        
        if (mgt == ngt)
        {
            for (unsigned int i = m + 1; i <= n; i++)
            {
                ret = ret & i;
            }
        }
        else
        {
            ret = 0;
        }
        
        return ret;
    }
};

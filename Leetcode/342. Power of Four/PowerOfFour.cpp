// Leetcode 342. Power of Four
// https://leetcode.com/problems/power-of-four/description/
// Runtime: 4ms

// pre-calculate all of the power of four under the 32bit integer, then binary searched the number
class Solution 
{
public:
    bool isPowerOfFour(int num) 
    {
        int pow4[] = { 1, 
                       4, 
                       16, 
                       64, 
                       256, 
                       1024, 
                       4096, 
                       16384, 
                       65536, 
                       262144, 
                       1048576, 
                       4194304, 
                       16777216, 
                       67108864, 
                       268435456, 
                       1073741824 };
        int b = 0;
        int e = 16;
        int mid = (e - b) / 2;
        
        while (b < e)
        {
            if (num < pow4[mid])
            {
                e = mid;
                mid = (e + b) / 2;
            }
            else if (num > pow4[mid])
            {
                b = mid + 1;
                mid = (e + b) / 2;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};

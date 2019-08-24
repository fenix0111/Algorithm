// Leetcode 728. Self Dividing Numbers
// https://leetcode.com/problems/self-dividing-numbers/
// Runtime: 0ms

class Solution 
{
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> ret;
        for (int i = left; i <= right; i++)
        {
            bool valid = true;
            int n = i;
            int mod = 0;
            while (n > 0)
            {
                mod = n % 10;
                if (mod == 0)
                {
                    valid = false;
                    break;
                }
                
                if (i % mod == 0)
                {
                    n = n / 10;
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
                ret.push_back(i);
        }
        
        return ret;
    }
};

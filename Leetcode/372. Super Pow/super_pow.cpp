// Leetcod 372. Super Pow
// https://leetcode.com/problems/super-pow/

// https://en.wikipedia.org/wiki/Modular_exponentiation
class Solution
{
    int MOD = 1337;
public:   
    int modPow(int base, int exponent)
    {
        int result = 1;
        base = base % MOD;
        while (exponent > 0)
        {
            if ((exponent % 2) == 1)
            {
                result = (result * base) % MOD;
            }
            
            exponent >>= 1;
            base = (base * base) % MOD;
        }
        
        return result;
    }
    
    int superPow(int a, vector<int>& b)
    {
        if (b.empty())
        {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        
        return modPow(superPow(a, b), 10) * modPow(a, last) % MOD;
    }
};

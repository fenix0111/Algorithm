// Leetcode 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/description/
// Runtime: 0ms

class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        int lim = 65535;
        
        // because input num is positive, so we should use unsigned int in the case of overflow
        vector<unsigned int> v;  
        for (int i = 1; i < lim; i++)
        {
            if (i * i <= num)
            {
                v.push_back(i * i);
            }
            else
            {
                break;
            }
        }
        
        return binary_search(v.begin(), v.end(), num);
    }
};

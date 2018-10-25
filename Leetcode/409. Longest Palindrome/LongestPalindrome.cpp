// Leetcode 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/
// Runtime: 4ms

// length of longest palindrome = 
// all of the even num of character + longest odd num of character + all other odd num of character minus 1 to make even
class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        int tbl[128] = { 0 };
        
        for (int i = 0; i < s.size(); i++)
        {
            tbl[s[i]]++;
        }
        
        int ret = 0;
        int max_single = 0;
        int max_idx = 0;
        for (int i = 0; i < 128; i++)
        {
            if (tbl[i] % 2 != 0 && tbl[i] > max_single)
            {
                max_single = tbl[i];
                max_idx = i;
            }
        }
        
        for (int i = 0; i < 128; i++)
        {
            if (tbl[i] % 2 == 0)
            {
                ret += tbl[i];
            }
            else
            {
                if (i != max_idx)
                {
                    if (tbl[i] - 1 > 1)
                    {
                        ret += tbl[i] - 1;
                    }  
                }
            }
        }
        
        ret += max_single;
        
        return ret;
    }
};

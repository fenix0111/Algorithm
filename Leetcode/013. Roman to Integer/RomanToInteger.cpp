// Leetcode 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/description/
// Runtime: 44ms

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int ret = 0;
        int i = 0;
        if (s.empty())
            return 0;
        
        while (i < s.size())
        {
            char c = s[i];
            if (c == 'M')
            {
                ret += 1000;
                i++;
            }
            else if (c == 'D')
            {
                ret += 500;
                i++;
            }
            else if (c == 'C')
            {
                if (i + 1 < s.size() && s[i + 1] == 'M')
                {
                    ret += 900;
                    i += 2;
                    continue;
                }
                
                if (i + 1 < s.size() && s[i + 1] == 'D')
                {
                    ret += 400;
                    i += 2;
                    continue;
                }
                
                ret += 100;
                i++;
            }
            else if (c == 'L')
            {
                ret += 50;
                i++;
            }
            else if (c == 'X')
            {
                if (i + 1 < s.size() && s[i + 1] == 'L')
                {
                    ret += 40;
                    i += 2;
                    continue;
                }
                
                if (i + 1 < s.size() && s[i + 1] == 'C')
                {
                    ret += 90;
                    i += 2;
                    continue;
                }
                
                ret += 10;
                i++;
            }
            else if (c == 'V')
            {
                ret += 5;
                i++;
            }
            else if (c == 'I')
            {
                if (i + 1 < s.size() && s[i + 1] == 'V')
                {
                    ret += 4;
                    i += 2;
                    continue;
                }
                
                if (i + 1 < s.size() && s[i + 1] == 'X')
                {
                    ret += 9;
                    i += 2;
                    continue;
                }
                
                ret += 1;
                i++;
            }
        }
        
        return ret;
    }
};

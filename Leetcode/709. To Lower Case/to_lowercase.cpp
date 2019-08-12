// Leetcode 709. To Lower Case
// https://leetcode.com/problems/to-lower-case/
// Runtime: 0ms

class Solution 
{
public:
    string toLowerCase(string str) 
    {
        string s = str;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]) && s[i] < 'a')
            {
                s[i] += 32;
            }
        }
        
        return s;
    }
};

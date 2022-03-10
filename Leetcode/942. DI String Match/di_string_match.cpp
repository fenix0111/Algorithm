// Leetcode 942. DI String Match
// https://leetcode.com/problems/di-string-match/

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int len = s.length();
        vector<int> result(len + 1, 0);
        
        int inc = 0;
        int dec = len;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'I')
            {
                result[i] = inc;
                inc++;
            }
            else
            {
                result[i] = dec;
                dec--;
            }
        }
        
        result[len] = inc;
        
        return result;
    }
};

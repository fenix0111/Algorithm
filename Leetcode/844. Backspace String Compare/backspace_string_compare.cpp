// Leetcode 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/
// Runtime: 0 ms
// Memory: 6.6 MB

// used stack as auxiliary space
class Solution 
{
public:
    bool backspaceCompare(string S, string T) 
    {
        vector<char> vs;
        vector<char> vt;
        
        for (char c : S)
        {
            if (c == '#')
            {
                if (!vs.empty())
                {
                    vs.pop_back();
                }
            }
            else
            {
                vs.push_back(c);
            }
        }
        
        for (char c : T)
        {
            if (c == '#')
            {
                if (!vt.empty())
                {
                    vt.pop_back();
                }
            }
            else
            {
                vt.push_back(c);
            }
        }
        
        if (vs.size() == vt.size())
        {
            for (int i = 0; i < vs.size(); i++)
            {
                if (vt[i] != vs[i])
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
        
        return true;
    }
};

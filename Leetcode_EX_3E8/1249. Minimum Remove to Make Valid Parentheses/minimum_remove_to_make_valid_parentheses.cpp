// Leetcode 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Runtime: 72 ms
// Memory: 12 MB

// using stack to track index of string s
class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        deque<int> idx;
        string ret = "";
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == '(')
            {
                idx.push_back(i);
            }
            else if (c == ')')
            {
                if (!idx.empty())
                {
                    if (s[idx.back()] == '(')
                    {
                        idx.pop_back();
                    }
                    else
                    {
                        idx.push_back(i);
                    }
                }
                else
                {
                    idx.push_back(i);
                }
            }
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            if (!idx.empty() && i == idx.front())
            {
                idx.pop_front();
            }
            else
            {
                ret.push_back(s[i]);
            }
        }
        
        return ret;
    }
};

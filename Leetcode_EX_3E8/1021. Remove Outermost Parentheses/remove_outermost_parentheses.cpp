// Leetcode 1021. Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int last = 0;
        int match = 0;
        string result = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (match == 0)
            {
                if (i - last > 0)
                {
                    result += s.substr(last + 1, i - last - 2);
                    last = i;
                }
            }
            
            if (s[i] == ')')
            {
                match--;
            }
            else
            {
                match++;
            }
        }
        
        result += s.substr(last + 1, s.length() - last - 2);
        
        return result;
    }
};

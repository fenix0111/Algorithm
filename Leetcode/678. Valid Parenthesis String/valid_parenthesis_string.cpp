// Leetcode 678. Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/
// Runtime: 0 ms

class Solution 
{
public:
    bool checkValidString(string s) 
    {
        int low = 0;
        int high = 0;
        for (char c : s) 
        {
            if (c == '(')
            {
                low++;
                high++;
            }
            else if (c == ')')
            {
                low--;
                high--;
            }
            else
            {
                // c is asterisk
                low--;
                high++;
            }
            
            if (low < 0)
            {
                low = 0;
            }
            
            if (high < 0)
                return false;
        }
        
        return low == 0;
    }
};

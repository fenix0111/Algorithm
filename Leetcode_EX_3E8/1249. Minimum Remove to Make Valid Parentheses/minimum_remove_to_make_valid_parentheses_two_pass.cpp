// solution with two passes
// in first pass, from left to right, increment "match" if current character is '('
// decrement match if current character is ')'. 
// at the same time, keep track of "lowest match", character would be discarded if current match is lower than current lowest
// "lowest" means that if match is greater than or equal to lowest, then it means there is a chance that valid parentheses may exist
// but we cannot sure by only one pass, so we have to scan in reverse order again.

// do the same process again from right to left, but this time increment match when the current character is ')'

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int match = 0;
        int lowest = 0;
        string buf = "";
        for (char c : s)
        {
            if (c == ')')
            {
                match--;
                
                if (match >= lowest)
                {
                    buf.push_back(c);
                }
                
                lowest = min(match, lowest);
            }
            else if (c == '(')
            {
                match++;
                buf.push_back(c);
            }
            else
            {
                buf.push_back(c);
            }
        }
        
        match = 0;
        lowest = 0;
        string result = "";
        for (int i = buf.length() - 1; i >= 0; i--)
        {
            char c= buf[i];
            if (c == '(')
            {
                match--;
                
                if (match >= lowest)
                {
                    result.push_back(c);
                }
                
                lowest = min(match, lowest);
            }
            else if (c == ')')
            {
                match++;
                result.push_back(c);
            }
            else
            {
                result.push_back(c);
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

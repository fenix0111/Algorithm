// Leetcode 520. Detect Capital
// https://leetcode.com/problems/detect-capital/
// Runtime: 4ms

class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        int sz = word.size();
        char c;
        int lower = 0;
        int upper = 0;
        bool cap = false;
        
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            upper++;
            cap = true;
        }
        else
        {
            lower++;
        }
        
        for (unsigned int i = 1; i < sz; i++)
        {
            c = word[i];
            if (c >= 'A' && c <= 'Z')
                upper++;
            else
                lower++;
        }
        
        // only first letter is upper case
        if (cap && upper == 1)
            return true;
        
        if (lower == sz || upper == sz)
            return true;
    
        return false;
    }
};

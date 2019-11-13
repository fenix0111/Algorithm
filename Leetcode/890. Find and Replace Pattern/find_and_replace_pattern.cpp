// Leetcode 890. Find and Replace Pattern
// https://leetcode.com/problems/find-and-replace-pattern/
// Runtime: 4ms

// using two dictionaries
class Solution 
{
public:
    void clear_tbl(int *tbl, int n)
    {
        for (int i = 0; i < n; i++)
        {
            tbl[i] = 0;
        }
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ret;
        int tbl[26] = { 0 };  // word -> pattern
        int sz = pattern.size();
        
        int comp[26] = { 0 };  // pattern -> word
        
        for (string s : words)
        {
            bool valid = true;
            clear_tbl(tbl, 26);
            clear_tbl(comp, 26);
            
            for (int i = 0; i < sz; i++)
            {
                if (tbl[s[i] - 'a'] != 0 && tbl[s[i] - 'a'] != pattern[i])
                {
                    valid = false;
                    break;
                }
                
                if (comp[pattern[i] - 'a'] != 0 && comp[pattern[i] - 'a'] != s[i])
                {
                    valid = false;
                    break;
                }
                
                tbl[s[i] - 'a'] = pattern[i];
                comp[pattern[i] - 'a'] = s[i];
            }
            
            if (valid)
            {
                ret.push_back(s);
            }
        }
        
        return ret;
    }
};

// Leetcode 784. Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/
// Runtime: 8ms

class Solution 
{
public:
    void helper(string &s, int i, vector<string> &v)
    {
        if (i == s.size())
        {
            v.push_back(s);
            return;
        }
        
        if (isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            helper(s, i + 1, v);
            
            s[i] = toupper(s[i]);
            helper(s, i + 1, v);
        }
        else
        {
            helper(s, i + 1, v);
        }
    }
    
    vector<string> letterCasePermutation(string S) 
    {
        vector<string> ret;
        helper(S, 0, ret);
        
        return ret;
    }
};

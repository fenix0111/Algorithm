// Leetcode 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/
// Runtime: 348ms (extremely slow..)

class Solution 
{
public:
    bool is_palindrom(const string &s)
    {
        int beg = 0;
        int end = s.size() - 1;
        while (beg < end)
        {
            if (s[beg] != s[end])
            {
                return false;
            }
            beg++;
            end--;
        }
        return true;
    }
    
    int countSubstrings(string s) 
    {
        int sz = s.size();
        vector<int> tbl(sz, 0);
        tbl[0] = 1;
        
        for (int i = 1; i < sz; i++)
        {
            tbl[i] = tbl[i - 1] + 1;
            int n = i - 1;
            while (n >= 0)
            {
                if (s[n] != s[i])
                {
                    n--;
                    continue;
                }
                
                string tmps = s.substr(n, i - n + 1);
                if (is_palindrom(tmps))
                {
                    tbl[i]++;
                }
                n--;
            }
        }
        
        return tbl[sz - 1];
    }
};

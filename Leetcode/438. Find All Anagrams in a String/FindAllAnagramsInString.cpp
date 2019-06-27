// Leetcode 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Runtime: 28ms

class Solution {
public:
    bool is_anagram(int *src, int *dst)
    {
        for (int i = 0; i < 26; i++)
        {
            if (src[i] != dst[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) 
    {
        int ssz = s.size();
        int psz = p.size();
        vector<int> ret;
        
        if (s.empty() || ssz < psz)
            return ret;
        
        int tbl[26] = { 0 };
        int stb[26] = { 0 };
        
        // init source table
        for (int i = 0; i < psz; i++)
        {
            stb[s[i] - 97] += 1;
        }
        
        for (int i = 0; i < psz; i++)
        {
            tbl[p[i] - 97] += 1;
        }
        
        for (int i = 0; i <= ssz - psz; i++)
        {
            if (i > 0)
            {
                stb[s[i - 1] - 97] -= 1;
                stb[s[i + psz - 1] - 97] += 1;
            }
            
            if (is_anagram(stb, tbl))
                ret.push_back(i);
        }
        
        return ret;
    }
};

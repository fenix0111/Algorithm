// Leetcode 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// time complexity: O(len(s) + len(p))
// space complexity: O(len(s) + len(p))

class Solution
{
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
        
        int p_tbl[26] = { 0 };
        int s_tbl[26] = { 0 };
        
        // init source table
        for (int i = 0; i < psz; i++)
        {
            s_tbl[s[i] - 97] += 1;
        }
        for (int i = 0; i < psz; i++)
        {
            p_tbl[p[i] - 97] += 1;
        }
        
        for (int i = 0; i <= ssz - psz; i++)
        {
            if (i > 0)
            {
                s_tbl[s[i - 1] - 97] -= 1;
                s_tbl[s[i + psz - 1] - 97] += 1;
            }
            
            if (is_anagram(s_tbl, p_tbl))
            {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
};

// Leetcode 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/
// Runtime: 8ms

// intuitively could be solve by "sorting & comparing"
// but we could use bucket to improve running time
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        
        int bkts[26] = {0};
        int bktt[26] = {0};
        
        for (int i = 0; i < s.size(); i++)
        {
            bkts[s[i] - 97] += 1;
        }
        
        for (int i = 0; i < t.size(); i++)
        {
            bktt[t[i] - 97] += 1;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (bkts[i] != bktt[i])
            {
                return false;
            }
        }
        
        return true;
    }
};

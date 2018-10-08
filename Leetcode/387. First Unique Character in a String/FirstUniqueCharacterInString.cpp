// Leetcode 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Runtime: 28ms

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        int tbl[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            tbl[s[i] - 'a'] += 1;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (tbl[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};

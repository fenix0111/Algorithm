// Leetcode 383. Ransom Note
// https://leetcode.com/problems/ransom-note/description/
// Runtime: 16ms

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unsigned short tbl[128] = {0};
        for (int i = 0; i < magazine.size(); i++)
        {
            tbl[magazine[i]] += 1;
        }
        
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (tbl[ransomNote[i]] == 0)
            {
                return false;
            }
            else
            {
                tbl[ransomNote[i]] -= 1;
            }
        }
        
        return true;
    }
};

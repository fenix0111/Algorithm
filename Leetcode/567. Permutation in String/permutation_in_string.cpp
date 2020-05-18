// Leetcode 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/
// time complexity: O(n2)
// space complexity: O(n)

class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.length() > s2.length())
            return false;
        
        int* tbls1 = (int*)malloc(sizeof(int) * 26);
        int* tbls2 = (int*)malloc(sizeof(int) * 26);
        for (int i = 0; i < 26; i++)
        {
            tbls1[i] = 0;
            tbls2[i] = 0;
        }
        
        for (int i = 0; i < s1.length(); i++)
        {
            tbls1[s1[i] - 'a']++;
        }
        
        if (s1.length() == s2.length())
        {
            for (int j = 0; j < s1.length(); j++)
            {
                tbls2[s2[j] - 'a']++;
            }
            
            for (int j = 0; j < 26; j++)
            {
                if (tbls1[j] != tbls2[j])
                {
                    return false;
                }
            }

            return true;
        }
        
        for (int i = 0; i <= s2.length() - s1.length(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < s1.length(); j++)
                {
                    tbls2[s2[i + j] - 'a']++;
                }
            }
            
            if (i > 0)
            {
                tbls2[s2[i - 1] - 'a']--;
                tbls2[s2[i + s1.length() - 1] - 'a']++;
            }
            
            bool valid = true;
            for (int j = 0; j < 26; j++)
            {
                if (tbls1[j] != tbls2[j])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                return true;
            }
        }
        
        return false;
    }
};

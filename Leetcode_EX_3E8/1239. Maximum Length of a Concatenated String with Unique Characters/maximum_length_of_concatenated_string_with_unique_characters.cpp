// Leetcode 1239. Maximum Length of a Concatenated String with Unique Characters
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// time complexity: 
// space complexity: O(N)

class Solution 
{
public:
    void find(vector<string>& arr, int index, bool* tbl, int& maxlen, int slen)
    {
        if (index < arr.size())
        {
            for (int i = index; i < arr.size(); i++)
            {
                bool valid = true;
                string& str = arr[i];
                int pos = 0;
                for (int j = 0; j < str.length(); j++)
                {
                    char c = str[j];
                    if (tbl[c - 'a'])
                    {
                        valid = false;
                        pos = j; // revert check point
                        break;
                    }
                    else
                    {
                        tbl[c - 'a'] = true;
                    }
                }

                if (valid)
                {
                    for (char c : str)
                    {
                        tbl[c - 'a'] = true;
                    }
 
                    // update max length before end of the loop
                    if (slen + str.length() > maxlen)
                    {
                        maxlen = slen + str.length();
                    }
                    
                    find(arr, i + 1, tbl, maxlen, slen + str.length());
                    
                    for (char c : str)
                    {
                        tbl[c - 'a'] = false;
                    }
                }
                else
                {                    
                    if (slen > maxlen)
                    {
                        maxlen = slen;
                    }
                    
                    // revert
                    for (int j = 0; j < pos; j++)
                    {
                        char c = str[j];
                        tbl[c - 'a'] = false;
                    }
                }
            }
        } 
    }
    
    int maxLength(vector<string>& arr) 
    {
        int maxlen = 0;
        bool* tbl = new bool[26];
        for (int i = 0; i < 26; i++)
        {
            tbl[i] = false;
        }
        
        find(arr, 0, tbl, maxlen, 0);
        
        return maxlen;
    }
};

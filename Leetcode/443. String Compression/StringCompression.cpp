// Leetcode 443. String Compression
// https://leetcode.com/problems/string-compression/
// Runtime: 4ms

class Solution 
{
public:
    int compress(vector<char>& chars) 
    {
        if (chars.size() < 2)
            return chars.size();
        
        int pos = 0;  // position for insertion
        char lastc = chars[0];
        
        int len = 0;  // length of same characters
        for (int i = 0; i < chars.size(); i++)
        {
            if (chars[i] != lastc)
            {
                if (len != 1)
                {
                    if (len >= 100)
                    {
                        int c = len / 100;
                        len %= 100;
                        int d = len / 10;
                        len %= 10;
                        chars[pos++] = lastc;
                        chars[pos++] = c + 48;
                        chars[pos++] = d + 48;
                        chars[pos++] = len + 48;
                    }
                    else if (len >= 10)
                    {
                        int d = len / 10;
                        len %= 10;
                        chars[pos++] = lastc;
                        chars[pos++] = d + 48;
                        chars[pos++] = len + 48;
                    }
                    else 
                    {
                        chars[pos++] = lastc;
                        chars[pos++] = len + 48;
                    }
                }
                else
                {
                    chars[pos++] = lastc;
                }
                
                len = 1;
                lastc = chars[i];
            }
            else
            {
                len++;
            }
        }
        
        if (len > 1)
        {
            if (len >= 100)
            {
                int c = len / 100;
                len %= 100;
                int d = len / 10;
                len %= 10;
                chars[pos++] = lastc;
                chars[pos++] = c + 48;
                chars[pos++] = d + 48;
                chars[pos++] = len + 48;
            }
            else if (len >= 10)
            {
                int d = len / 10;
                len %= 10;
                chars[pos++] = lastc;
                chars[pos++] = d + 48;
                chars[pos++] = len + 48;
            }
            else 
            {
                chars[pos++] = lastc;
                chars[pos++] = len + 48;
            }
        }
        else
        {
            chars[pos++] = lastc;
        }
        
        return pos;
    }
};

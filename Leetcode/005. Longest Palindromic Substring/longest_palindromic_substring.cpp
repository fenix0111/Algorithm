class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int len = s.length();
        int result = 0;
        int left, right;
        for (int i = 0; i < len; i++)
        {
            int l = i;
            int r = i;
            
            // check the type like "aba"
            while (l >= 0 && r < len)
            {
                if (s[l] == s[r])
                {
                    if (r - l + 1 > result)
                    {
                        result = r - l + 1;
                        left = l;
                        right = r;
                    }
                    
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            
            // check the type like "abba"
            l = i;
            r = i + 1;
            while (l >= 0 && r < len)
            {
                if (s[l] == s[r])
                {
                    if (r - l + 1 > result)
                    {
                        result = r - l + 1;
                        left = l;
                        right = r;
                    }
                    
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
        }
        
        if (result == 0)
        {
            return "";
        }
        else
        {
            return s.substr(left, right - left + 1);
        }
    }
};

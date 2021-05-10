// Leetcode 906. Super Palindromes
// https://leetcode.com/problems/super-palindromes/
// 
// 

// we could guess that around 200000000 would close to the limit(pow(10,18))
// maximum square root of number, which is also a palindrome, under pow(10,18) is 200010002
class Solution 
{
public:
    bool isPalindrome(string& str)
    {
        int l = 0;
        int r = str.length() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
    
    int superpalindromesInRange(string left, string right) 
    {
        unsigned long long left_ull = stoull(left);
        unsigned long long right_ull = stoull(right);
        
        int result = 0;
        
        // even length
        for (unsigned int i = 1; i <= 2200; i++)
        {            
            string s = to_string(i);
            int len = s.length();
            
            for (int k = len - 1; k >= 0; k--)
            {                
                s.push_back(s[k]);
            }
            
            if (isPalindrome(s))
            {
                unsigned long long num = stoull(s);
                unsigned long long pow = num * num;

                if (pow >= left_ull && pow <= right_ull)
                {
                    string powstr = to_string(pow);
                    if (isPalindrome(powstr))
                    {
                        result++;
                    }
                }
                
                if (pow > right_ull)
                {
                    break;
                }
            }
        }
        
        // odd length
        for (unsigned int i = 1; i <= 2200; i++)
        {
            // number in the middle can only be 0, 1 and 2
            for (unsigned int j = 0; j <= 2; j++)
            {
                string s = to_string(i);
                s.push_back(j + '0');
                int len = s.length();
                for (int k = len - 2; k >= 0; k--)
                {
                    s.push_back(s[k]);
                }

                if (isPalindrome(s))
                {
                    unsigned long long num = stoull(s);
                    unsigned long long pow = num * num;
                
                    if (pow >= left_ull && pow <= right_ull)
                    {
                        string powstr = to_string(pow);
                        if (isPalindrome(powstr))
                        {
                            result++;
                        }
                    }

                    if (pow > right_ull)
                    {
                        goto last;
                    }
                }
            }
        }
        
last:
        if (left_ull <= 1 && 1 <= right_ull)
        {
            result++;
        }
        
        if (left_ull <= 4 && 4 <= right_ull)
        {
            result++;
        }
        
        if (left_ull <= 9 && 9 <= right_ull)
        {
            result++;
        }
        
        return result;
    }
};

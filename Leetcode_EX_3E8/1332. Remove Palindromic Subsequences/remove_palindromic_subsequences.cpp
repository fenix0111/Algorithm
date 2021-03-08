// Leetcode 1332. Remove Palindromic Subsequences
// https://leetcode.com/problems/remove-palindromic-subsequences/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    int removePalindromeSub(string s) 
    {
        if (s.length() == 0)
        {
            return 0;
        }
        
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return 2;
            }
        }
        
        return 1;
    }
};

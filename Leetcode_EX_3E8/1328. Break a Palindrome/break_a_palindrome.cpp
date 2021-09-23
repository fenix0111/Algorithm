// Leetcode 1328. Break a Palindrome
// https://leetcode.com/problems/break-a-palindrome/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    string breakPalindrome(string palindrome) 
    {
        if (palindrome.length() == 1)
        {
            return "";
        }
        
        int i = 0;
        bool dirty = false;
        while (i < (palindrome.length() / 2))
        {
            if (palindrome[i] != 'a')
            {
                dirty = true;
                palindrome[i] = 'a';
                break;
            }
            i++;
        }
        
        if (!dirty)
        {
            palindrome[palindrome.length() - 1] = 'b';
        }
        
        return palindrome;
    }
};

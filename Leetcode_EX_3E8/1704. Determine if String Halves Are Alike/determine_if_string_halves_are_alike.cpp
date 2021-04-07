// Leetcode 1704. Determine if String Halves Are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    bool isVowel(char c)
    {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || 
                (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
    }
    
    bool halvesAreAlike(string s) 
    {
        int l = 0;
        int r = s.length() - 1;
        int leftVowels = 0;
        int rightVowels = 0;
        
        while (l < r)
        {
            if (isVowel(s[l]))
            {
                leftVowels++;
            }
            
            if (isVowel(s[r]))
            {
                rightVowels++;
            }
            
            l++;
            r--;
        }
        
        return leftVowels == rightVowels;
    }
};

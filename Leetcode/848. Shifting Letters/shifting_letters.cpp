// Leetcode 848. Shifting Letters
// https://leetcode.com/problems/shifting-letters/
// time complexity: O(n)
// space complexity: O(n)

class Solution 
{
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int size = s.length();
        for (int i = size - 1; i > 0; i--)
        {
            // watch out for overflow
            shifts[i - 1] += (shifts[i] % 26);
        }
        
        string result = s;
        for (int i = size - 1; i >= 0; i--)
        {
            result[i] = (s[i] - 'a' + shifts[i] % 26) % 26 + 'a';
        }
                
        return result;
    }
};

// Leetcode 1456. Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int result = 0;
        int current_counts = 0;
        for (int i = 0; i < k; i++)
        {
            if (is_vowel(s[i]))
            {
                result++;
            }
        }

        current_counts = result;

        for (int i = k; i < s.length(); i++)
        {
            if (is_vowel(s[i - k]))
            {
                current_counts--;
            }

            if (is_vowel(s[i]))
            {
                current_counts++;
            }

            result = max(result, current_counts);
        }

        return result;
    }

    bool is_vowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

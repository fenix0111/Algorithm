// Leetcode 917. Reverse Only Letters
// https://leetcode.com/problems/reverse-only-letters/
// time complexity: O(n)
// space complexity: O(1)

class Solution 
{
public:
    void swap(string& s, int i, int j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    
    string reverseOnlyLetters(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            if (isalpha(s[left]) && isalpha(s[right]))
            {
                swap(s, left, right);
                left++;
                right--;
            }
            else
            {
                if (!isalpha(s[left]))
                {
                    left++;
                }
                
                if (!isalpha(s[right]))
                {
                    right--;
                }
            }
        }
        
        return s;
    }
};

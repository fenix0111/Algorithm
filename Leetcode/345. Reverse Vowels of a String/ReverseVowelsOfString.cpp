// Leetcode 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
// Runtime: 8ms

class Solution 
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) 
    {
        stack<char> st;
        string ret;
        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                st.push(s[i]);
            }
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                char c = st.top();
                ret.append(1, c);
                st.pop();
            }
            else
            {
                ret.append(1, s[i]);
            }
        }
        
        return ret;
    }
};

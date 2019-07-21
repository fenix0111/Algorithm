// Leetcode 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Runtime: 24ms

class Solution 
{
public:
    string reverseWords(string s) 
    {
        stack<char> buf;
        int i = 0;
        string ret = "";
        while (i < s.size())
        {
            if (s[i] != ' ')
            {
                buf.push(s[i]);
            }
            else
            {
                while (!buf.empty())
                {
                    ret += buf.top();
                    buf.pop();
                }
                ret += " ";
            }
            i++;
        }
        
        while (!buf.empty())
        {
            ret += buf.top();
            buf.pop();
        }
        
        return ret;
    }
};

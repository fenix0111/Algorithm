// Leetcode 1544. Make The String Great
// https://leetcode.com/problems/make-the-string-great/
// time complexity: O(N)
// space complexity: O(N)

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> buf;
        for (char c : s)
        {
            if (buf.empty())
            {
                buf.push(c);
                continue;
            }
            
            char top = buf.top();
            if (top - 32 == c || top + 32 == c)
            {
                buf.pop();
            }
            else
            {
                buf.push(c);
            }
        }
        
        int sz = buf.size();
        string result;
        result.assign(sz, 0);
        
        int i = sz - 1;
        while (!buf.empty())
        {
            result[i] = buf.top();
            buf.pop();
            i--;
        }
        
        return result;
    }
};

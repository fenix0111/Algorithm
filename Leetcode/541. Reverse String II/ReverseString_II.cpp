// Leetcode 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/
// Runtime: 4ms

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        string ret = "";
        int sz = s.size();
        int i = 0;
        stack<char> st;
        int c = 1;
        while (i < sz)
        {
            if (c > 2 * k)
            {
                c = 1;
            }
            else if (c > k)
            {
                while (!st.empty())
                {
                    ret += st.top();
                    st.pop();
                }
            }
            
            if (c <= k)
            {
                st.push(s[i]);
            }
            else if (c <= 2 * k)
            {
                ret += s[i];
            }
            
            c++;
            i++;
        }
        
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        
        return ret;
    }
};

// Leetcode 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Runtime: 4ms

class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        if (S.size() == 0)
        {
            return 0;
        }
        
        stack<char> st;
        for (int i = 0; i < S.size(); i++)
        {
            if (st.empty())
            {
                st.push(S[i]);
                continue;
            }
            
            if (S[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(S[i]);
                }
            }
            else
            {
                st.push(S[i]);
            }
        }
        
        return st.size();
    }
};

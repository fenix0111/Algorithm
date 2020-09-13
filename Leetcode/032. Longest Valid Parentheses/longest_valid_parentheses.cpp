// Leetcode 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
// time complexity: O(length of s)
// space complexity: O(length of s)

// in auxiliary table, if left parentheses have no matching right parentheses
// it would be marked as -1
// count the length between two position marked as -1, find the longest one

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        int max = 0;
        vector<int> tbl(s.length(), -1);
        
        for (int i = 0; i < s.length(); i++)
        {         
            char c = s[i];
            if (c == '(')
            {
                st.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    int lp = st.top();
                    if (s[lp] == '(')
                    {
                        st.pop();
                        tbl[lp] = i;
                        tbl[i] = lp;
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else
                {
                    st.push(i);
                }
            }
        }
        
        int left = 0;
        for (int i = 0; i < tbl.size(); i++)
        {
            if (tbl[i] == -1)
            {
                if (i - left > max)
                {
                    max = i - left;
                }
                left = i + 1;
            }
        }
        
        if (tbl.size() - left > max)
        {
            max = tbl.size() - left;
        }
        
        return max;
    }
};

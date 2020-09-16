// Leetcode 856. Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses/
// time complexity: O(length of S)
// space complexity: O(length of S)

class Solution 
{
public:
    int scoreOfParentheses(string S) 
    {
        stack<int> st;  // because of '(' and ')', I treat the result as negative to differentiate from parentheses
        for (char c : S)
        {
            if (st.empty())
            {
                st.push(c);
            }
            else
            {
                if ((char)st.top() == '(')
                {
                    if (c == ')')
                    {
                        st.pop();
                        
                        int sum = -1;
                        while (!st.empty() && st.top() != '(' && st.top() != ')')
                        {
                            sum += st.top();
                            st.pop();
                        }
                        
                        if (sum < 0)
                        {
                            st.push(sum);
                        }
                    }
                    else
                    {
                        st.push(c);
                    }
                }
                else
                {
                    // multiply with 2
                    if (c == ')')
                    {
                        int sum = 0;
                        while (!st.empty() && st.top() != '(' && st.top() != ')')
                        {
                            sum += st.top();
                            st.pop();
                        }
                        
                        st.pop(); // pop '('
                        if (sum < 0)
                        {
                            st.push(sum * 2);
                        }
                    }
                    else
                    {
                        st.push(c);
                    }
                }
            }
        }
        
        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        
        return -result;
    }
};

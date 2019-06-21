// Leetcode 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/
// Runtime: 192ms

// using stack, then compare
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        int idx = 1;
        int sz = T.size();
        stack<int> st;
        st.push(0);
        vector<int> ret(sz, 0);
        while (idx < sz)
        {
            int top = st.top();
            if (T[top] < T[idx])
            {
                st.pop();
                ret[top] = idx - top;
                if (st.empty())
                {
                    st.push(idx);
                    idx++;
                }
            }
            else
            {
                st.push(idx);
                idx++;
            }
        }
        
        return ret;
    }
};

// Leetcode 779. K-th Symbol in Grammar
// https://leetcode.com/problems/k-th-symbol-in-grammar/
// time complexity: O(n)
// space complexity: O(n)

// first, track the change of position(here denoted as k)
// then, adjust the result according to position
// if position in the next row is equal to double of position in the current row
// then flip the result(0->1 or 1->0)
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        }
        
        stack<int> st;
        st.push(k);
        
        while (n > 2)
        {            
            if (k > pow(2, n - 2))
            {
                if (k % 2 == 1)
                {
                    k = (k + 1) / 2;
                }
                else
                {
                    k /= 2;
                }
            }
                        
            st.push(k);
            n--;
        }
        
        int result = 0;
        int pos = 1;
        while (!st.empty())
        {
            int p = st.top();  
            st.pop();
            
            if (pos * 2 == p)
            {
                if (result == 0)
                {
                    result = 1;
                }
                else
                {
                    result = 0;
                }
            }
            
            pos = p;
        }
        
        return result;
    }
};

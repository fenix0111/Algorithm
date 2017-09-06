// Leetcode 66. Plus One
// https://leetcode.com/problems/plus-one/description/
// Runtime: 6ms

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        bool isCarry = false;
		bool isFirst = true;
        stack<int> st;
        for (vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); rit++)
        {
            int num;
            if (isFirst)
            {
                if (*rit == 9)
                {
                    num = 0;
                    isCarry = true;
                }
                else
                {
                    num = *rit + 1;
                    isCarry = false;
                }
                isFirst = false;
            }
            else
            {
                if (isCarry)
                {
                    if (*rit == 9)
                    {
                        num = 0;
                    }
                    else
                    {
                        num = *rit + 1;
                        isCarry = false;
                    }
                }
                else
                {
                    num = *rit;
                }
            }
            
            st.push(num);
        }
        
        if (isCarry)
        {
            st.push(1);
        }

        vector<int> res;
        while (!st.empty()) 
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
    
    // 3ms 参考解法
    vector<int> plusOne(vector<int>& digits) 
    {
        int i = digits.size()-1;
        int carry = 1;
        while (i >= 0 && carry == 1)
        {
            digits[i] ++;
            if (digits[i] == 10)
            {
                digits[i] = 0;
            }
            else
            {
                carry = 0;
            }
            i--;
            
        }
        if (carry == 1) 
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};

// Leetcode 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/
// Runtime: 24ms (slow)

class Solution 
{
public:
    bool is_operator(char c)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool is_mul(char c)
    {
        if (c == '*' || c == '/')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int calculate(string s) 
    {
        deque<int> nums;  // deque is faster than list in this problem
        deque<char> ops;
        
        string num = "";
        for (char c : s)
        {
            if (c != ' ')
            {
                if (is_operator(c))
                {
                    nums.push_back(stoi(num));
                    num.clear();
                    
                    if (!ops.empty())
                    {
                        char last_op = ops.back();
                        if (is_mul(last_op))
                        {
                            int num2 = nums.back();
                            nums.pop_back();
                            int num1 = nums.back();
                            nums.pop_back();
                            
                            if (last_op == '*')
                            {
                                nums.push_back(num1 * num2);
                            }
                            else
                            {
                                nums.push_back(num1 / num2);   
                            }
                            ops.pop_back();
                        }
                    }
                    ops.push_back(c);
                }
                else
                {
                    num += c;
                }
            }
        }
        
        // last number
        nums.push_back(stoi(num));
        
        while (!ops.empty())
        {
            char op = ops.back();
            if (is_mul(op))
            {
                int num2 = nums.back();
                nums.pop_back();
                int num1 = nums.back();
                nums.pop_back();
                
                if (op == '*')
                {
                    nums.push_back(num1 * num2);
                }
                else
                {
                    nums.push_back(num1 / num2);
                }
                ops.pop_back();
            }
            else
            {
                op = ops.front();
                int num1 = nums.front();
                nums.pop_front();
                int num2 = nums.front();
                nums.pop_front();
                
                if (op == '+')
                {
                    nums.push_front(num1 + num2);
                }
                else
                {
                    nums.push_front(num1 - num2);
                }
                ops.pop_front();
            }
        }
        
        return nums.front();
    }
};

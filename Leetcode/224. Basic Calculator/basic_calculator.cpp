// Leetcode 224. Basic Calculator
// https://leetcode.com/problems/basic-calculator/
// time complexity: O(n)
// space complexity: O(n)

// ugly but works
class Solution 
{
    int i = 0;
public:
    int calculate(string s) 
    {
        int result = 0;
        stack<char> ops;
        stack<int> nums;
        int parenthesis = 0;
        while (i < s.length())
        {
            if (s[i] == '(')
            {
                i++;
                int num = calculate(s);
                if (ops.empty())
                {
                    nums.push(num);
                }
                else
                {
                    if (nums.empty())
                    {
                        nums.push(-num);
                        continue;
                    }
                    int x = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    if (op == '+')
                    {
                        nums.push(x + num);
                    }
                    else
                    {
                        nums.push(x - num);
                    }
                }
            }
            else if (s[i] == ')')
            {
                i++;
                return nums.top();
            }
            else if (s[i] == '+')
            {
                ops.push(s[i]);
                i++;
            }
            else if (s[i] == '-')
            {
                ops.push(s[i]);
                i++;
            }
            else if (s[i] == ' ')
            {
                i++;
            }
            else
            {
                int num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    num *= 10;
                    num += (s[i] - '0');
                    i++;
                }
                
                if (ops.empty())
                {
                    nums.push(num);
                }
                else
                {
                    if (nums.empty())
                    {
                        nums.push(-num);
                        continue;
                    }
                    int x = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    if (op == '+')
                    {
                        nums.push(x + num);
                    }
                    else
                    {
                        nums.push(x - num);
                    }
                }
            }
        }
        
        return nums.top();
    }
};

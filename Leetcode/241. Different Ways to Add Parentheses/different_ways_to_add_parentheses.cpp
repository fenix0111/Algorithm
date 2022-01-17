// Leetcode 241. Different Ways to Add Parentheses
// https://leetcode.com/problems/different-ways-to-add-parentheses/
// time complexity: 
// space complexity: O(n)

// divide and conquer
class Solution
{
public:    
    bool isOp(char c)
    {
        return c == '+' || c == '-' || c == '*';
    }
    
    vector<int> calculate(const string& expression, int begin, int end)
    {
        vector<int> buf;
        string numstr = "";
        for (int i = begin; i < end; i++)
        {
            char c = expression[i];
            numstr.push_back(c);
            
            if (isOp(c))
            {
                numstr = "";
                
                vector<int> left = calculate(expression, begin, i);
                vector<int> right = calculate(expression, i + 1, end);
                if (c == '+')
                {
                    for (int j = 0; j < left.size(); j++)
                    {
                        for (int k = 0; k < right.size(); k++)
                        {
                            buf.push_back(left[j] + right[k]);
                        }
                    }
                }
                else if (c == '-')
                {
                    for (int j = 0; j < left.size(); j++)
                    {
                        for (int k = 0; k < right.size(); k++)
                        {
                            buf.push_back(left[j] - right[k]);
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < left.size(); j++)
                    {
                        for (int k = 0; k < right.size(); k++)
                        {
                            buf.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        
        if (buf.empty())
        {
            buf.push_back(atoi(numstr.c_str()));
        }
        
        return buf;
    }
    
    vector<int> diffWaysToCompute(string expression)
    {
        return calculate(expression, 0, expression.length());
    }
};

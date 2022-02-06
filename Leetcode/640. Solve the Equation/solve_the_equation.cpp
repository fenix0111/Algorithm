// Leetcode 640. Solve the Equation
// https://leetcode.com/problems/solve-the-equation/
// time complexity: O(N)
// space complexity: O(!)

// need to refactoring
// take care of these cases: 2X, 0X, +8X etc.
class Solution
{
public:
    string solveEquation(string equation) 
    {
        int leftX = 0;
        int rightX = 0;
        int leftSum = 0;
        int rightSum = 0;
        
        int i = 0;
        int len = equation.length();
        while (equation[i] != '=')
        {
            if (equation[i] == 'x')
            {
                leftX++;
                i++;
            }
            else if (isdigit(equation[i]))
            {
                int num = 0;
                
                while (i < len && isdigit(equation[i]))
                {
                    num *= 10;
                    num += (equation[i] - '0');
                    i++;
                }
                
                // like 2X
                if (equation[i] == 'x')
                {
                    leftX += num;
                    i++;
                }
                else
                {
                    leftSum += num;
                }
            }
            else
            {
                if (equation[i] == '+')
                {
                    i++;
                    int num = 0;
                    if (equation[i] != '0')
                    {
                        while (isdigit(equation[i]))
                        {
                            num *= 10;
                            num += (equation[i] - '0');
                            i++;
                        }

                        // like 2X
                        if (equation[i] == 'x')
                        {
                            leftX += (num == 0 ? 1 : num);
                            i++;
                        }
                        else
                        {
                            leftSum += num;
                        }
                    }
                    else
                    {
                        i++;
                        if (i < len && equation[i] == 'x')
                        {
                            i++;
                        }
                    }
                }
                else if (equation[i] == '-')
                {
                    i++;
                    int num = 0;
                    if (equation[i] != '0')
                    {
                        while (isdigit(equation[i]))
                        {
                            num *= 10;
                            num += (equation[i] - '0');
                            i++;
                        }

                        // like 2X
                        if (equation[i] == 'x')
                        {
                            leftX -= (num == 0 ? 1 : num);
                            i++;
                        }
                        else
                        {
                            leftSum -= num;
                        }
                    }
                    else
                    {
                        i++;
                        if (i < len && equation[i] == 'x')
                        {
                            i++;
                        }
                    }
                }
            }
        }
        
        i++;
        while (i < len)
        {
            if (equation[i] == 'x')
            {
                rightX++;
                i++;
            }
            else if (isdigit(equation[i]))
            {
                int num = 0;
                while (i < len && isdigit(equation[i]))
                {
                    num *= 10;
                    num += (equation[i] - '0');
                    i++;
                }
                
                if (equation[i] == 'x')
                {
                    rightX += num;
                    i++;
                }
                else
                {
                    rightSum += num;
                }
            }
            else
            {
                if (equation[i] == '+')
                {
                    i++;
                    int num = 0;
                    
                    if (equation[i] != '0')
                    {
                        while (isdigit(equation[i]))
                        {
                            num *= 10;
                            num += (equation[i] - '0');
                            i++;
                        }

                        // like 2X
                        if (equation[i] == 'x')
                        {
                            rightX += (num == 0 ? 1 : num);
                            i++;
                        }
                        else
                        {
                            rightSum += num;
                        }
                    }
                    else
                    {
                        i++;
                        if (i < len && equation[i] == 'x')
                        {
                            i++;
                        }
                    }
                    
                }
                else if (equation[i] == '-')
                {
                    i++;
                    int num = 0;
                    if (equation[i] != '0')
                    {
                        while (isdigit(equation[i]))
                        {
                            num *= 10;
                            num += (equation[i] - '0');
                            i++;
                        }

                        // like 2X
                        if (equation[i] == 'x')
                        {
                            rightX -= (num == 0 ? 1 : num);
                            i++;
                        }
                        else
                        {
                            rightSum -= num;
                        }
                    }
                    else
                    {
                        i++;
                        if (i < len && equation[i] == 'x')
                        {
                            i++;
                        }
                    }
                }
            }
        }
        
        if (leftSum == rightSum && leftX == rightX)
        {
            return "Infinite solutions";
        }
        
        if (leftSum != rightSum && leftX == rightX)
        {
            return "No solution";
        }
        
        if (leftX > rightX)
        {
            int diffX = leftX - rightX;
            int diffSum = rightSum - leftSum;
            int X = diffSum / diffX;
            return "x=" + to_string(X);
        }
        else
        {
            int diffX = rightX - leftX;
            int diffSum = leftSum - rightSum;
            int X = diffSum / diffX;
            return "x=" + to_string(X);
        }
    }
};

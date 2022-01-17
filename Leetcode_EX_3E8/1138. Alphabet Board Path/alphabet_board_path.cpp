// Leetcode 1138. Alphabet Board Path
// https://leetcode.com/problems/alphabet-board-path/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    string findPath(char last, char c)
    {
        string path = "";
        int last_x, last_y, x, y;
        last_x = (last - 'a') % 5;
        last_y = (last - 'a') / 5;
        
        x = (c - 'a') % 5;
        y = (c - 'a') / 5;
        
        int diff_x = abs(last_x - x);
        int diff_y = abs(last_y - y);
        
        // take care when staring point is 'z'
        // since cannot go out of the boundary, going up is the only option
        if (last == 'z')
        {
            if (last_y > y)
            {
                while (diff_y > 0)
                {
                    path.push_back('U');
                    diff_y--;
                }
            }
            else
            {
                while (diff_y > 0)
                {
                    path.push_back('D');
                    diff_y--;
                }
            }
            
            if (last_x > x)
            {
                while (diff_x > 0)
                {
                    path.push_back('L');
                    diff_x--;
                }
            }
            else
            {
                while (diff_x > 0)
                {
                    path.push_back('R');
                    diff_x--;
                }
            }
        }
        else
        {
            if (last_x > x)
            {
                while (diff_x > 0)
                {
                    path.push_back('L');
                    diff_x--;
                }
            }
            else
            {
                while (diff_x > 0)
                {
                    path.push_back('R');
                    diff_x--;
                }
            }

            if (last_y > y)
            {
                while (diff_y > 0)
                {
                    path.push_back('U');
                    diff_y--;
                }
            }
            else
            {
                while (diff_y > 0)
                {
                    path.push_back('D');
                    diff_y--;
                }
            }
        }
        
        return path;
    }
    
    string alphabetBoardPath(string target) 
    {
        string result = "";
        char last = -1;
        for (char c : target)
        {
            if (last == c)
            {
                result.push_back('!');
            }
            else
            {
                if (last == -1)
                {
                    result.append(findPath('a', c));
                }
                else
                {
                    result.append(findPath(last, c));
                }
                last = c;
                result.push_back('!');
            }
        }
        
        return result;
    }
};

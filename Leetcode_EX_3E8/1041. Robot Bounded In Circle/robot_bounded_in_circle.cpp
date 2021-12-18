// Leetcode 1041. Robot Bounded In Circle
// https://leetcode.com/problems/robot-bounded-in-circle/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0;
        int y = 0;
        int dir = 0;
        
        int i = 0;
        while (i < 4)
        {
            for (char instruction : instructions)
            {
                switch (instruction)
                {
                    case 'G':
                        {
                            if (dir == 0)
                            {
                                y++;
                            }
                            else if (dir == 90)
                            {
                                x++;
                            }
                            else if (dir == 180)
                            {
                                y--;
                            }
                            else if (dir == 270)
                            {
                                x--;
                            }
                        }
                        break;
                    case 'L':
                        {
                            dir += 270;
                            dir %= 360;
                        }
                        break;
                    case 'R':
                        {
                            dir += 90;
                            dir %= 360;
                        }
                        break;
                }
            }
            
            if (x == 0 && y == 0)
            {
                return true;
            }
            i++;
        }
        
        return false;
    }
};

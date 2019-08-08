// Leetcode 657. Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin/
// Runtime: 16ms

class Solution 
{
public:
    bool judgeCircle(string moves) 
    {
        int coord[2] = { 0 }; // [x, y]
        
        for (int i = 0; i < moves.size(); i++)
        {
            char move = moves[i];
            if (move == 'L')
            {
                coord[0]--;
            }
            else if (move == 'R')
            {
                coord[0]++;
            }
            else if (move == 'U')
            {
                coord[1]++;
            }
            else if (move == 'D')
            {
                coord[1]--;
            }
        }
        
        if (coord[0] == 0 && coord[1] == 0)
        {
            return true;
        }
        
        return false;
    }
};

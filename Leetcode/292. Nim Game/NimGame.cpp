// Leetcode 292. Nim Game
// https://leetcode.com/problems/nim-game/description/
// Runtime: 0ms

// it works..why..
class Solution 
{
public:
    bool canWinNim(int n) 
    {
        if (n % 4 == 0)
            return false;
        else
            return true;
    }
};

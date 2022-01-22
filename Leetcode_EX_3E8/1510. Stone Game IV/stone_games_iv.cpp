// Leetcode 1510. Stone Game IV
// https://leetcode.com/problems/stone-game-iv/
// time complexity: 
// space complexity: O(n)

class Solution
{
public:
    bool play(int n, bool isAlice, vector<int>& tbl)
    {
        int root = (int)floor(sqrt(n));
        if (tbl[n] != -1)
        {
            return tbl[n];
        }
        
        if (root * root == n)
        {
            return true;
        }
        
        bool result = false;
        for (int i = 1; i <= root; i++)
        {            
            result |= !play(n - i * i, !isAlice, tbl);
        }
        
        tbl[n] = result;
        
        return result;
    }
    
    bool winnerSquareGame(int n) 
    {
        vector<int> tbl(n + 1, -1);
        return play(n, true, tbl);
    }
};

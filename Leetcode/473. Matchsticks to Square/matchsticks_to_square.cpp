// Leetcode 473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/

class Solution
{
public:
    bool makesquare(vector<int>& m, int index, 
                    int a, int b, int c, int d, int side)
    {
        if (index == m.size())
        {
            return a == side && b == side && c == side && d == side;
        }
        
        if (a > side || b > side || c > side || d > side)
        {
            return false;
        }

        bool result = false;
        
        result = result || makesquare(m, index + 1, a + m[index], b, c, d, side);
        result = result || makesquare(m, index + 1, a, b + m[index], c, d, side);
        result = result || makesquare(m, index + 1, a, b, c + m[index], d, side);
        result = result || makesquare(m, index + 1, a, b, c, d + m[index], side);
        
        return result;
    }
    
    bool makesquare(vector<int>& matchsticks)
    {
        int len = 0;
        for (int m : matchsticks)
        {
            len += m;
        }
        
        if (len % 4 != 0)
        {
            return false;
        }
        
        int side = len / 4;
        
        // sorting matchsticks in descending order
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        return makesquare(matchsticks, 0, 0, 0, 0, 0, side);
    }
};

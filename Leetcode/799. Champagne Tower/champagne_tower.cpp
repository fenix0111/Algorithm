// Leetcode 799. Champagne Tower
// https://leetcode.com/problems/champagne-tower/

// sometimes don't try to figure out kind of brilliant solution
// just simulate it as the problem description
// the point is, the excess champagne of full glass will flow into the cups at the next row
// which positions are [current row + 1, current col], [current row + 1, current col + 1]

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double tower[101][101] = { 0.0 };        
        tower[0][0] += poured;
        
        for (int r = 0; r < 100; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                if (tower[r][c] > 1.0)
                {
                    double water = tower[r][c] - 1.0;
                    tower[r + 1][c] += water * 0.5;
                    tower[r + 1][c + 1] += water * 0.5;
                    tower[r][c] = 1.0;
                }
            }
        }
        
        return tower[query_row][query_glass];
    }
};

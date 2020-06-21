// Leetcode 174. Dungeon Game
// https://leetcode.com/problems/dungeon-game/
// time complexity: O(N)
// space complexity: O(N)

// problem states that "he knight decides to move only rightward or downward in each step"
// so the minimum hp required to survive in next step is "minimum hp needed in the next cell - state in the current cell"
// if current cell has demons, it is obivous that we need more hp than the loses hp
// if current cell has magic orbs, there are two cases
//   1, if magic orbs are greater than or equal to we need, then we are able to survive only with 1 hp
//   2, if magic orbs are less than we need, we have to subtract the magic orbs to get necessary hp

class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int row = dungeon.size();
        int col = dungeon[0].size();
        int** tbl = (int**)malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++)
        {
            tbl[i] = (int*)malloc(sizeof(int) * col);
        }
        
        tbl[row - 1][col - 1] = dungeon[row - 1][col - 1] < 0 ? -dungeon[row - 1][col - 1] + 1 : 1;
        
        for (int i = col - 2; i >= 0; i--)
        {
            if (tbl[row - 1][i + 1] <= dungeon[row - 1][i])
            {
                tbl[row - 1][i] = 1;
                continue;
            }
            
            tbl[row - 1][i] = tbl[row - 1][i + 1] - dungeon[row - 1][i];
        }
        
        for (int i = row - 2; i >= 0; i--)
        {
            if (tbl[i + 1][col - 1] <= dungeon[i][col - 1])
            {
                tbl[i][col - 1] = 1;
                continue;
            }
            
            tbl[i][col - 1] = tbl[i + 1][col - 1] - dungeon[i][col - 1];
        }
        
        for (int r = row - 2; r >= 0; r--)
        {
            for (int c = col - 2; c >= 0; c--)
            {
                if (dungeon[r][c] >= tbl[r][c + 1] || dungeon[r][c] >= tbl[r + 1][c])
                {
                    tbl[r][c] = 1;
                }
                else
                {
                    tbl[r][c] = min(tbl[r + 1][c], tbl[r][c + 1]) - dungeon[r][c];
                }
            }
        }
        
        return tbl[0][0];
    }
};

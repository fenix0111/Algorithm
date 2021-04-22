// Leetcode 554. Brick Wall
// https://leetcode.com/problems/brick-wall/
// time complexity: O(n) , n is number of bricks
// space complexity: O(n)

class Solution 
{
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        unordered_map<unsigned int, int> bricks;
        
        int width = 0;
        int result = wall.size();
        
        // calculate the width of the wall
        for (int val : wall[0])
        {
            width += val;
        }
        
        for (int i = 0; i < wall.size(); i++)
        {
            int w = 0;
            for (int j = 0; j < wall[i].size(); j++)
            {
                w += wall[i][j];
                
                // ignore last brick in the row
                if (w != width)
                    bricks[w]++;
            }
        }
        
        for (auto it = bricks.begin(); it != bricks.end(); it++)
        {
            int crossed = wall.size() - it->second;
        
            if (crossed < result)
            {
                result = crossed;
            }
        }
        
        return result;
    }
};

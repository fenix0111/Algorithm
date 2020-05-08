// Leetcode 1232. Check If It Is a Straight Line
// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Runtime: 12 ms
// Memory: 9.9 MB

class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int dx = 0;
        int dy = 0;
        dx = coordinates[1][0] - coordinates[0][0];
        dy = coordinates[1][1] - coordinates[0][1];
        
        float slope = float(dy) / float(dx);
        for (int i = 2; i < coordinates.size(); i++)
        {
            int tmp_dx = coordinates[i][0] - coordinates[i - 1][0];
            int tmp_dy = coordinates[i][1] - coordinates[i - 1][1];
            if (fabs(float(tmp_dy) / float(tmp_dx) - slope) > 0.0001f)
            {
                return false;
            }
        }
        
        return true;
    }
};

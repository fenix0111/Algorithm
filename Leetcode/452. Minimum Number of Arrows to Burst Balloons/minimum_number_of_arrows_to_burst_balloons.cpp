// Leetcode 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// time complexity: O(nlogn)
// space complexity: O(1)

// sort the points array in the ascending order of end position
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        
        int result = 1;
        int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            vector<int>& p = points[i];
            int newL = max(p[0], left);
            int newR = min(p[1], right);
            
            if (newL > right)
            {
                result++;
                left = p[0];
                right = p[1];
            }
        }
        
        return result;
    }
};

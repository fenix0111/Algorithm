// Leetcode 939. Minimum Area Rectangle
// https://leetcode.com/problems/minimum-area-rectangle/
// time complexity: O(N^2 * logN)
// space complexity: O(N)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points)
    {
        // higher 16bit : x, lower 16bit: y
        unordered_set<int> point_set;
        
        // contains y coordinate with same x
        unordered_map<int, vector<int>> xset;
        
        // contains x coordinate with same y
        unordered_map<int, vector<int>> yset;
        int result = INT_MAX;
        
        for (vector<int>& p : points)
        {
            int x = p[0];
            int y = p[1];
            int point = x << 16;
            point |= y;
            
            point_set.insert(point);
            xset[x].push_back(y);
            yset[y].push_back(x);
        }
        
        for (vector<int>& p : points)
        {
            int x = p[0];
            int y = p[1];
            
            const vector<int>& xs = xset[x];
            const vector<int>& ys = yset[y];
            
            for (int py : xs)
            {
                for (int px : ys)
                {
                    if (px == x || py == y)
                    {
                        continue;
                    }
                    
                    int point = px << 16;
                    point |= py;
                    
                    if (point_set.count(point))
                    {
                        int area = abs(px - x) * abs(py - y);                        
                        result = min(result, area);
                    }
                }
            }
        }
        
        return result == INT_MAX ? 0 : result;
    }
}; 

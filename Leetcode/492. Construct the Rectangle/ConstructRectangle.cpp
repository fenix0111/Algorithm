// Leetcode 492. Construct the Rectangle
// https://leetcode.com/problems/construct-the-rectangle/
// Runtime: 16ms

class Solution 
{
public:
    vector<int> constructRectangle(int area) 
    {
        int w = 0;
        int l = 0;
        vector<int> ret(2, 0);
        int root = (int)sqrt(area);
        w = root;
        l = root;
        
        while (w * l != area)
        {
            if (w * l < area)
            {
                l++;
            }
            else
            {
                w--;
            }
        }
        ret[0] = l;
        ret[1] = w;
        return ret;
    }
};

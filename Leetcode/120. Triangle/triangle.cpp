// bottom-up solution

class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int size = triangle.size();
        vector<int> buf;
        for (int val : triangle.back())
        {
            buf.push_back(val);
        }
        
        for (int i = size - 2; i >= 0; i--)
        {
            vector<int>& nums = triangle[i];
            for (int j = 0; j < nums.size(); j++)
            {
                buf[j] = min(buf[j], buf[j + 1]) + nums[j];
            }
        }
        
        return buf[0];
    }
};

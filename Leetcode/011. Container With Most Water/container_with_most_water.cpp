// two pointers

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int result = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            int area = h * (j - i);

            if (area > result)
            {
                result = area;
            }
            
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return result;
    }
};

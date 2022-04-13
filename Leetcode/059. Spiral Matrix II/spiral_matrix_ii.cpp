class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int num = 1;
        int end = n * n;
        
        vector<vector<int>> result(n, vector<int>(n, 0));
        int r = 0;
        int c = 0;
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        while (num <= end)
        {
            // right
            for (int i = left; i <= right; i++)
            {
                result[top][i] = num;
                num++;
            }
            
            top++;
            
            // down
            for (int i = top; i <= bottom; i++)
            {                
                result[i][right] = num;
                num++;
            }
            
            right--;
            
            // left
            for (int i = right; i >= left; i--)
            {
                result[bottom][i] = num;
                num++;
            }
            
            bottom--;
            // up
            for (int i = bottom; i >= top; i--)
            {
                result[i][left] = num;
                num++;
            }
            
            left++;
        }
        
        return result;
    }
};

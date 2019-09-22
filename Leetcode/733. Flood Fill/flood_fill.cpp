// Leetcode 733. Flood Fill
// https://leetcode.com/problems/flood-fill/
// Runtime: 24ms

class Solution 
{
public:
    void flood_fill(vector< vector<int> > &image, int r, int c, int oldColor, int newColor, bool **visited)
    {
        if (r < 0 || c >= image[0].size() || r >= image.size() || c < 0)
            return;
        
        if (visited[r][c])
            return;
        
        visited[r][c] = true;
        if (image[r][c] == oldColor)
        {
            image[r][c] = newColor;
        }
        else
        {
            return;
        }
        
        flood_fill(image, r, c - 1, oldColor, newColor, visited); // left
        flood_fill(image, r - 1, c, oldColor, newColor, visited); // top
        flood_fill(image, r, c + 1, oldColor, newColor, visited); // right
        flood_fill(image, r + 1, c, oldColor, newColor, visited); // bottom       
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> ret = image;
        bool **tbl = (bool**)malloc(sizeof(bool*) * row);
        for (int i = 0; i < row; i++)
        {
            tbl[i] = (bool*)malloc(sizeof(bool) * col);
            for (int j = 0; j < col; j++)
            {
                tbl[i][j] = false;
            }
        }
        
        flood_fill(ret, sr, sc, image[sr][sc], newColor, tbl);
        
        return ret;
    }
};

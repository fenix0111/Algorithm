// Leetcode 1329. Sort the Matrix Diagonally
// https://leetcode.com/problems/sort-the-matrix-diagonally/
// time complexity: O(row x col x DlogD), D is maximum number of diagonal elements
// space complexity: O(D), D is maximum number of diagonal elements

// solution is pretty straightforward
class Solution 
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size();
        int col = mat[0].size();
        
        int r = row - 1;
        
        while (r >= 0)
        {
            int i = r;
            int j = 0;
            vector<int> tmp;
            while (i < row && j < col)
            {
                tmp.push_back(mat[i][j]);
                j++;
                i++;
            }
            
            sort(tmp.begin(), tmp.end());
            
            i = r;
            j = 0;
            int k = 0;
            while (i < row && j < col)
            {
                mat[i][j] = tmp[k];
                k++;
                j++;
                i++;
            }
            
            r--;
        }
        
        int c = 1;
        while (c < col)
        {
            int i = 0;
            int j = c;
            vector<int> tmp;
            while (j < col && i < row)
            {
                tmp.push_back(mat[i][j]);
                j++;
                i++;
            }
            
            sort(tmp.begin(), tmp.end());
            
            i = 0;
            j = c;
            int k = 0;
            while (i < row && j < col)
            {
                mat[i][j] = tmp[k];
                k++;
                j++;
                i++;
            }
            
            c++;
        }
        
        return mat;
    }
};

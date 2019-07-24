// Leetcode 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/
// Runtime: 32ms

class Solution 
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        // check the dimension first
        int row = nums.size();
        if (row == 0)
            return nums;
        
        int col = nums[0].size();
        if (row * col != r * c)
            return nums;
        
        // index for reshaped matrix
        int cpos = 0;
        int rpos = 0;
        
        // index for nums
        int rnums = 0;
        int cnums = 0;
        
        vector< vector<int> > ret;
        vector<int> retrow;
        while (rpos < r)
        {
            retrow.push_back(nums[rnums][cnums]);
            
            cnums++;
            cpos++;
            if (cnums == col)
            {
                rnums++;
                cnums = 0;
            }
            
            if (cpos == c)
            {
                cpos = 0;
                rpos++;
                
                ret.push_back(retrow);
                retrow.clear();
            }
        }
        
        return ret;
    }
};

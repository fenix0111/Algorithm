// Leetcode 598. Range Addition II
// https://leetcode.com/problems/range-addition-ii/submissions/
// Runtime: 8ms

class Solution 
{
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        int ret = 0;
        if (ops.size() == 0)
            return m * n;
        
        int min_x = ops[0][0];
        int min_y = ops[0][1];
        for (int i = 1; i < ops.size(); i++)
        {
            if (ops[i][0] < min_x)
                min_x = ops[i][0];
            
            if (ops[i][1] < min_y)
                min_y = ops[i][1];
        }
        
        ret = min_x * min_y;
        return ret;
    }
};

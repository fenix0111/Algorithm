// Leetcode 119. Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/description/
// Runtime: 3ms

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res;
        if (rowIndex == 0)
        {
            res.push_back(1);
            return res;
        }
        
        if (rowIndex == 1)
        {
            res.push_back(1);
            res.push_back(1);
            return res;
        }

        int *prev = (int*)malloc(sizeof(int) * (rowIndex + 1));
        int *curr = (int*)malloc(sizeof(int) * (rowIndex + 1));

        prev[0] = 1;
        prev[1] = 1;

        for (int i = 2; i <= rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    curr[0] = 1;
                }
                else if (j < i)
                {
                    curr[j] = prev[j] + prev[j - 1];
                }
            }
            curr[i] = 1;
            memmove(prev, curr, sizeof(int) * (rowIndex + 1));
        }
        res.assign(curr, curr + rowIndex + 1);
        return res;
    }
    
    // 0ms参考解法。主要思路为从尾部往前构建三角。
    // 这样一来不需要额外的存储空间也不会影响到前后两个数的相加，因为第N个数和第N+1个数的和保存在N+1的位置，所以不影响相加。
    vector<int> getRow_fast(int rowIndex) 
    {
        vector<int> result(rowIndex+1,0);
        result[0]=1;
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=i;j>=0;j--)
            {
                result[j] = result[j] + result[j-1];
            }
        }
        return result;
    }
};

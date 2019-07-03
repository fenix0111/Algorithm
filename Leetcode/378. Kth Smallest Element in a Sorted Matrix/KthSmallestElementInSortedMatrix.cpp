// Leetcode 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Runtime: 44ms

// using priority queue in "less" order to contain k elements
class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue< int, vector<int>, less<int> > q;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (q.size() < k)
                {
                    q.push(matrix[i][j]);
                }
                else
                {
                    if (matrix[i][j] < q.top())
                    {
                        q.pop();
                        q.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return q.top();
    }
};

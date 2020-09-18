// Leetcode 1302. Deepest Leaves Sum
// https://leetcode.com/problems/deepest-leaves-sum/
// time complexity: O(N)
// space complexity: O(1)

class Solution 
{
public:
    void run(TreeNode* node, vector<int>& sum, int depth)
    {
        if (node)
        {
            if (depth > sum[0])
            {
                sum[1] = node->val;
                sum[0] = depth;
            }
            else if (depth == sum[0])
            {
                sum[1] += node->val;
            }
            
            run(node->left, sum, depth + 1);
            run(node->right, sum, depth + 1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) 
    {
        vector<int> sum(2, 0); // <depth, sum>
        run(root, sum, 1);
        
        return sum[1];
    }
};

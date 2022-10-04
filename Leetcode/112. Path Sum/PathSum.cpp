// Leetcode 112. Path Sum
// https://leetcode.com/problems/path-sum/description/
// Runtime: 6ms
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathSum(TreeNode* node, int sum)
    {
        if (node->left == NULL && node->right == NULL)
        {
            // 叶子节点的val刚好等于目标差
            if (sum == node->val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool lsum = false;
        bool rsum = false;
        if (node->left)
            lsum = pathSum(node->left, sum - node->val);

        if (node->right)
            rsum = pathSum(node->right, sum - node->val);

        return lsum || rsum;
    }

    bool hasPathSum(TreeNode* root, int sum) 
    {
        if (root == NULL)
            return false;

        return pathSum(root, sum);
    }
};

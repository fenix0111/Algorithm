// Leetcode 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/
// Runtime: 20ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // similar to "Path Sum II"
 // treat every node in the tree as "root" node, then calculate the sum
class Solution 
{
public:
    int helper(TreeNode *root, int sum, int target)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        if (sum + root->val == target)
        {
            return  helper(root->left, sum + root->val, target) + 
                    helper(root->right, sum + root->val, target) + 1;
        }
        else
        {
            return  helper(root->left, sum + root->val, target) + 
                    helper(root->right, sum + root->val, target);
        }
    }

    int pathSum(TreeNode* root, int sum) 
    {
        int ret = 0;
        ret = helper(root, 0, sum);
        if (root)
        {
            ret += pathSum(root->left, sum);
            ret += pathSum(root->right, sum);
        }

        return ret;
    }
};

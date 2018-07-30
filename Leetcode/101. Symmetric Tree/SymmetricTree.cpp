// Leetcode 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/description/
// Runtime: 3ms

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
    bool isSym(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if (left && right && (left->val == right->val))
        {
            return isSym(left->left, right->right) && isSym(left->right, right->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL)
        {
            return true;
        }
        if ((root->left == NULL) && (root->right == NULL))
        {
            return true;
        }
        return isSym(root->left, root->right);
    }
};

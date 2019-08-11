// Leetcode 671. Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/submissions/
// Runtime: 0ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution 
{
public:
    void traverse(TreeNode *root, unsigned int *secmin)
    {
        if (root && root->left && root->right)
        {
            if (root->left->val > root->right->val)
            {
                if (root->left->val > root->val && root->left->val <= *secmin)
                    *secmin = root->left->val;
            }
            else
            {
                if (root->right->val > root->val && root->right->val <= *secmin)
                    *secmin = root->right->val;
            }

            traverse(root->left, secmin);
            traverse(root->right, secmin);
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) 
    {
        unsigned int secmin = UINT_MAX;
        traverse(root, &secmin);

        if (secmin == UINT_MAX)
            return -1;

        return secmin;
    }
};

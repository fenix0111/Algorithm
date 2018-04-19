// Leetcode 114. Flatten Binary Tree to Linked List
// Runtime: 12ms
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    TreeNode* flattenRecur(TreeNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        if (root->left)
        {
            if (root->left->left == NULL && root->left->right == NULL)
            {
                root->left->right = root->right;
                root->right = root->left;
                root->left = NULL;
                return flattenRecur(root->right);
            }
            else
            {
                TreeNode *L = flattenRecur(root->left);
                if (L)
                {
                    L->right = root->right;
                    root->right = root->left;
                    root->left = NULL;
                    return flattenRecur(root->right);
                }
                else
                {
                    return NULL;
                }
            }
        }
        else
        {
            return flattenRecur(root->right);
        }
    }
    
    void flatten(TreeNode* root) 
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        TreeNode *l = flattenRecur(root->left);
        TreeNode *r = flattenRecur(root->right);
		
        if (l)
        {
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

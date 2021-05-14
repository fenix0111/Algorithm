// Leetcode 114. Flatten Binary Tree to Linked List
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
    TreeNode* flattenTree(TreeNode* node)
    {
        if (node)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                return node;
            }
            
            TreeNode* left = flattenTree(node->left);
            TreeNode* right = node->right;
            if (node->left)
            {
                node->right = node->left;
            }
            
            node->left = nullptr;

            if (left)
            {
                left->right = right;
            }
            
            if (right)
            {
                return flattenTree(right);
            }
            else
            {
                return left;
            }
        }
        
        return nullptr;
    }
    
    void flatten(TreeNode* root) 
    {
        flattenTree(root);
    }
};

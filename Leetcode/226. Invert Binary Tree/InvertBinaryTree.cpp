// Leetcode 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/description/
// Runtime: 0ms

// This problem was inspired by this original tweet by Max Howell:
// Google: 90% of our engineers use the software you wrote (Homebrew), 
// but you can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root == NULL) 
        {
            return root;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        root->left = right;
        root->right = left;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

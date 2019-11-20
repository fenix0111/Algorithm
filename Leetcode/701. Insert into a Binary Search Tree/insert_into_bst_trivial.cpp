// Leetcode 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Runtime: 80ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // naive solution
 // follow-up: re-balance the tree
class Solution 
{
public:
    void helper(TreeNode* root, int val)
    {
        if (root)
        {
            if (root->val > val)
            {
                if (root->left)
                {
                    helper(root->left, val);
                }
                else
                {
                    root->left = new TreeNode(val);
                }
            }
            else
            {
                if (root->right)
                {
                    helper(root->right, val);
                }
                else
                {
                    root->right = new TreeNode(val);
                }
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (NULL == root)
        {
            return new TreeNode(val);
        }
        helper(root, val);
        return root;
    }
};

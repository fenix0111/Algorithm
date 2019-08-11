// Leetcode 700. Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/
// Runtime: 52ms

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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root)
        {
            if (root->val == val)
            {
                return root;
            }
            else
            {
                if (val < root->val)
                {
                    return searchBST(root->left, val);
                }
                else
                {
                    return searchBST(root->right, val);
                }
            }
        }
        
        return NULL;
    }
};

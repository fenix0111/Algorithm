// Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
 
 // because the tree is BST, simply utilize the property of it: 
 // nodes have smaller val than parent are all in the left sub-tree, otherwise in the right.
class Solution 
{
public:
    TreeNode* lcaHelper(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        int small, big;
        if (p->val > q->val)
        {
            big = p->val;
            small = q->val;
        }
        else
        {
            big = q->val;
            small = p->val;
        }
        
        if (small < node->val && big > node->val)
        {
            return node;
        }
        
        if (small < node->val && big < node->val)
        {
            return lcaHelper(node->left, p, q);
        }
        
        if (small > node->val && big > node->val)
        {
            return lcaHelper(node->right, p, q);
        }
        
        // reach here if current "root" val is equal to val of p or q 
        return node;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return lcaHelper(root, p, q);
    }
};

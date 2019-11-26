// Leetcode 814. Binary Tree Pruning
// https://leetcode.com/problems/binary-tree-pruning/
// Runtime: 4ms

// Related: 
// 1104. Path In Zigzag Labelled Binary Tree
// 998. Maximum Binary Tree II

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
    void prune(TreeNode **node)
    {
        if (*node)
        {
            prune(&(*node)->left);
            prune(&(*node)->right);
            
            // self destruction
            if ((*node)->val == 0 && (*node)->left == NULL && (*node)->right == NULL)
            {
                *node = NULL;
            } 
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        prune(&root);
        return root;
    }
};

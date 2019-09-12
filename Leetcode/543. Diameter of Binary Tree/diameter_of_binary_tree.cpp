// Leetcode 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
// Runtime: 4ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // using post-order traversal
class Solution 
{
public:
    int check_height(TreeNode *node, int &max)
    {
        if (!node)
            return 0;
        
        if (node->left == NULL && node->right == NULL)
            return 1;
        
        int l = check_height(node->left, max);
        int r = check_height(node->right, max);
        
        if (l + r > max)
            max = l + r;
        
        int ret = l > r ? l : r;
        return ret + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root)
            return 0;
        
        int max = 0;
        check_height(root, max);
        
        return max;
    }
};

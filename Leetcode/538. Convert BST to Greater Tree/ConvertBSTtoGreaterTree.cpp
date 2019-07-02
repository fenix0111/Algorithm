// Leetcode 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/
// Runtime: 24ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // anyway it works...
class Solution 
{
public:    
    int helper(TreeNode *node, int sum)
    {
        if (node == NULL)
        {
            return sum;
        }
        
        if (node->left == NULL && node->right == NULL)
        {
            node->val += sum;
            return node->val;
        }
        
        int rsum = helper(node->right, sum);
        node->val += rsum;
        rsum = node->val;
        return helper(node->left, rsum);
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {   
        if (root)
        {
            helper(root, 0);
        }

        return root;
    }
};

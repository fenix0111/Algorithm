// Leetcode 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
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
 
 // naive solution
 // should use the properties of complete binary tree
class Solution 
{
public:
    void traversal(TreeNode *node, int &c)
    {
        if (node)
        {
            int tmp = c;
            tmp++;
            c = tmp;
            traversal(node->left, c);
            traversal(node->right, c);
        }
    }
    
    int countNodes(TreeNode* root) 
    {
        if (root)
        {
            int c = 0;
            traversal(root, c);
            return c;
        }
        return 0;
    }
};

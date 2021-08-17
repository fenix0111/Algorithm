// Leetcode 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// time complexity: O(n)
// space complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int traverse(TreeNode* node, int currentMax)
    {
        if (node == nullptr)
        {
            return 0;
        }
        
        return traverse(node->left, max(currentMax, node->val)) + 
               traverse(node->right, max(currentMax, node->val)) + 
               (currentMax <= node->val ? 1 : 0);
    }
    
    int goodNodes(TreeNode* root) 
    {
        return traverse(root, root->val);
    }
};

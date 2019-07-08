// Leetcode 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Runtime: 12ms

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
    void helper(TreeNode *node, int k, int &c, int &num)
    {
        if (!node)
        {
            return;
        }
            
        if (num != INT_MIN)
        {
            return;
        }
        
        helper(node->left, k, c, num);
        c++;
        if (c == k)
        {
            num = node->val;
            return;
        }
        
        helper(node->right, k, c, num);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int num = INT_MIN;
        int c = 0;
        helper(root, k, c, num);
        
        return num;
    }
};

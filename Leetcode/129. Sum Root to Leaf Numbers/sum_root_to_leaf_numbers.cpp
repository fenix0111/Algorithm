// Leetcode 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// time complexity: O(n)
// space complexity: O(1)

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
    int calculate(TreeNode* node, int prev)
    {        
        if (!node) return 0;
        
        // only return when reach the leaf node
        if (node->left == NULL && node->right == NULL)
        {
            return prev * 10 + node->val;
        }
        
        return calculate(node->left, prev * 10 + node->val) + 
               calculate(node->right, prev * 10 + node->val);
    }
    
    int sumNumbers(TreeNode* root) 
    {
        return calculate(root, 0);
    }
};

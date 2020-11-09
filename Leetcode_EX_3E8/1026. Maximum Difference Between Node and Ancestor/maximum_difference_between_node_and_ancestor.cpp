// Leetcode 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// time complexity: O(N)
// space complexity: O(N)

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
    void findMaxDiff(TreeNode* node, int minval, int maxval, int& result)
    {
        if (node)
        {
            int min = node->val < minval ? node->val : minval;
            int max = node->val > maxval ? node->val : maxval;
            
            if (result < abs(node->val - minval))
            {
                result = abs(node->val - minval);
            }
            
            if (result < abs(node->val - maxval))
            {
                result = abs(node->val - maxval);
            }
            
            findMaxDiff(node->left, min, max, result);
            findMaxDiff(node->right, min, max, result);
        }
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        int result = 0;
        if (root)
            findMaxDiff(root, root->val, root->val, result);

        return result;
    }
};

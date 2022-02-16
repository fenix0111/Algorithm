// Leetcode 687. Longest Univalue Path
// https://leetcode.com/problems/longest-univalue-path/
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
    int result = 0;
public:
    int findPath(TreeNode* node)
    {
        if (node)
        {
            int left = findPath(node->left);
            int right = findPath(node->right);

            int leftpath = 0;
            int rightpath = 0;
            if (node->left != nullptr && node->left->val == node->val)
            {
                leftpath = left + 1;
            }
            
            if (node->right != nullptr && node->right->val == node->val)
            {
                rightpath = right + 1;
            }
            
            int maxpath = max(leftpath, rightpath);
            result = max(result, leftpath + rightpath);
            
            return maxpath;
        }    
        
        return 0;
    }
    
    int longestUnivaluePath(TreeNode* root)
    {
        findPath(root);
        return result;
    }
};

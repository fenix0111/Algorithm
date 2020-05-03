// Leetcode 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/
// Runtime: 300 ms
// Memory: 64.7 MB

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
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if (root)
        {
            if (root->val >= L && root->val <= R)
            {
                return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
            }
            else
            {
                if (root->val < L)
                {
                    return rangeSumBST(root->right, L, R);
                }

                if (root->val > R)
                {
                    return rangeSumBST(root->left, L, R);
                }
            }
        }
        
        return 0;
    }
};

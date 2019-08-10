// Leetcode 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/
// Runtime: 20ms

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
    TreeNode* trimBST(TreeNode* root, int L, int R) 
    {
        if (root)
        {
            TreeNode *newroot = NULL;
            if (L <= root->val && root->val <= R)
            {
                newroot = new TreeNode(root->val);
                TreeNode *lc = trimBST(root->left, L, R);
                TreeNode *rc = trimBST(root->right, L, R);
                if (lc)
                {
                    if (L <= lc->val && lc->val <= R)
                    {
                        newroot->left = lc;
                    }
                }
                
                if (rc)
                {
                    if (L <= rc->val && rc->val <= R)
                    {
                        newroot->right = rc;
                    }
                }
            }
            else
            {
                TreeNode *lc = trimBST(root->left, L, R);
                TreeNode *rc = trimBST(root->right, L, R);
                if (lc)
                {
                    if (L <= lc->val && lc->val <= R)
                    {
                        newroot = lc;
                    }
                }
                
                if (rc)
                {
                    if (L <= rc->val && rc->val <= R)
                    {
                        newroot = rc;
                    }
                }
            }
            
            return newroot;
        }
        
        return NULL;
    }
};

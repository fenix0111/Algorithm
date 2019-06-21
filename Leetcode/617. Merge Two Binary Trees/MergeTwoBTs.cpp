// Leetcode 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/
// Runtime: 32ms

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        int lv = t1 == NULL ? INT_MAX : t1->val;
        int rv = t2 == NULL ? INT_MAX : t2->val;
        
        int val;
        if (lv == INT_MAX && rv == INT_MAX)
        {
            return NULL;
        }
        else
        {
            if (lv == INT_MAX && rv != INT_MAX)
            {
                val = rv;
            }
            
            if (lv != INT_MAX && rv == INT_MAX)
            {
                val = lv;
            }
            
            if (lv != INT_MAX && rv != INT_MAX)
            {
                val = lv + rv;
            }
        }
        
        TreeNode *root = new TreeNode(val);
        TreeNode *l1 = t1 == NULL ? NULL : t1->left;
        TreeNode *l2 = t2 == NULL ? NULL : t2->left;
        
        TreeNode *r1 = t1 == NULL ? NULL : t1->right;
        TreeNode *r2 = t2 == NULL ? NULL : t2->right;
        
        root->left = mergeTrees(l1, l2);
        root->right = mergeTrees(r1, r2);
        
        return root;
    }
};

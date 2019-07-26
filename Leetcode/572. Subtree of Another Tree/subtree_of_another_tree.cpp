// Leetcode 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/
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
 
// check subtree using each node in the tree "s"  
class Solution 
{
public:
    bool is_subtree(TreeNode *src, TreeNode *dst)
    {
        if (src && dst)
        {
            if (src->val == dst->val)
                return is_subtree(src->left, dst->left) && is_subtree(src->right, dst->right);
            else
                return false;
        }
        
        if (!src && !dst)
            return true;
        
        return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (t)
        {
            if (is_subtree(s, t))
            {
                return true;
            }
            else
            {
                if (s)
                    return isSubtree(s->left, t) || isSubtree(s->right, t);
                else
                    return false;
            }
        }
        
        return false;
    }
};

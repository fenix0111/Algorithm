// Leetcode 100. Same Tree
// https://leetcode.com/problems/same-tree/description/
// Runtime: 3ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    
    if (p == NULL || q == NULL)
    {
        return false;
    }
    
    if (p->val != q->val)
        return false;
    
    
    if (isSameTree(p->left, q->left))
    {
        return isSameTree(p->right, q->right);
    }
    else
    {
        return false;
    }
}

// 0ms参考解法
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
if(p == NULL && q == NULL)
      return true;
    else if(p != NULL && q != NULL)
    {
        return (((p->val == q->val)) && isSameTree(p->left, q->left) && isSameTree(p ->right, q->right));
    }
    else
        return false;
}

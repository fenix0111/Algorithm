// Leetcode 114. Flatten Binary Tree to Linked List
// Runtime: 12ms
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 大体思路是：根节点的左节点的right指向根的右节点，根的right指向根的left，然后根的left设为NULL。
// 把这个步骤递归用到根的左右子树。最终需要返回根节点左子树里的最靠右的节点。

class Solution {
public:
    TreeNode* flattenRecur(TreeNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        
	// 叶子节点直接返回自身
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        if (root->left)
        {
            TreeNode *L = flattenRecur(root->left);
            if (L)
            {
                L->right = root->right;
                root->right = root->left;
                root->left = NULL;
                return flattenRecur(root->right);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
	    // 左节点为空时直接返回当前右子树的操作结果
            return flattenRecur(root->right);
        }
    }
    
    void flatten(TreeNode* root) 
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        TreeNode *l = flattenRecur(root->left);
        TreeNode *r = flattenRecur(root->right);
		
        if (l)
        {
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};

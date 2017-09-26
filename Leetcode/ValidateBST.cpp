// Leetcode 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/description/
// Runtime: 13ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 关键要定好比较范围。例如有时会出现根节点的右子树里有个左子树的右儿子节点值比根节点还要大
class Solution {
public:
    bool validBSTRecr(TreeNode* root, long long left, long long right)
    {
        if (root == NULL)
            return true;

        if (root->val > left && root->val < right)
            return validBSTRecr(root->left, left, root->val) && validBSTRecr(root->right, root->val, right);
        else
            return false;
    }

    bool isValidBST(TreeNode* root) 
    {
        // 空树也算二叉搜索树?
        if (root == NULL)
            return true;

        return validBSTRecr(root->left, LONG_MIN, root->val) && validBSTRecr(root->right, root->val, LONG_MAX);
    }
};

// Leetcode 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/
// Runtime: 9ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 平衡树条件：左右子树平衡且左子树和右子树高度差最多为1
class Solution {
public:
    int get_depth(TreeNode* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			int lDepth = get_depth(node->left);
			int rDepth = get_depth(node->right);

			if (lDepth > rDepth)
			{
				return(lDepth + 1);
			}
			else
			{
				return(rDepth + 1);
			}
		}
	}

	bool isBalanced(TreeNode* root) 
	{
		if (root == NULL)
		{
			return true;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return true;
		}

		int left = get_depth(root->left);
		int right = get_depth(root->right);

		if (abs(left - right) > 1)
		{
			return false;
		}
		else
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}
};

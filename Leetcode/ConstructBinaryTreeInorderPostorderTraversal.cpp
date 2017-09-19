// Leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Runtime: 23ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 跟使用先序遍历和中序遍历构建二叉树类似。
class Solution {
public:
    TreeNode* btRecur(vector<int>& postorder, vector<int>& inorder, int pb, int pe, int ib, int ie)
{
	if (pb < pe)
		return NULL;

	if (ib > ie)
		return NULL;

	int rt = 0;
	for (int i = ib; i <= ie; i++)
	{
		if (inorder[i] == postorder[pb])
		{
			rt = i;
			break;
		}
	}

	int ileftl = ib;
	int ileftr = rt - 1;
	int irightl = rt + 1;
	int irightr = ie;

	int prightr = pb - 1;
	int prightl = pb + rt -ie;
	int pleftr = prightl - 1;
	int pleftl = pe;

	TreeNode *tree = (TreeNode*)malloc(sizeof(TreeNode));
	tree->val = inorder[rt];
	tree->left = btRecur(postorder, inorder, pleftr, pleftl, ileftl, ileftr);
	tree->right = btRecur(postorder, inorder, prightr, prightl, irightl, irightr);

	return tree;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
	return btRecur(postorder, inorder, (int)postorder.size() - 1, 0, 0, (int)inorder.size() - 1);
}
};

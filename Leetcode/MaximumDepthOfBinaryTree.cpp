// Leetcode 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
 
 // 主要思路为广度搜索，每清理一层depth加一。有点笨。。
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		list<TreeNode*> nodelist;
		list<TreeNode*> tmp;
		nodelist.push_back(root);
		int depth = 0;

		while (!nodelist.empty())
		{
			while (!nodelist.empty())
			{
				tmp.push_back(nodelist.front());
				nodelist.pop_front();
			}

			while (!tmp.empty())
			{
				TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
				node = tmp.front();
				tmp.pop_front();

				if (node->left)
				{
					nodelist.push_back(node->left);
				}

				if (node->right)
				{
					nodelist.push_back(node->right);
				}
			}

			depth++;
		}

		return depth;
    }
    
    // 6ms参考解法
    int maxDepth(TreeNode* root) {
        if (root == NULL) 
        return 0;
        if (root != NULL) 
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

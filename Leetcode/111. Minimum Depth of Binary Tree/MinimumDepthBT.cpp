// Leetcode 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// Runtime: 6ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 使用了广度优先搜索
class Solution {
public:
    int getMinDepth(TreeNode* root)
    {
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
        int depth = 1;

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

                if (node->left == NULL && node->right == NULL)
                    return depth++;

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
    
    int minDepth(TreeNode* root) 
    {
        return getMinDepth(root);
    }
};

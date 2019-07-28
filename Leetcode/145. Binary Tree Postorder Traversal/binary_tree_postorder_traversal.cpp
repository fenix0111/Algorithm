// Leetcode 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Runtime: 4ms

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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        if (root)
        {
            deque<TreeNode*> q;
            q.push_back(root);
            while (!q.empty())
            {
                TreeNode *node = q.front();
                ret.push_back(node->val);
                q.pop_front();
                if (node->left)
                    q.push_front(node->left);
                
                if (node->right)
                    q.push_front(node->right);
            }
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// Leetcode 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/description/
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
    void btpHelper(vector<string> &v, TreeNode* node, string path)
    {
        path = path + to_string(node->val) + "->";
        if (node->left == NULL && node->right == NULL)
        {
            path.erase(path.size() - 2, 2);
            v.push_back(path);
            path.erase(path.size() - 1, 1);
            return;
        }
        
        if (node->left)
        {
            btpHelper(v, node->left, path);
        }
        
        if (node->right)
        {
            btpHelper(v, node->right, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ret;
        if (root == NULL)
        {
            return ret;
        }
        
        btpHelper(ret, root, "");
        
        return ret;
    }
};

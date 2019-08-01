// Leetcode 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/
// Runtime: 16ms

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
    void preorder(TreeNode *node, string &s)
    {
        if (node)
        {
            s += "(";
            s += to_string(node->val);
            if (!node->left && node->right)
            {
                s += "()";  // <--- careful
                preorder(node->right, s);
                s += ")";
            }
            
            if (node->left && !node->right)
            {
                preorder(node->left, s);
                s += ")";
            }
            
            if (node->left && node->right)
            {
                preorder(node->left, s);
                s += ")";
                preorder(node->right, s);
                s += ")";
            }
        }
    }
    
    string tree2str(TreeNode* t) 
    {
        string ret = "";
        preorder(t, ret);
        
        // get rid of first left parenthesis
        if (ret.size() > 0)
            ret.erase(0, 1);
        
        return ret;
    }
};

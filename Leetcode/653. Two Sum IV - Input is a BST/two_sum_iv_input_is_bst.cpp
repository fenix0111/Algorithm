// Leetcode 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Runtime: 32ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// used auxiliary space
class Solution 
{
public:
    void inorder(TreeNode *node, vector<int>& v)
    {
        if (node)
        {
            inorder(node->left, v);
            v.push_back(node->val);
            inorder(node->right, v);
        }
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> tbl;
        if (root)
        {
            inorder(root, tbl);  // collect value(s)
            
            int h = 0;
            int t = tbl.size() - 1;
            
            while (h < t)
            {
                if (tbl[h] + tbl[t] == k)
                {
                    return true;
                }
                else if (tbl[h] + tbl[t] > k)
                {
                    t--;
                }
                else
                {
                    h++;
                }
            }
        }
        
        return false;
    }
};

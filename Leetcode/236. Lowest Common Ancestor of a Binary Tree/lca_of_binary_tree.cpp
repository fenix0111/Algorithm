// Leetcode 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// time complexity: O(n)
// space complexity: O(n)

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
    bool findNode(vector<TreeNode*>& buf, TreeNode* node, TreeNode* target)
    {
        if (node)
        {
            buf.push_back(node);
            if (node->val == target->val)
            {
                return true;
            }
            
            if (!findNode(buf, node->left, target) && !findNode(buf, node->right, target) && !buf.empty())
            {
                buf.pop_back();
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> bufp;
        vector<TreeNode*> bufq;
        findNode(bufp, root, p);
        findNode(bufq, root, q);
        int i = 0;
        TreeNode* lca = NULL;
        while (i < bufq.size() && i < bufp.size())
        {
            if (bufq[i]->val != bufp[i]->val)
            {
                break;
            }
            else
            {
                lca = bufq[i];
                i++;
            }
        }
        
        return lca;
    }
};

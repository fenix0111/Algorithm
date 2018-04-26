// Leetcode 107. Binary Tree Level Order Traversal II
// Runtime: 6ms
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 写的比较笨比较绕。。
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector< vector<int> > result;
        
        if (root == NULL) 
        {
            return result;
        }
        
        if (root->left == NULL && root->right == NULL)
        {
            vector<int> v;
            v.push_back(root->val);
            result.push_back(v);
            return result;
        }
        
        list< list<TreeNode*> > tmpList;
        list<TreeNode*> q;
        list<TreeNode*> l;
        
        q.push_back(root);
        while (!q.empty() || !l.empty())
        {
            
            while(!q.empty())
            {
                TreeNode *node = q.front();
                q.pop_front();
                if (node)
                {
                    l.push_back(node);
                }
            }
            
            if (!l.empty())
            {
                for (list<TreeNode*>::iterator iter = l.begin(); iter != l.end(); iter++)
                {
                    TreeNode *node = *iter;
                    if (node->left)
                    {
                        q.push_back(node->left);
                    }
                    if (node->right)
                    {
                        q.push_back(node->right);
                    }
                }
            
                tmpList.push_front(l);
            }
            
            
            l.clear();
        }
        
        for (list< list<TreeNode*> >::iterator i = tmpList.begin(); i != tmpList.end(); i++)
        {
            vector<int> v;
            for (list<TreeNode*>::iterator j = (*i).begin(); j != (*i).end(); j++)
            {
                v.push_back((*j)->val);
            }
            result.push_back(v);
        }
        
        return result;
    }
};

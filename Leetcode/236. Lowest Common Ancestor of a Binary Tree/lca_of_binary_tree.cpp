// Leetcode 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Runtime: 20ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 分别找从root到p和q节点的路径
 // 逐个比较，肯定有分叉，找到这个分叉即可
 // 数组遍历完依然没有找到分叉，说明lowest common ancestor是根节点
 // 这个方法内存占用比较大
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (NULL == root)
        {
            return NULL;
        }
        
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        
        find_path(root, p, path_p);
        find_path(root, q, path_q);
        
        int len = path_p.size() < path_q.size() ? path_p.size() : path_q.size();
        int pos = 0;
        TreeNode *ret = NULL;
        for (int i = 0; i < len; i++)
        {
            if (path_p[i] != path_q[i])
            {
                ret = path_p[i - 1];
                return ret;
            }
        }
        
        ret = path_p[len - 1];
        return ret;
    }
    
    bool find_path(TreeNode *root, TreeNode *target, vector<TreeNode*> &v)
    {
        if (NULL == root)
        {
            return false;
        }
        
        v.push_back(root);
        if (root->val == target->val)
        {
            return true;
        }
        
        if (find_path(root->left, target, v))
        {
            return true;
        }
        
        if (find_path(root->right, target, v))
        {
            return true;
        }
        else
        {
            if (!v.empty())
            {
                v.pop_back();
            }    
        }
        
        return false;
    }
};

// Leetcode 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Runtime: 28ms

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
    void helper(TreeNode *node, map<int,int> &counter)
    {
        if (node)
        {
            if (counter.find(node->val) == counter.end())
            {
                counter.insert(make_pair(node->val, 1));
            }
            else
            {
                counter.find(node->val)->second++;
            }
            helper(node->left, counter);
            helper(node->right, counter);
        }
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        map<int, int> counter;
        helper(root, counter);
        
        int mode = 0;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            if (it->second > mode)
                mode = it->second;
        }
        
        vector<int> ret;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            if (mode == it->second)
            {
                ret.push_back(it->first);
            }
        }
        
        return ret;
    }
};

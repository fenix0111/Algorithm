// Leetcode 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    void helper(TreeNode *node, priority_queue< int, vector<int>, less<int> > &q, int k)
    {
        if (!node)
            return;
        
        if (q.size() < k)
        {
            q.push(node->val);
        }
        else
        {
            if (q.top() > node->val)
            {
                q.pop();
                q.push(node->val);
            }
        }
        
        helper(node->left, q, k);
        helper(node->right, q, k);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        priority_queue< int, vector<int>, less<int> > q;
        helper(root, q, k);
        
        return q.top();
    }
};

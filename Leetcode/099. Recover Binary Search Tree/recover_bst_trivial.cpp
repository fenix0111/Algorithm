// Leetcode 99. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/
// time complexity: O(#nodes)
// space complexity: O(#nodes)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 // using in-order traversal
class Solution 
{
public:
    void record(TreeNode* node, vector<int>& v)
    {
        if (node)
        {
            record(node->left, v);
            v.push_back(node->val);
            record(node->right, v);
        }
    }
    
    void recover(TreeNode* node, vector<int>& v, int& index)
    {
        if (index >= v.size())
        {
            return;
        }
        
        if (node)
        {
            recover(node->left, v, index);
            node->val = v[index];
            index += 1;
            recover(node->right, v, index);
        }
    }
    
    void recoverTree(TreeNode* root) 
    {
        vector<int> values;
        record(root, values);
        
        sort(values.begin(), values.end());
        int index = 0;
        recover(root, values, index);
    }
};

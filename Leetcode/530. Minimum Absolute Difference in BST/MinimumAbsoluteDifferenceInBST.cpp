// Leetcode 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Runtime: 24ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // naive solution
 // traversing all node, put the value of each node in buffer, 
 // then sort it, find the minimum absolute difference.
class Solution 
{
public:
    void collect_node(TreeNode *node, vector<int> &buf)
    {
        if (node)
        {
            buf.push_back(node->val);
            collect_node(node->left, buf);
            collect_node(node->right, buf);
        }
    }
    
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> buf;
        collect_node(root, buf);
        
        sort(buf.begin(), buf.end());
        int min = INT_MAX;
        for (int i = 0; i < buf.size() - 1; i++)
        {
            if (buf[i + 1] - buf[i] < min)
                min = buf[i + 1] - buf[i];
        }
        
        return min;
    }
};

// Leetcode 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

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
 
// using in-order travesral to flatten the tree
class BSTIterator 
{
    vector<int> data;
    int idx = 0;
    void inorder(TreeNode* node)
    {
        if (node)
        {
            inorder(node->left);
            data.push_back(node->val);
            inorder(node->right);
        }
    }
    
public:
    BSTIterator(TreeNode* root) 
    {
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        int ret = data[idx];
        idx++;
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return idx != data.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

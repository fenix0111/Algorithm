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
class BSTIterator {
    stack<TreeNode*> data;

    void inorder(TreeNode* node)
    {
        while (node)
        {
            data.push(node);
            node = node->left;
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
        TreeNode* node = data.top();
        int ret = node->val;
        data.pop();
        
        if (node->right)
        {
            inorder(node->right);
        }
        
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !data.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

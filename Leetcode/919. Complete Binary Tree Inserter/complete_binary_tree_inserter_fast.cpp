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

// the idea is simple
// maintaining a queue contains tree node
// if node is full, push left and right child into the queue then pop it out
// the front of the queue will be a node which has no children or only has left children

class CBTInserter
{
    TreeNode* root;
    queue<TreeNode*> q;
    
public:
    CBTInserter(TreeNode* root)
    {
        this->root = root;
        q.push(this->root);
        
        while (!q.empty())
        {
            TreeNode* node = q.front();
            
            if (node->left && node->right)
            {
                q.push(node->left);
                q.push(node->right);
                q.pop();
            }
            else
            {
                break;
            }
        }
    }
    
    int insert(int val)
    {
        TreeNode* node = q.front();
            
        if (node->left == nullptr)
        {
            node->left = new TreeNode(val);
            return node->val;
        }
        else
        {
            node->right = new TreeNode(val);
            q.pop();
            
            q.push(node->left);
            q.push(node->right);
            return node->val;
        }
    }
    
    TreeNode* get_root()
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

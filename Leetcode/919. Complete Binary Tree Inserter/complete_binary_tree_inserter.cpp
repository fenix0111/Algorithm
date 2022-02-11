// Leetcode 919. Complete Binary Tree Inserter
// https://leetcode.com/problems/complete-binary-tree-inserter/

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

// BFS
class CBTInserter
{
    TreeNode* root;
public:
    CBTInserter(TreeNode* root)
    {
        this->root = root;
    }
    
    int insert(int val)
    {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left && node->right)
            {
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                if (node->left == nullptr)
                {
                    node->left = new TreeNode(val);
                    return node->val;
                }
                
                if (node->right == nullptr)
                {
                    node->right = new TreeNode(val);
                    return node->val;
                }
            }
        }
        
        return -1;  // never reach here
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

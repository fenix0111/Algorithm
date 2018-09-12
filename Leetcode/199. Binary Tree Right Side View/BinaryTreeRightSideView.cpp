// Leetcode 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/
// Runtime: 4ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // use the extra space to do breadth-first search
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ret;
        if (root == NULL)
            return ret;
        
        queue<TreeNode*> main_queue;
        queue<TreeNode*> extr_queue;
        
        main_queue.push(root);
        
        while (!main_queue.empty() || !extr_queue.empty())
        {
            while (!main_queue.empty())
            {
                if (main_queue.size() == 1)
                {
                    ret.push_back(main_queue.front()->val);
                }
                
                if (main_queue.front()->left)
                {
                    extr_queue.push(main_queue.front()->left);
                }
                
                if (main_queue.front()->right)
                {
                    extr_queue.push(main_queue.front()->right);
                }
                
                main_queue.pop();
            }
            
            while (!extr_queue.empty())
            {
                main_queue.push(extr_queue.front());
                extr_queue.pop();
            }
        }
        
        return ret;
    }
};

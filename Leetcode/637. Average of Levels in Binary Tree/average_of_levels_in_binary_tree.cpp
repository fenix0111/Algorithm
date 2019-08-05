// Leetcode 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Runtime: 16ms

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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ret;
        deque<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty())
        {
            int size = q.size();
            double ave = 0;
            for (auto it = q.begin(); it != q.end(); it++)
            {
                ave += (*it)->val;
            }
            
            int c = 0;
            while (c < size)
            {
                TreeNode *node = q.front();
                q.pop_front();
                if (node->left)
                    q.push_back(node->left);
                
                if (node->right)
                    q.push_back(node->right);
                
                c++;
            }
            
            ret.push_back(ave / (double)(size));
        }
        
        return ret;
    }
};

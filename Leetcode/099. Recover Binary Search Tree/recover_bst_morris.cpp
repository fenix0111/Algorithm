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
class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* current = root;
        TreeNode* mostRight = NULL;
        TreeNode* beg = NULL;
        TreeNode* end = NULL;
        TreeNode* last = NULL;
        
        while (current)
        {
            mostRight = current->left;
            if (current->left)
            {
                while (mostRight && mostRight->right && mostRight->right != current)
                {
                    mostRight = mostRight->right;
                }
                
                if (mostRight && mostRight->right == NULL)
                {
                    mostRight->right = current;
                    current = current->left;
                    continue;
                }
                else
                {
                    mostRight->right = NULL;
                }
            }
            
            if (last && last->val > current->val)
            {
                if (beg == NULL)
                {
                    beg = last;
                    end = current;
                }
                else
                {
                    end = current;
                }
            }
            else
            {
                last = current;
            }
            current = current->right;
        }
        
        int tmp = beg->val;
        beg->val = end->val;
        end->val = tmp;
    }
};

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
 
 // O(1) space complexity & no recursion
class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (root == NULL)
        {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        else
        {
            TreeNode* curNode = root;
            while (true)
            {
                if (val > curNode->val)
                {
                    if (curNode->right == nullptr)
                    {
                        curNode->right = new TreeNode(val);
                        break;
                    }
                    curNode = curNode->right;
                }
                else
                {
                    if (curNode->left == nullptr)
                    {
                        curNode->left = new TreeNode(val);
                        break;
                    }
                    curNode = curNode->left;
                }
            }
        }

        return root;
    }
};

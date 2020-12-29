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
    void check(TreeNode* node, int& bitarray, int& result)
    {
        if (node)
        {
            bitarray ^= (1 << node->val);
            if (node->left == nullptr && node->right == nullptr)
            {
                int ones = 0;
                int c = 1;
                while (c <= 9)
                {
                    if ((bitarray & (1 << c)) != 0)
                    {
                        ones++;
                    }
                    c++;
                }
                
                if (ones < 2)
                {
                    result += 1;
                }
            }
            else
            {
                check(node->left, bitarray, result);
                check(node->right, bitarray, result);
            }
            
            bitarray ^= (1 << node->val);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int bitarray = 0;
        int result = 0;
        
        check(root, bitarray, result);
        
        return result;
    }
};

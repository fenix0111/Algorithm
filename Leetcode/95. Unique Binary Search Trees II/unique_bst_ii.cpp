// Leetcode 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/
// time complexity: O(n! * log(n))
// space complexity: O(n * n)

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
 
 // slow 
class Solution 
{
public:
    TreeNode* makeTree(vector<int>& num)
    {
        TreeNode* root = new TreeNode(num[0]);
        int i = 1;
        while (i < num.size())
        {
            int n = num[i];
            TreeNode* node = new TreeNode(n);
            TreeNode* pRoot = root;
            while (pRoot && ( (n < pRoot->val && pRoot->left) || (n > pRoot->val && pRoot->right) ) )
            {
                if (n < pRoot->val)
                {
                    pRoot = pRoot->left;
                }
                else
                {
                    pRoot = pRoot->right;
                }
            }
            
            if (n < pRoot->val)
            {
                pRoot->left = node;
            }
            else
            {
                pRoot->right = node;
            }
            i++;
        }
        
        return root;
    }
    
    bool isNewTree(unordered_set<int>& generated, TreeNode* root)
    {
        int num = 0;
        queue<TreeNode*> q;
        q.push(root);
    
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            num = num * 10 + node->val;
            if (node->left)
            {
                q.push(node->left);
            }
            
            if (node->right)
            {
                q.push(node->right);
            }
        }
        
        if (generated.find(num) == generated.end())
        {
            generated.insert(num);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> ret;
        if (n == 0)
            return ret;
        
        vector<int> num;
        unordered_set<int> generated;
        for (int i = 1; i <= n; i++)
        {
            num.push_back(i);
        }
        
        do
        {
            TreeNode* root = makeTree(num);
            if (isNewTree(generated, root))
            {
                ret.push_back(makeTree(num));
            }
            
        } while (next_permutation(num.begin(), num.end()));
        
        return ret;
    }
};

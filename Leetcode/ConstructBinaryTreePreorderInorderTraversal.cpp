// Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Runtime: 16 ms

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 不太美观。。
// 主要思路: 先序遍历里第一个元素是根结点，根据这个根结点在中序遍历里找到根结点位置。
// 这样在中序遍历里根结点前面部分是根结点左子树而后面部分就是右子树了。
// 之后递归处理即可。
class Solution {
public:
    TreeNode* btRecur(vector<int>& preorder, vector<int>& inorder, int pb, int pe, int ib, int ie)
    {
        if (pb > pe)
            return NULL;
    
        if (ib > ie)
            return NULL;
    
        int rt = 0;
        for (int i = ib; i <= ie; i++)
        {
            if (inorder[i] == preorder[pb])
            {
                rt = i;
                break;
            }
        }
    
        int ileftl = ib;
        int ileftr = rt - 1;
        int irightl = rt + 1;
        int irightr = ie;
    
        int pleftl = pb + 1;
        int pleftr = pb + rt - ib;
        int prightl = pleftr + 1;
        int prightr = pe;
    
        TreeNode *tree = (TreeNode*)malloc(sizeof(TreeNode));
        tree->val = inorder[rt];
        tree->left = btRecur(preorder, inorder, pleftl, pleftr, ileftl, ileftr);
        tree->right = btRecur(preorder, inorder, prightl, prightr, irightl, irightr);
    
        return tree;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return btRecur(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
};

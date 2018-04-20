// Leetcode 116. Populating Next Right Pointers in Each Node
// Runtime: 20ms
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 // 关键是如何判断树的一个层的结束。这里用了NULL为了标志。
 // 另外本题一个前提是“数是完全二叉树”，所以也可以取巧用2的幂去算一个层的结束。
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == NULL)
        {
            return;
        }
        
        if (root->left == NULL && root->right == NULL)
        {
            root->next = NULL;
            return;
        }

        list<TreeLinkNode*> bf;
        bf.push_back(root);
        bf.push_back(NULL);

        while (!bf.empty())
        {
            TreeLinkNode *node = bf.front();
            bf.pop_front();
            if (node != NULL)
            {
                bf.push_back(node->left);
                bf.push_back(node->right);
                node->next = bf.front();
                
                if (bf.front() == NULL)
                {
                    bf.push_back(NULL);
                }
            }
        }
    }
};

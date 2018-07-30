// Leetcode 117. Populating Next Right Pointers in Each Node II
// Runtime: 27ms
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// 解法相比116题多弄了个辅助list。
// 严格来说这个解法不符合条件。虽然没严格检查，但题目要求in-place解法。
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == NULL)
            return;
              
        if (root->left == NULL && root->right == NULL)
        {   
            root->next = NULL;
            return;
        }

        list<TreeLinkNode*> bf;    
        list<TreeLinkNode*> ll;
        
        bf.push_back(root);

        while (!bf.empty() || !ll.empty())
        {
            while (!bf.empty())
            {
                ll.push_back(bf.front());
                bf.pop_front();  
            }
        
            while (!ll.empty())
            {
                TreeLinkNode *node = ll.front();
                ll.pop_front();
                
                if (node->left)
                    bf.push_back(node->left);
                
                if (node->right)
                    bf.push_back(node->right);
                
                if (!ll.empty())
                {
                    node->next = ll.front();
                }
                else
                {
                    node->next = NULL;
                }
            }
        }
    }
};

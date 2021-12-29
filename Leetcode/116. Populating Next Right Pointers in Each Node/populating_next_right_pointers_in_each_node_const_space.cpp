/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// O(1) space solution

// It is stated that the tree is perfect binary tree
// therefore no need to check carefully about if the node has right child or not
// it the node doesn't have left child, then that node is leaf node.
class Solution
{
public:
    Node* connect(Node* root) 
    {
        if (root)
        {
            Node* current = root;
            Node* next = root->left;
            while (current->left)
            {
                current->left->next = current->right;
                
                // jump to the sibling node
                if (current->next)
                {
                    current->right->next = current->next->left;
                    current = current->next;
                }
                else
                {
                    // go down to the next level
                    current = next;
                    next = current->left;
                }
            }
        }    
        
        return root;
    }
};

// Leetcode 589. N-ary Tree Preorder Traversal
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Runtime: 144ms

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// non-recursive solution
class Solution 
{
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> ret;
        if (root)
        {
            deque<Node*> q;
            q.push_back(root);
            while (!q.empty())
            {
                Node *node = q.front();
                ret.push_back(node->val);
                q.pop_front();
                
                for (auto it = (node->children).rbegin(); it != (node->children).rend(); it++)
                {
                    q.push_front(*it);
                }
            }
        }
        
        return ret;
    }
};

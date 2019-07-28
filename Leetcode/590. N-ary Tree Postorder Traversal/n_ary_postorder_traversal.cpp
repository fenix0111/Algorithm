// Leetcode 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Runtime: 152ms

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

class Solution 
{
public:
    vector<int> postorder(Node* root) 
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
                for (auto it = (node->children).begin(); it != (node->children).end(); it++)
                {
                    q.push_front(*it);
                }
            }
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// Leetcode 133. Clone Graph
// https://leetcode.com/problems/clone-graph/
// time complexity: O(V + E)
// space complexity: O(V)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {        
        if (!node)
            return NULL;
        
        Node* newhead = new Node(node->val);
        
        queue<Node*> q;
        queue<Node*> newq;
        q.push(node);
        newq.push(newhead);

        unordered_map<int, Node*> G;
        G[node->val] = newhead;
        
        while (!q.empty())
        {
            Node* n = q.front();
            q.pop();
            
            Node* newNode = newq.front();
            newq.pop();
            
            for (Node* neighbor : n->neighbors)
            {
                if (G.find(neighbor->val) == G.end())
                {
                    Node* newNeighbor = new Node(neighbor->val);
                    (newNode->neighbors).push_back(newNeighbor);

                    newq.push(newNeighbor);
                    q.push(neighbor);
                    
                    G[neighbor->val] = newNeighbor;
                }
                else
                {
                    (newNode->neighbors).push_back(G.find(neighbor->val)->second);
                }
            }
        }
        
        return newhead;
    }
};

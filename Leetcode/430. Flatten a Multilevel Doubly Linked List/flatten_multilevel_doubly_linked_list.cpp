// Leetcode 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// time complexity: O(n)
// space complexity: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        if (!head)
            return NULL;
        
        stack<Node*> st;
        Node* node = head;
        while (node)
        {
            if (node->child)
            {
                st.push(node->next);
                node->next = node->child;
                node->child->prev = node;
                node->child = nullptr;  // have to set child pointer to null
                node = node->next;
                
                continue;
            }
            
            if (node->next == nullptr)
            {
                if (!st.empty())
                {
                    Node* p = st.top();                    
                    if (p)
                    {
                        node->next = p;
                        p->prev = node;
                        node = node->next;
                    }
                    st.pop();
                }
                else
                {
                    break;
                }
                continue;
            }
            
            node = node->next;
        }
        
        return head;
    }
};

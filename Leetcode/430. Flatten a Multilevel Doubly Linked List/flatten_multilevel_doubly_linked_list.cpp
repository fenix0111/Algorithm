// Leetcode 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Runtime: 8ms

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
    Node* helper(Node* head) 
    {
        if (head)
        {
            if (!head->next && !head->child)
            {
                return head;
            }
            
            if (head->child)
            {
                head->child->prev = head;
                
                Node *currentNext = head->next;
                head->next = head->child;
                head->child = NULL;
                
                Node *returnFromChild = helper(head->next);
                if (returnFromChild)
                    returnFromChild->next = currentNext;
                if (currentNext)
                    currentNext->prev = returnFromChild;
                
                return helper(currentNext);
            }
            else
            {
                return helper(head->next);
            }
        }
        else
        {
            return NULL;
        }
    }
    
    Node* flatten(Node* head) 
    {
        if (!head)
            return NULL;
        
        helper(head);
        return head;
    }
};

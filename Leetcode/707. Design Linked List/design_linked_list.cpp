// Leetcode 707. Design Linked List
// https://leetcode.com/problems/design-linked-list/
// Runtime: 68 ms (slow)
// Memory: 16.7 MB

typedef struct LL 
{
    int v;
    LL *next;
    LL (int val)
    {
        v = val;
        next = NULL;
    }
};

class MyLinkedList 
{
    LL *head;
    int sz = 0;
public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        head = new LL(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        LL *h = head->next;
        int c = 0;
        while (h && c < index)
        {
            c++;
            h = h->next;
        }
        
        if (h)
        {
            return h->v;
        }
        else
        {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        LL *h = head;
        LL *newNode = new LL(val);
        newNode->next = h->next;
        h->next = newNode;
        
        sz++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        if (sz == 0)
        {
            LL *h = head;
            h->next = new LL(val);
        }
        else
        {
            LL *h = head;
            while (h->next)
            {
                h = h->next;
            }

            LL *newNode = new LL(val);
            h->next = newNode;
        }
        sz++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index <= sz)
        {
            LL *h = head;
            int c = 0;
            while (h && c < index)
            {
                c++;
                h = h->next;
            }
            
            LL *nextNode = h->next;
            LL *newNode = new LL(val);
            newNode->next = nextNode;
            h->next = newNode;
            
            sz++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (sz == 0)
        {
            return;
        }
        
        if (index < sz)
        {
            LL *follow = head;
            LL *h = head->next;
            int c = 0;
            while (h && c < index)
            {
                follow = follow->next;
                h = h->next;
                c++;
            }
            
            follow->next = h->next;
            delete h;
            sz--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

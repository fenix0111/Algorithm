// Leetcode 641. Design Circular Deque
// https://leetcode.com/problems/design-circular-deque/

// using double linked list
// also could implement using array with two pointers 
typedef struct Node
{
    int val;
    Node* next;
    Node* prev;
    
    Node(int v)
    {
        val = v;
    }
};

class MyCircularDeque
{
    int cap;
    int size;
    Node* head;
    Node* tail;
public:
    MyCircularDeque(int k)
    {
        cap = k;
        size = 0;
    }
    
    bool insertFront(int value)
    {
        if (size == cap)
        {
            return false;
        }
        
        Node* newNode = new Node(value);
        if (size == 0)
        {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            
            head = newNode;
        }
        
        size++;
        
        return true;
    }
    
    bool insertLast(int value)
    {
        if (size == cap)
        {
            return false;
        }
        
        Node* newNode = new Node(value);
        if (size == 0)
        {
            newNode->next = nullptr;
            newNode->prev = tail;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            
            tail = newNode;
        }
        
        size++;
        return true;
    }
    
    bool deleteFront()
    {
        if (size == 0)
        {
            return false;
        }
        
        size--;
        Node* front = head;
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        
        // cause runtime error in leetcode, although it shouldn't be
        // delete front; 
        
        return true;
    }
    
    bool deleteLast()
    {
        if (size == 0)
        {
            return false;
        }
        
        size--;
        Node* last = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        
        delete last;
        
        return true;
    }
    
    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        
        return head->val;
    }
    
    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        
        return tail->val;
    }
    
    bool isEmpty()
    {
        return size == 0;
    }
    
    bool isFull()
    {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
